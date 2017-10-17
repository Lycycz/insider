#include "../include/param.h"
#include "../include/Net.h"
#include "../include/Decoder.h"
#include "assert.h"
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dlfcn.h>
#include <time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <math.h>
#include <netdb.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>  
#include <string.h>

//#define KDK_DEBUG
#define ServerPort 6000						//服务器端口号
#define ListenPort 6000						//本机侦听端口
#define MAXLINE 128

char *userNmae;								//系统用户名，从配置接口中读取
char *userPWD;								//系统登录口令，从配置接口中读取
char machine[32]; 							//系统设备编码，从配置接口中读取
char *appCode = "KDK_P2P_INSIDER_HUANGHE_";	//固定24bytes文字
char *runtimeCode;							//本机的运行码
/*********** 系统运行变量 ************/
int insiderSocket;							//系统 UDP sockect
static int gcount = 0;						//当前链接数量???????????????????????????????????????????
unsigned char	frameIdx = 0;				//当前发送的帧序号（0..255循环使用）

struct sockaddr_in serverAddr;				//服务器通讯地址信息
struct sockaddr_in insiderAddr;				//自身听口

pthread_mutex_t mutex;

//客户端缓存信息
typedef struct clientInfo {
	char kind;				//CMD_Kind(Media/Picture)
	char runCode[32];		//Client runtimeCode
	struct sockaddr addr; 	//Client_Addr			
};

struct clientInfo *clientList;				//多有客户端缓存信息
int *clientCount;							//客户缓存数量（最大值为5）
int *sysFlag;								//运行标记（1为运行状态，-1为停止状态）
//BYTE *mediaData[3];							//流媒体数据
//int *mediaSize[3];							//流媒体数据长度
//int *mediaIdx;								//当前正在存储的媒体序号
BYTE *mediaData;							//流媒体数据
//添加一个客户端信息
void addClient(char kind, char *runCode, struct sockaddr *addr)
{
	int idx = *clientCount;
	if (idx < 5)
	{
		clientList[idx].kind = kind;
		memcpy(clientList[idx].runCode, runCode, 32);
		memcpy(&clientList[idx].addr, addr, sizeof(struct sockaddr));
		*clientCount = idx + 1;
	}
}
//根据运行码得到在用户列表中的位置
int indexClient(char *runCode)
{
	printf("indexClient ->enter\n");
	int i;
	for (i = 0; i < *clientCount; i++)
	{
		if (strncmp(clientList[i].runCode, runCode, 32) == 0) return i;
	}
	printf("indexClient ->success\n");
	return -1;
}
//根据序号删除一个客户信息
void deleteClient(int index)
{
	printf("Delete a client at %d\n", index);
	if (index < 0 || index >= *clientCount) return;
	int i;
	for (i = index; i < *clientCount - 1; i++)
	{
		clientList[i].kind = clientList[i+1].kind;
		memcpy(&clientList[i].runCode, &clientList[i + 1].runCode, 32);
		memcpy(&clientList[i].addr, &clientList[i + 1].addr, sizeof(struct sockaddr));
	}
	*clientCount = *clientCount - 1;
	printf("Delete a client at %d\n", index);
}
//根据运行码删除一个客户信息
void deleteClientByCode(char *runCode)
{
	int idx = indexClient(runCode);
	printf("idx:%d\n", idx);
	if (idx >= 0) {
		return deleteClient(idx);
	}
	printf("deleteClientByCode\n");
}

/*********** 心跳函数 ************/
int heartbeatIdx = -1;						//心跳函数心跳项目指针（-1：时间同步，其他为用户状态同步）
//心跳之登录函数 USRLGN-AppCode-UserName-','-Password-','-MatchingCode
void insiderHeartbeat_Login()
{
	#ifdef KDK_DEBUG
	printf("insiderHeartbeat_Login => %s\n",runtimeCode);
	#endif
	char machineCode[32];
	memset(machineCode, '0', 32);
	memcpy(machineCode, machine, strlen(machine) > 32 ? 32 : strlen(machine));	//获取有效的设备编码信息（保证32bytes，不足处补'0'）
	// USRLGN-AppCode-UserName-','-Password-','-MatchingCode size=6+24+20+1+20+1+32=104
	char buff[104];
	memcpy(buff, "USRLGN", 6);
	memcpy(&buff[6], appCode, 24);
	memcpy(&buff[30], userNmae, strlen(userNmae));
	int Idx = 30 + strlen(userNmae);
	memcpy(&buff[Idx], ",", 1); Idx++;
	memcpy(&buff[Idx], userPWD, strlen(userPWD)); Idx += strlen(userPWD);
	memcpy(&buff[Idx], ",", 1); Idx++;
	memcpy(&buff[Idx], machineCode, 32);
	int i = sendto(insiderSocket, buff, Idx + 32, 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	#ifdef KDK_DEBUG
	printf("SEND USRLGN buff=%s\n",buff);
	#endif
}
//心跳之时间同步 SYNTIM-RuntimeCode-DateTime
void insiderHeartbeat_SynTime()
{
	//insiderSocket = socket(AF_INET, SOCK_STREAM, 0);
	//printf("insiderHeartbeat_SynTime => %s\n",runtimeCode);
	time_t timer = time(NULL);
	//SYNTIM-RuntimeCode-DateTime size=6+32+8=46
	char buff[46];
	memcpy(buff, "SYNTIM", 6);
	memcpy(&buff[6], runtimeCode, 32);
	memcpy(&buff[38], &timer, 8);
	int i = sendto(insiderSocket, buff, 46, 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	#ifdef KDK_DEBUG
	printf("SEND SYNTIM buff=%s\n",buff);
	#endif
}
//心跳之客户端状态同步 GETRTC-RuntimeCode1-RuntimeCode2
void insiderHeartbeat_SynRtc(int idx)
{
	//GETRTC-RuntimeCode1-RuntimeCode2 size=6+32+32=70
	char buff[70];
	memcpy(buff, "GETRTC", 6);
	memcpy(&buff[6], runtimeCode, 32);
	memcpy(&buff[38], clientList[idx].runCode, 32);
	sendto(insiderSocket, buff, 70, 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
#ifdef KDK_DEBUG
	printf("SEND GETRTC => %s\n", runtimeCode);
#endif
}
//心跳处理进程
void insiderHeartbeat()
{
	while (*sysFlag)
	{
		if (runtimeCode[0] == 0x00 || runtimeCode[0] == '0')
			insiderHeartbeat_Login();
		else
		{
			printf("heartbeatIdx:%d,clientCount:%d\n", heartbeatIdx, *clientCount);
			switch (heartbeatIdx)
			{
			case -1:
				insiderHeartbeat_SynTime();
				break;
			default:
				if (heartbeatIdx < *clientCount)
					insiderHeartbeat_SynRtc(heartbeatIdx);
			}
			heartbeatIdx++;
			if (heartbeatIdx >= *clientCount)
				heartbeatIdx = -1;
		}
		sleep(3);
	}
	printf("Heartbeat is overed.\n");
}

//登录结果回复，如果成功，服务器返回 runtimeCode，如果下线则从用户列表中删除，USRLGN-Result[-RuntimeCode-AppCode-UserName]
void rcvUSRLGN(char *buff)
{
	//USRLGN-SUCCES-RuntimeCode-AppCode-UserName
	//USRLGN-FAILED[-AppCode-UserName]
#ifdef KDK_DEBUG
	printf("RECEIVE USRLGN => %s\n", buff);
#endif
	if (strncmp(&buff[6], "FAILED", 6) == 0)
		memset(runtimeCode, 0, 32);
	else if (strncmp(&buff[6], "SUCCES", 6) == 0)
	{
		memcpy(runtimeCode, &buff[12], 32);
	    printf("runtimeCode = %s\n", runtimeCode);
	}
}
//时间同步回复，如果时差过大，则返回 UPDATE-DateTime
void rcvSYNTIM(char *buff)
{
	//SYNTIM-Result[-Date-Time]
	//SYNTIM-NOLOGN
	//SYNTIM-SUCCES
	//SYNTIM-FAILED
	//SYNTIM-UPDATE-DateTime
#ifdef KDK_DEBUG
	printf("RECEIVE SYNTIM => %s\n", buff);
#endif
	if (strncmp(&buff[6], "NOLOGN", 6) == 0)
		memset(runtimeCode, 0, 32);
	else if (strncmp(&buff[6], "SUCCES", 6) == 0)
		return;
	else if (strncmp(&buff[6], "FAILED", 6) == 0)
		return;
	else if (strncmp(&buff[6], "UPDATE", 6) == 0)
	{
		long long timer;
		memcpy(&timer, &buff[12], 8);
		time_t t = timer;
		struct timeval t_timeval;
		//struct tm *p;
		//p=localtime(&t);
		t_timeval.tv_sec = t;
		t_timeval.tv_usec = 0;
		if (settimeofday(&t_timeval, NULL) < 0)
		{
			printf("Set system datatime error!\n");
		}
		printf("UPDATE,timet=%x size=%d\n",t,sizeof(t));
		//更新本地机器时间
	}
}
//用户状态回复，如果对方已经下线则从用户列表中剔除该用户
void rcvGETRTC(char *buff)
{
	//GETRTC-Result[-RuntimeCode-sockaddr]
	//GETRTC-NOLOGN
	//GETRTC-ONLINE-RuntimeCode-sockaddr
	//GETRTC-OFFLIN-RuntimeCode
#ifdef KDK_DEBUG
	printf("RECEIVE GETRTC => %s\n", buff);
#endif
	if (strncmp(&buff[6], "NOLOGN", 6) == 0)
		memset(runtimeCode, 0, 32);
	else if (strncmp(&buff[6], "OFFLIN", 6) == 0)
		deleteClientByCode(&buff[12]);
	else if (strncmp(&buff[6], "ONLINE", 6) == 0)
	{
		int idx = indexClient(&buff[12]);
		if (idx >= 0)
		{
			memcpy(&clientList[idx].addr, &buff[44], 16);
		}
	}
}
//接收到用户获取连续画面请求
void rcvGETFRM(char *buff, struct sockaddr *addr)
{
	//GETFRM-RuntimeCode1-RuntimeCode2
#ifdef KDK_DEBUG
	printf("RECEIVE GETFRM => %s\n", buff);
#endif
	if (strncmp(runtimeCode, &buff[38], 32) != 0) return;
	int idx = indexClient(&buff[6]);
	if (idx >= 0)
		clientList[idx].kind = 'M';
	else
		addClient('M', &buff[6], addr);
}
//接收到用户停止获取连续画面请求
void rcvSTPFRM(char *buff)
{
	//STPFRM-RuntimeCode
#ifdef KDK_DEBUG
	printf("RECEIVE STPFRM => %s\n", buff);
#endif
	deleteClientByCode(&buff[6]);
}
//接收到用户停止获取连续画面请求
void rcvGETPIC(char *buff, struct sockaddr *addr)
{
	//GETPIC-RuntimeCode1-RuntimeCode2
#ifdef KDK_DEBUG
	printf("RECEIVE GETPIC => %s\n", buff);
#endif
	if (strncmp(runtimeCode, &buff[38], 32) != 0) return;
	int idx = indexClient(&buff[6]);
	if (idx >= 0)
		clientList[idx].kind = 'P';
	else
		addClient('P', &buff[6], addr);
}
//接收到用户PTZ控制命令请求
void rcvSETPTZ(char *buff)
{
	//SETPTZ-RuntimeCode1-RuntimeCode2-PTZ-Param
#ifdef KDK_DEBUG
	printf("RECEIVE SETPTZ => %s\n", buff);
#endif
	if (strncmp(runtimeCode, &buff[38], 32) != 0) return;
	int cmd = buff[70];
	switch (cmd)
	{
	case 1:	//	1	向前移动	速度，延时	以多快的速度移动云台多长时间
		break;
	case 2:	//	2	向后移动	速度，延时	以多快的速度移动云台多长时间
		break;
	case 3:	//	3	顺时针移动	速度，延时	以多快的速度移动云台多长时间
		break;
	case 4:	//	4	逆时针移动	速度，延时	以多快的速度移动云台多长时间
		break;
	case 5:	//	5	1、3组合	移动速度，旋转速度，延时
		break;
	case 6:	//	6	1、4组合	移动速度，旋转速度，延时
		break;
	case 7:	//	7	2、3组合	移动速度，旋转速度，延时
		break;
	case 8:	//	8	2、4组合	移动速度，旋转速度，延时
		break;
	case 9:	//	9	打开夜视	0：关闭，1：打开
		break;
	case 10://	10	推 - 聚焦	速度，延时
		break;
	case 11://	11	拉 - 聚焦	速度，延时
		break;
	}
}
//接收穿透命令请求
void rcvCNTUSR(char *buff)
{
	//CNTUSR-sockaddr_in -> LNKUSR-Runtimecode
#ifdef KDK_DEBUG
	printf("RECEIVE CNTUSR => %s\n", buff);
#endif	
	struct sockaddr_in clientAddr;				//服务器通讯地址信息	
	char sendbuff[38];
	memcpy(sendbuff, "LNKUSR", 6);;
	memcpy(&sendbuff[6], runtimeCode, 32);
	memcpy(&clientAddr, &buff[6], 16);
	//sendto(insiderSocket, sendbuff, sizeof(sendbuff), 0, (struct sockaddr*)&clientAddr, sizeof(clientAddr));
	if (sendto(insiderSocket, sendbuff, sizeof(sendbuff), 0, (struct sockaddr*)&clientAddr, sizeof(clientAddr)) < 0)
	printf("SEND LNKUSR --> send error\n");
}
//接收目标客户穿透命令
void rcvLNKUSR(char* buff)
{
	// LNKUSR-Runtimecode
	printf("RECEIVE LNKUSR => P2P success\n");
}
//侦听处理进程
void insiderListener()
{
	struct timeval timeout = { 3, 0 };	//设定接收超时时间值 3s
	int ret = setsockopt(insiderSocket, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));
	char *buff = (char*)malloc(MAXLINE * sizeof(char));
	while (*sysFlag) {
		//printf("pid2:");
		struct sockaddr_in rcvAddr; 			//Client_Addr
		int rcvAddSize = sizeof(rcvAddr);	//Client_AddSize
		int recvd = recvfrom(insiderSocket, buff, MAXLINE, 0, (struct sockaddr_in *)&rcvAddr, &rcvAddSize);
		//printf("%s\n", buff);
#ifdef KDK_DEBUG
		printf("Received a message => %s\n", buff);
#endif
		if (recvd > 6)
		{
			//printf("size=%d|",recvd);
			if (strncmp(buff, "USRLGN", 6) == 0) rcvUSRLGN(buff);		//登录结果回复
			else if (strncmp(buff, "SYNTIM", 6) == 0) rcvSYNTIM(buff);	//时间同步回复
			else if (strncmp(buff, "GETRTC", 6) == 0) rcvGETRTC(buff);	//用户状态回复
			else if (strncmp(buff, "GETFRM", 6) == 0) rcvGETFRM(buff, &rcvAddr);	//接收到用户获取连续画面请求
			else if (strncmp(buff, "STPFRM", 6) == 0) rcvSTPFRM(buff);	//接收到用户停止获取连续画面请求
			else if (strncmp(buff, "GETPIC", 6) == 0) rcvGETPIC(buff, &rcvAddr);	//接收到用户获取连续画面请求
			else if (strncmp(buff, "SETPTZ", 6) == 0) rcvSETPTZ(buff);	//接收到用户PTZ控制命令请求
			else if (strncmp(buff, "CNTUSR", 6) == 0) rcvCNTUSR(buff);	//服务器收到穿透命令后转发过来新的穿透命令
			else if (strncmp(buff, "LNKUSR", 6) == 0) rcvLNKUSR(buff);	//接收目标客户穿透命令
			else printf("Received a unkonw message. %s\n", buff);
		}

	}
	free(buff);
}
// --------------------------- 摄像设备接口程序
INT  LogonNotifyCallback(UINT dwMsgID, UINT ip, UINT port, HANDLE hNotify, void *pPar)
{
	printf("LogonNotifyCallback \n");
	return 0;
}
INT  CheckUserPswCallback(const CHAR *pUserName, const CHAR *pPsw)
{
	printf("Check user :%s ,psw:%s \n", pUserName, pPsw);
	return 3;
}
INT	 UpdateFileCallback(INT nOperation, INT hsock, ULONG ip, ULONG port, INT nUpdateType, CHAR *pFileName, CHAR *pFileData, INT nFileLen)
{
	printf("UpdateFileCallback\n");
	return 0;
}
INT  PreviewStreamCallback(HANDLE hOpenChannel, void *pStreamData, UINT dwClientID, void *pContext, ENCODE_VIDEO_TYPE encodeVideoType)
{
	printf("PreviewStreamCallback\n");
	return 0;
}
INT  StreamWriteCheckCallback(INT nOperation, const CHAR *pUserName, const CHAR *pPsw, ULONG ip, ULONG port, OPEN_VIEWPUSH_INFO viewPushInfo, HANDLE hOpen)
{
	//printf("StreamWriteCheckCallback\n");
	return 0;
}
INT  ServerMsgCmdCallback(ULONG ip, ULONG port, CHAR *pMsgHd)
{
	printf("ServerMsgCmdCallback\n");
	return 0;
}

INT myCallbackServerFind(SEARCH_SER_INFO *pSearchInfo)
{
	gcount++;
	printf("***********************gcount %d\n", gcount);
	printf("ServerFindCallback ip: %d.%d.%d.%d, %s \n", (pSearchInfo->ipLocal & 0xff000000) >> 6, (pSearchInfo->ipLocal & 0xff0000) >> 4,
		(pSearchInfo->ipLocal & 0xff00) >> 2, (pSearchInfo->ipLocal & 0xff),
		pSearchInfo->szDeviceName);
	return 0;
}

int myTalkStreamCallback(void *pTalkData, UINT nTalkDataLen, void *pContext)
{
	printf("Get audio data size: %d\n", nTalkDataLen);
	return 0;
}

#define MIN_BUFFERSIZE 1011
//帧发送进程
void insiderSender(void *arg)
{
	int dataSize = *(int*)arg;
#ifdef KDK_DEBUG
	printf("-- Frame %d --", dataSize);
#endif
	int buffsize = ((dataSize / 30) > MIN_BUFFERSIZE ? (dataSize / 30) : MIN_BUFFERSIZE);
	int sendCount = dataSize / buffsize + 1;
	char *sendBuff = (char*)malloc(buffsize + 13);
	frameIdx++;

	struct timeval tv1;
	struct timeval tv2;
	int cost;
	gettimeofday(&tv1, NULL);	//得到当前系统时间
	int idx = 0;
	int position = 0;
	while (position < dataSize)
	{
		int bufLen = (dataSize - position) > buffsize ? buffsize : dataSize - position;
		memcpy(sendBuff, "GETFRM", 6);
		memcpy(&sendBuff[6], &frameIdx, 1);
		memcpy(&sendBuff[7], &position, 3);
		memcpy(&sendBuff[10], &dataSize, 3);
		memcpy(&sendBuff[13], &mediaData[position], bufLen);
		int i;
		for (i = 0; i < *clientCount; i++) {
			if (clientList[i].kind = 'M')
			{
				sendto(insiderSocket, sendBuff, bufLen + 13, 0, (struct sockaddr*)&clientList[i].addr, sizeof(struct sockaddr));
				//printf("SEND Frame %ld/%ld bytes on %ld ---->", sendBuff, mediaSize, tv1.tv_usec);
			}
		}
		gettimeofday(&tv2, NULL);
		cost = ++idx * (30000 / sendCount) - (1000000 - tv1.tv_usec + tv2.tv_usec) % 1000000;
#ifdef KDK_DEBUG
		printf("%d ", cost);
#endif
		if (cost > 0)
			usleep(cost);
		position += bufLen;
	}
	memcpy(sendBuff, "ENDFRM", 6);
	memcpy(&sendBuff[6], &frameIdx, 1);
	int i;
	for (i = 0; i < *clientCount; i++) {
		if (clientList[i].kind = 'M')
		{
			sendto(insiderSocket, sendBuff, 7, 0, (struct sockaddr*)&clientList[i].addr, sizeof(struct sockaddr));
		}
	}
#ifdef KDK_DEBUG
	printf("SEND Frame over on %d\n", tv2.tv_usec);
#endif
	free(sendBuff);
	free(mediaData);
	return;
}
//视频回调函数
int insiderCallBack(HANDLE hOpenChannel, void *pStreamData, UINT dwClientID, void *pContext, ENCODE_VIDEO_TYPE encodeVideoType, ULONG frameno)
{
	FRAME_HEAD	*pFrameHead = (FRAME_HEAD *)pStreamData;
	EXT_FRAME_HEAD *exfream = (EXT_FRAME_HEAD *)(pStreamData + sizeof(FRAME_HEAD));
	if (FRAME_FLAG_A == pFrameHead->streamFlag)
	{
		pthread_mutex_unlock(&mutex);
		return -1;
	}
	int mediaSize;							//流媒体数据长度
	mediaSize = pFrameHead->nByteNum + sizeof(FRAME_HEAD);//流媒体数据长度
	mediaData = (BYTE*)malloc(mediaSize);
	memcpy(mediaData, pStreamData, mediaSize);

	//printf("Receive a frame %d bytes\n", mediaSize);

	struct timeval tv1;
	gettimeofday(&tv1, NULL);	//得到当前系统时间
#ifdef KDK_DEBUG
	printf("Receiver a frame %d on %d", mediaSize, tv1.tv_usec);
#endif
	pthread_t hreadid;
	int ret;
	ret = pthread_create(&hreadid, NULL, (void *)insiderSender, &mediaSize);
	if (ret != 0) {
		printf("Create pthread error!\n");
		exit(1);
	}
	pthread_join(hreadid, NULL);
	//insiderSender(&mediaSize);
}

//抓拍回调函数
/*
int CapturePictureCallback(HANDLE hPictureChn, void *pPicData, int nPicLen, DWORD dwClientID, void *pContext)
{
	struct sockaddr_in address;
	int buffsize = nPicLen / 39 + 14;
	char*sendBuff = (char*)malloc(buffsize);
	int position = 0;
	int dataSize = nPicLen;
	unsigned char		frameIdx = 0;
	while (position<dataSize)
	{
		int bufLen = (dataSize - position) > buffsize - 13 ? buffsize - 13 : dataSize - position;
		memcpy(sendBuff, "GETPIC", 6);
		memcpy(&sendBuff[6], &frameIdx, 1);
		memcpy(&sendBuff[7], &position, 3);
		memcpy(&sendBuff[10], &dataSize, 3);
		memcpy(&sendBuff[13], &pPicData[position], bufLen);
		int i;
		for (i = 0; i < *clientCount; i++) {
			bzero(&address, sizeof(address));
			memcpy(&address,&clientList[i].addr,sizeof(struct sockaddr));
			if (clientList[i].kind = 'P')
				sendto(insiderSocket, sendBuff, bufLen + 12, 0, (struct sockaddr*)&address, sizeof(address));
		}
		usleep(50);
		position += bufLen;
	}
	memcpy(sendBuff, "ENDPIC", 6);
	memcpy(&sendBuff[6], &frameIdx, 1);
	int i;
		bzero(&address, sizeof(address));
			memcpy(&address,&clientList[i].addr,sizeof(struct sockaddr));
		if (clientList[i].kind = 'P')
		{
			sendto(insiderSocket, sendBuff, 7, 0, (struct sockaddr*)&address, sizeof(address));
			deleteClient(i);
		}

	}



	return 0;
}
*/
//嵌入程序主函数
int main()
{
	//share memory
	int shmRTCid;
	if ((shmRTCid = shmget(IPC_PRIVATE, 32, 0666 | IPC_CREAT)) < 0)
	{
		perror("Fail to shmget shmRTCid");
		exit(EXIT_FAILURE);
	}
	runtimeCode = shmat(shmRTCid, 0, 0);
	memset(runtimeCode, '0', 32);
	
	int shmLLSTid;
	if ((shmLLSTid = shmget(IPC_PRIVATE, 5 * sizeof(struct clientInfo), 0666 | IPC_CREAT)) < 0)
	{
		perror("Fail to shmget shmLLSTid");
		exit(EXIT_FAILURE);
	}
	clientList = shmat(shmLLSTid, 0, 0);
	
	int shmCNTid;
	if ((shmCNTid = shmget(IPC_PRIVATE, sizeof(int), 0666 | IPC_CREAT)) < 0)
	{
		perror("Fail to shmget shmCNTid");
		exit(EXIT_FAILURE);
	}
	clientCount = (int*)shmat(shmCNTid, 0, 0);
	*clientCount = 0;
	
	int shmSYSid;
	if ((shmSYSid = shmget(IPC_PRIVATE, sizeof(int), 0666 | IPC_CREAT)) < 0)
	{
		perror("Fail to shmget shmCNTid");
		exit(EXIT_FAILURE);
	}
	sysFlag = (int*)shmat(shmSYSid, 0, 0);
	*sysFlag = 1;
	
	//int shmMediaDataid1;
	//if ((shmMediaDataid1 = shmget(IPC_PRIVATE, 40000, 0666 | IPC_CREAT)) < 0)
	//{
	//	perror("Fail to shmget shmMediaDataid");
	//	exit(EXIT_FAILURE);
	//}
	//mediaData[0] = (BYTE*)shmat(shmMediaDataid1, 0, 0);//流媒体数据
	//int shmMediaDataid2;
	//if ((shmMediaDataid2 = shmget(IPC_PRIVATE, 40000, 0666 | IPC_CREAT)) < 0)
	//{
	//	perror("Fail to shmget shmMediaDataid");
	//	exit(EXIT_FAILURE);
	//}
	//mediaData[1] = (BYTE*)shmat(shmMediaDataid2, 0, 0);//流媒体数据
	//int shmMediaDataid3;
	//if ((shmMediaDataid3 = shmget(IPC_PRIVATE, 40000, 0666 | IPC_CREAT)) < 0)
	//{
	//	perror("Fail to shmget shmMediaDataid");
	//	exit(EXIT_FAILURE);
	//}
	//mediaData[2] = (BYTE*)shmat(shmMediaDataid3, 0, 0);//流媒体数据
	
	//int mediaSizeid;
	//if ((mediaSizeid = shmget(IPC_PRIVATE, sizeof(int), 0666 | IPC_CREAT)) < 0)
	//{
	//	perror("Fail to shmget mediaSizeid");
	//	exit(EXIT_FAILURE);
	//}
	//mediaSize = (int*[3])shmat(mediaSizeid, 0, 0);//流媒体数据长度
	//*mediaSize = 0;

	//int mediaIdxid;
	//if ((mediaIdxid = shmget(IPC_PRIVATE, sizeof(int), 0666 | IPC_CREAT)) < 0)
	//{
	//	perror("Fail to shmget mediaSizeid");
	//	exit(EXIT_FAILURE);
	//}
	//mediaIdx = (int*)shmat(mediaIdxid, 0, 0);//流媒体数据长度
	//*mediaIdx = 0;

	//建立 UDP Socket 连接
	if ((insiderSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		printf("Can not create a socket. \n");
		exit(1);
	}
	insiderAddr.sin_family = AF_INET;
	insiderAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	insiderAddr.sin_port = htonl(ListenPort);
	if (bind(insiderSocket, (struct sockaddr*)(&insiderAddr), sizeof(struct sockaddr)) == -1) {
		printf("Can not init UDP. \n");
		exit(1);
	}
	serverAddr.sin_family = AF_INET;
	//char *ipbuf = (char*)malloc(128);
	//struct hostent *he = gethostbyname("www.jdwxcn.com");
	//memcpy(&serverAddr.sin_addr, he->h_addr, sizeof(struct in_addr));
	//serverAddr.sin_addr.s_addr = inet_addr("192.168.18.6");
	//serverAddr.sin_port = htons(4999);
	//struct in_addr *addr_list = (struct in_addr *)he.h_addr_list;
	//serverAddr.sin_addr.s_addr = addr_list[0].s_addr;
	/*serverAddr.sin_addr.s_b1 = he.h_addr_list[0];
	serverAddr.sin_addr.s_b2 = he.h_addr_list[1];
	serverAddr.sin_addr.s_b3 = he.h_addr_list[2];
	serverAddr.sin_addr.s_b4 = he.h_addr_list[3];*/
	//serverAddr.sin_addr.s_addr = inet_addr("111.161.35.140");
	//serverAddr.sin_port = htons(6000);



	//设定设备回调函数——insiderCallBack

	//	char senderrtc[32];
	//	memcpy(senderrtc, buff[7], 32);
	//	addClient("0", senderrtc, rcvAddr, rcvAddSize);
	//
	char *g_pIPString = "192.168.18.243";
	char *g_pUseName = "admin";
	char *g_pPASSWD = "admin";
	unsigned long	dwTmp;
	long g_lPort = 0;
	unsigned int 	nPort = 5000;
	g_lPort = nPort;
	ERR_CODE		errCode;
	errCode = NET_Startup(5000, LogonNotifyCallback, CheckUserPswCallback, UpdateFileCallback, ServerMsgCmdCallback, StreamWriteCheckCallback, (ChannelStreamCallback)PreviewStreamCallback);
	printf("--->|\tNET_Startup: %s\n", errCode ? "Failed!" : "Successful!");

	HANDLE m_hLogonServer;
	errCode = NET_LogonServer(g_pIPString, g_lPort, "admin", g_pUseName, g_pPASSWD, 0, &m_hLogonServer);
	printf("--->|\tNET_LogonServer: %s\n", errCode ? "Failed!" : "Successful!");

	if (errCode)
	{
		printf("--->|\tNET_LogonServer: %s\n", "Failed!");
		return -1;
	}
	else
	{
		printf("--->|\tNET_LogonServer: %s\n", "Successful!");
	}
	VIDEO_CONFIG_NEW stvideo;
	int ret;
	UINT len = sizeof(VIDEO_CONFIG_NEW);
	DWORD append = 0;
	ret = NET_GetServerConfig(m_hLogonServer, CMD_GET_VIDEO_CONFIG_NEW, (char *)&stvideo, &len, &append);

	printf("ret = %d, brightness = %d, contrast = %d\n", ret, stvideo.Brightness, stvideo.Contrast);


#if 1

	//get all param
	DVS_Parameter_New stparam;
	/*UINT */len = sizeof(DVS_Parameter_New);
	/*DWORD*/ append = 0;

	ret = NET_GetServerConfig(m_hLogonServer, CMD_GET_ALL_CONFIGPARAM, (char *)&stparam, &len, &append);
	printf("ret = %d, IPADDR = %x, sysName = %s, title = %s, username = %s, passwork = %s\n",
		ret, stparam.sysNet.IPAddr, stparam.sysName, stparam.sysVideo[0].Title, stparam.sysUser[1].Name, stparam.sysUser[1].Password);
	char machinetest[32];
	sprintf(machinetest,"%032d",stparam.sysID);
	strncpy(machine,machinetest,32);
	printf("machine=%s\n",machine);

	VIDEOMOTION_CONFIG_NEW stmotion;
	len = sizeof(VIDEOMOTION_CONFIG_NEW);
	append = 0;
	ret = NET_GetServerConfig(m_hLogonServer, CMD_GET_VMOTION_CONFIG_NEW, (char *)&stmotion, &len, &append);

	printf("ret = %d, h = %d, w = %d, open = %d\n", ret, stmotion.DetectArea[0].H, stmotion.DetectArea[0].W, stmotion.DetectOpen);

	stmotion.DetectOpen = 1;
	stmotion.DetectLevel = 4;
	stmotion.DetectArea[0].H = 100;
	stmotion.DetectArea[0].Y = 100;
	stmotion.DetectArea[0].X = 120;
	stmotion.DetectArea[0].W = 100;
	ret = NET_SetServerConfig(m_hLogonServer, CMD_SET_VMOTION_CONFIG_NEW, (char *)&stmotion, len, append);

	PACKED4 USER_DETAIL user;
	len = sizeof(PACKED4 USER_DETAIL);
	append = 0;
	ret = NET_GetServerConfig(m_hLogonServer, CMD_GET_USER_CONFIG, (char *)&user, &len, &append);
	//printf("blong=%d,Name=%s,password=%s\n",user.bLogon,user.Name,user.Password);

	NET_CONFIG netconfig;
	len = sizeof(NET_CONFIG);
	append = 0;
	ret = NET_GetServerConfig(m_hLogonServer, CMD_GET_NET_CONFIG, (char *)&netconfig, &len, &append);
	/*char szIP[16] = { 0 };
	char szIP2[16] = { 0 };
	unsigned char *c = (unsigned char *)&netconfig.IPAddr;
	unsigned char *b = (unsigned char *)&netconfig.DNSHostIP;
	//snprintf(szIP, sizeof(szIP), "%hhu.%hhu.%hhu.%hhu", *c, *(c + 1), *(c + 2), *(c + 3));
	snprintf(szIP, sizeof(szIP), "%hhu.%hhu.%hhu.%hhu", *(c + 3), *(c + 2), *(c + 1), *c);
	snprintf(szIP2, sizeof(szIP), "%hhu.%hhu.%hhu.%hhu", *(b + 3), *(b + 2), *(b + 1), *b);
	printf("IPADdr=%s,DdnsIP=%s\n", szIP, szIP2);*/
	userNmae=netconfig.DdnsName;
	userPWD=netconfig.DdnsPass;

	struct hostent *he = gethostbyname(netconfig.DdnsIP);
	memcpy(&serverAddr.sin_addr, he->h_addr, sizeof(struct in_addr));
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port = htons(netconfig.DdnsPortNo);
	
	//serverAddr.sin_port = htons(4999);
	//serverAddr.sin_addr.s_addr=inet_addr("192.168.18.22");
	printf("port=%d\n",netconfig.DdnsPortNo);
	printf("userName=%s,userPWd=%s\n",userNmae,userPWD);
	printf("ddns=%s\n",netconfig.DdnsIP);
	char szIP[16] = { 0 };
	unsigned char *c = (unsigned char *)&serverAddr.sin_addr;
	snprintf(szIP, sizeof(szIP), "%hhu.%hhu.%hhu.%hhu", *(c + 3), *(c + 2), *(c + 1), *c);
	printf("ip=%s\n",szIP);
#endif
	errCode = NET_LogoffServer(m_hLogonServer);
	if (errCode)
	{
		printf("Error code:%d\n", errCode);
		printf("--->|\tNET_LogoffServer: Failed!\n");
		return -1;
	}
	else
	{
		printf("--->|\tNET_LogoffServer: Successful!\n");
	}
	SERVER_INFO			stHHserverInfo;
	//发送帧
	insiderSocket = socket(AF_INET, SOCK_DGRAM, 0);

	memset(&stHHserverInfo, 0, sizeof(SERVER_INFO));
	errCode = NET_LogonServer(g_pIPString, g_lPort, "admin", g_pUseName, g_pPASSWD, 0, &m_hLogonServer);
	printf("--->|\tNET_LogonServer: %s\n", errCode ? "Failed!" : "Successful!");

	HANDLE m_hOpenChannel;
	OPEN_CHANNEL_INFO_EX channelInfo;
	channelInfo.dwClientID = 1;
	channelInfo.nOpenChannel = 0;
	channelInfo.nSubChannel = 1;
	channelInfo.protocolType = (NET_PROTOCOL_TYPE)0;
	channelInfo.funcStreamCallback = (ChannelStreamCallback)insiderCallBack;
	channelInfo.pCallbackContext = 0;
	errCode = NET_OpenChannel(g_pIPString, g_lPort, "admin", g_pUseName, g_pPASSWD, (OPEN_CHANNEL_INFO_EX*)&channelInfo, &m_hOpenChannel);
	printf("--->|\tNET_OpenChannel: %s \n\n", errCode ? "Failed!" : "Successful!");
	errCode = NET_ReadServerInfo(m_hLogonServer, &stHHserverInfo);
	if (ERR_SUCCESS != errCode)
	{
		printf("Get server information failed! Line=%d\n", __LINE__);
		return;
	}

	printf("Start *************************/\n");
   pthread_mutex_init(&mutex,NULL);  
	//启动心跳进程——insiderHeartbeat
	int pid1;
	if ((pid1 = fork()) == 0)
	{
		printf("pid1");
		insiderHeartbeat();
	}
	int pid2;
	//启动侦听进程——insiderListener
	if ((pid2 = fork()) == 0)
	{
		insiderListener();
	}
	//int pid3;
	////启动发送进程——insiderSender
	//if ((pid3 = fork()) == 0)
	//{
	//	insiderSender();
	//}
	getchar();
	*sysFlag = 0;
  pthread_mutex_destroy(&mutex);  
	printf("End of program.\n");
}
