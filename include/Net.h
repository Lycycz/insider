/******************************************************************************
* ϵͳ���ƣ�Net
* �ļ����ƣ�Net.h
* �汾    ��	V2.0.0.0.2
* ˵��	  �����翪�����ӿ�,��SDKΪ�ͱ����������ṩ�ӿ�
			���ļ����������֣�
			һ��ö�����Ͷ��壻
			�����ص�������
			�����ӿڽṹ���Ͷ��壻
			�ġ�����Ƶ����֡ͷ��
			�塢�����ӿڶ��壻
* ����˵��: ��
******************************************************************************/
#ifndef  __NET_H__
#define  __NET_H__

#define PACKED  __attribute__((packed, aligned(1)))
#define PACKED4 __attribute__((packed, aligned(4)))


/*********************************  һ��ö�����Ͷ���  ******************************/

//1��������Ƶ��������������
typedef enum	DVS_MACHINE_TYPE_
{
	NONE = 0xff,
}DVS_MACHINE_TYPE;

//2����Ƶ�����ʽ									
typedef enum  _ENCODE_VIDEO_TYPE
{
	EV_TYPE_NONE		= 0xFFFF,
}ENCODE_VIDEO_TYPE;

//3����������
typedef enum _UPDATE_TYPE
{
	UPDATE_KERNEL,					//�����ں�
	UPDATE_YUNTAI1,				//������̨Э��1
	UPDATE_YUNTAI2,				//������̨Э��2
	UPDATE_YUNTAI3,				//������̨Э��3
	UPDATE_YUNTAI4,				//������̨Э��4
	UPDATE_YUNTAI5,				//������̨Э��5
	UPDATE_YUNTAI6,				//������̨Э��6
	UPDATE_OCX,						//�����ؼ�
	UPDATE_WEBPAGE,				//����ҳ��
	UPDATE_PATHFILE,				//�����ض�Ŀ¼�ļ�
}UPDATE_TYPE;


//5������״̬
typedef enum _CONNECT_STATUS
{
	CONNECT_STATUS_NONE,			//δ����
	CONNECT_STATUS_OK,				//�Ѿ�����
}CONNECT_STATUS;

//6��ת������
typedef enum _RELAY_TYPE
{
	RELAY_LOGON,					//ת����¼����
	RELAY_PREVIEW,					//ת����ƵԤ������
	RELAY_TALK,						//ת���Խ�
	RELAY_AUDIOBRD,				//ת�������㲥
	RELAY_QUERY						//ת���Ĳ�ѯ
}RELAY_TYPE;

//7��֪ͨӦ�ó��򴰿���Ϣ����
typedef enum _MSG_NOTIFY
{

    MSG_CONNECT_CLOSE,             //��¼���ӹر� 
    MSG_CHANNEL_CLOSE,             //ͨ�����ӹر� 
    MSG_TALK_CLOSE,                //�Խ����ӹر� 
    MSG_ALARM_OUTPUT,              //�������                   
    MSG_UPDATE_SEND_PERCENT,       //���������Ͱٷֱ� 
    MSG_UPDATE_SAVE_PERCENT,       //����д�뷢�Ͱٷֱ�
    MSG_VIEWPUSH_CLOSE ,           //��������Ƶ����ر� 
   	MSG_BROADCAST_ADD_FAILURE,     //���������㲥��ʧ�� 
   	MSG_BROADCAST_CLOSE,           //�����㲥��һ���Ͽ� 
   	MSG_SENSOR_CAPTURE,            //̽ͷ������ץ�� 
   	MSG_COM_DATA,                  //���ڲɼ����� 
   	MSG_ALARM_LOST,                //������ʧ                   
    MSG_ALARM_OUTPUT_NEW,          //�������(��)               
    MSG_ALARM_LOST_NEW,            //������ʧ(��)               
    MSG_PICCHN_CLOSE,              //ץ��ͨ�����ӹر� 
}MSG_NOTIFY;


//8��������
typedef enum _ERR_CODE
{
	ERR_SUCCESS,					//�����ɹ�
	ERR_FAILURE,					//����ʧ��
	ERR_REFUSE_REQ,				//���󱻾ܾ�
	ERR_USER_FULL,					//��¼�û�����
	ERR_PREVIEW_FULL,				//Ԥ���û�����
	ERR_TASK_FULL,					//ϵͳ����æ�����᳢������
	ERR_CHANNEL_NOT_EXIST,			//Ҫ�򿪵�ͨ�������ڻ�����
	ERR_DEVICE_NAME,				//�򿪵��豸������
	ERR_IS_TALKING,				//���ڶԽ�
	ERR_QUEUE_FAILUE,				//���г���
	ERR_USER_PASSWORD,				//�û����������ϵͳ��ƥ��
	ERR_SHARE_SOCKET,				//socket ����
	ERR_RELAY_NOT_OPEN,			//ת������ķ���δ��
	ERR_RELAY_MULTI_PORT,			//ת���ಥ�˿ڴ���
	ERR_VIEWPUSH_CHANNEL_USING,	//��Ƶ�����ͨ���Ѿ���ռ��
	ERR_VIEWPUSH_DECODE_TYPE,		//��Ƶ����ͨ���Ľ����ʽ����0ͨ��(4cif,2cif,cif),1ͨ��(2cif,cif),2ͨ��(cif),3ͨ��(cif)
	ERR_AUTO_LINK_FAILURE,			//ת�����Զ�����ʧ��
	ERR_NOT_LOGON,
	ERR_IS_SETTING,
	ERR_COMMAND_FAILURE,
	
	ERR_INVALID_PARAMETER=100,		//���������Ч
	ERR_LOGON_FAILURE,				//��¼ʧ��
	ERR_TIME_OUT,					//������ʱ
	ERR_SOCKET_ERR,				//SOCKET����
	ERR_NOT_LINKSERVER,			//��δ���ӷ�����
	ERR_BUFFER_EXTCEED_LIMIT,		//ʹ�û��峬������	
	ERR_LOW_PRIORITY,				//����Ȩ�޲���
	ERR_BUFFER_SMALL,				//����̫С
	ERR_IS_BUSY,					//ϵͳ������æ
	ERR_UPDATE_FILE,				//�����ļ�����
	ERR_UPDATE_UNMATCH,			//�����ļ��ͻ�����ƥ��
	ERR_PORT_INUSE,				//�˿ڱ�ռ��
	ERR_RELAY_DEVICE_EXIST,		//�豸���Ѿ�����
	ERR_CONNECT_REFUSED,			//����ʱ���ܾ�
	ERR_PROT_NOT_SURPPORT,			//��֧�ָ�Э��

	ERR_FILE_OPEN_ERR,            //���ļ�ʧ��
	ERR_FILE_SEEK_ERR,            //fseekʧ�� 
	ERR_FILE_WRITE_ERR,           //fwriteʧ�� 
	ERR_FILE_READ_ERR,            //freadʧ�� 
	ERR_FILE_CLOSING,             //���ڹر��ļ� 
	
}ERR_CODE;

//9��������������
typedef enum _CMD_NET
{
	//����������
	CMD_GET_ALL_PARAMETER,			//�õ����б���������
	CMD_SET_DEFAULT_PARAMETER,	//�ָ����б�����Ĭ�ϲ���
	CMD_SET_RESTART_DVS,			//����������
	CMD_GET_SYS_CONFIG,			//��ȡϵͳ����
	CMD_SET_SYS_CONFIG,			//����ϵͳ����
	CMD_GET_TIME,					//��ȡ������ʱ��
	CMD_SET_TIME,					//���ñ�����ʱ��
	CMD_GET_AUDIO_CONFIG,			//��ȡ��Ƶ����
	CMD_SET_AUDIO_CONFIG,			//������Ƶ����
	CMD_GET_VIDEO_CONFIG,			//��ȡ��Ƶ����
	CMD_SET_VIDEO_CONFIG,			//������Ƶ����
	CMD_GET_VMOTION_CONFIG,		//��ȡ�ƶ��������
	CMD_SET_VMOTION_CONFIG,		//�����ƶ��������
	CMD_GET_VMASK_CONFIG,			//��ȡͼ����������
	CMD_SET_VMASK_CONFIG,			//����ͼ����������
	CMD_GET_VLOST_CONFIG,			//��ȡ��Ƶ��ʧ����
	CMD_SET_VLOST_CONFIG,			//������Ƶ��ʧ����
	CMD_GET_SENSOR_ALARM,			//��ȡ̽ͷ�����������
	CMD_SET_SENSOR_ALARM,			//����̽ͷ�����������
	CMD_GET_USER_CONFIG,			//��ȡ�û�����
	CMD_SET_USER_CONFIG,			//�����û�����
	CMD_GET_NET_CONFIG,			//��ȡ�������ýṹ
	CMD_SET_NET_CONFIG,			//�����������ýṹ
	CMD_GET_COM_CONFIG,			//��ȡ��������
	CMD_SET_COM_CONFIG,			//���ô�������
	CMD_GET_YUNTAI_CONFIG,			//��ȡ������̨��Ϣ
	CMD_SET_YUNTAI_CONFIG,			//����������̨��Ϣ
	CMD_GET_VIDEO_SIGNAL_CONFIG,	//��ȡ��Ƶ�źŲ��������ȡ�ɫ�ȡ��Աȶȡ����Ͷȣ�
	CMD_SET_VIDEO_SIGNAL_CONFIG,	//������Ƶ�źŲ��������ȡ�ɫ�ȡ��Աȶȡ����Ͷȣ�
	CMD_SET_PAN_CTRL,				//��̨����
	CMD_SET_COMM_SENDDATA,			//͸�����ݴ���
	CMD_SET_COMM_START_GETDATA,	//��ʼ�ɼ�͸������
	CMD_SET_COMM_STOP_GETDATA,	//ֹͣ�ɼ�͸������
	CMD_SET_OUTPUT_CTRL,			//�̵�������
	CMD_SET_PRINT_DEBUG,			//������Ϣ����
	CMD_SET_ALARM_CLEAR,			//�������
	CMD_GET_ALARM_INFO,			//��ȡ����״̬�ͼ̵���״̬
	CMD_SET_TW2824,				//���ö໭��оƬ����(����)
	CMD_SET_SAVE_PARAM,			//���ñ������
	CMD_GET_USERINFO,				//��ȡ��ǰ��½���û���Ϣ
	CMD_GET_DDNS,					//��ȡDDNS
	CMD_SET_DDNS,					//����DDNS
	CMD_GET_CAPTURE_PIC,			//ǰ��ץ��
	CMD_GET_SENSOR_CAP,			//��ȡ����ץ������
	CMD_SET_SENSOR_CAP,			//���ô���ץ������
	CMD_GET_EXTINFO,				//��ȡ��չ����
	CMD_SET_EXTINFO,				//������չ����
	CMD_GET_USERDATA,				//��ȡ�û�����
	CMD_SET_USERDATA,				//�����û�����
	CMD_GET_NTP,					//��ȡNTP����
	CMD_SET_NTP,					//����NTP����
	CMD_GET_UPNP,					//��ȡUPNP����
	CMD_SET_UPNP,					//����UPNP����
	CMD_GET_MAIL,					//��ȡMAIL����
	CMD_SET_MAIL,					//����MAIL����
	CMD_GET_ALARMNAME,				//��ȡ����������
	CMD_SET_ALARMNAME,				//���ñ���������
	CMD_GET_WFNET,					//��ȡ������������
	CMD_SET_WFNET,					//����������������
	CMD_GET_SEND_DEST,				//������Ƶ������Ŀ���
	CMD_SET_SEND_DEST,				//������Ƶ������Ŀ���
	CMD_GET_AUTO_RESET,			//ȡ�ö�ʱ����ע��
	CMD_SET_AUTO_RESET,			//���ö�ʱ����ע��
	CMD_GET_REC_SCHEDULE,			//ȡ��¼�����
	CMD_SET_REC_SCHEDULE,			//����¼�����
	CMD_GET_DISK_INFO,				//ȡ�ô�����Ϣ
	CMD_SET_MANAGE,				//��������Ͳ���
	CMD_GET_CMOS_REG,				//ȡ��CMOS����
	CMD_SET_CMOS_REG,				//����CMOS����
	CMD_SET_SYSTEM_CMD,			//����ִ������
	CMD_SET_KEYFRAME_REQ,         //70.���ùؼ�֡����
    CMD_GET_CONFIGENCPAR,         //71.ȡ����Ƶ����
    CMD_SET_CONFIGENCPAR,         //72.������Ƶ���
    CMD_GET_ALL_PARAMETER_NEW,    //73.��ȡ���в���
    CMD_FING_LOG,                  //74.������־(��ѯ��ʽ:0��ȫ����1�������ͣ�2����ʱ�䣬3����ʱ������� 0xFF-�رձ�������)
    CMD_GET_LOG,                   //75.��ȡ���ҵ�����־ 
    CMD_GET_SUPPORT_AV_FMT,       //76.��ȡ�豸֧�ֵı����ʽ����߼���Ƶ��ʽ
    CMD_GET_VIDEO_CONFIG_NEW,     //77.��ȡ��Ƶ������new
    CMD_SET_VIDEO_CONFIG_NEW,     //78.������Ƶ������new
    CMD_GET_VMOTION_CONFIG_NEW,   //79.��ȡ�ƶ�����������new
    CMD_SET_VMOTION_CONFIG_NEW,   //80.�����ƶ�����������new
    CMD_GET_VLOST_CONFIG_NEW,     //81.��ȡ��Ƶ��ʧ����������new
    CMD_SET_VLOST_CONFIG_NEW,     //82.������Ƶ��ʧ����������new
    CMD_GET_SENSOR_ALARM_NEW,     //83.��ȡ̽ͷ����������new
    CMD_SET_SENSOR_ALARM_NEW,     //84.����̽ͷ����������new
    CMD_GET_NET_ALARM_CONFIG,     //85.��ȡ������ϱ�������
    CMD_SET_NET_ALARM_CONFIG,     //86.����������ϱ�������
    CMD_GET_RECORD_CONFIG,        //87.��ȡ��ʱ¼�����
    CMD_SET_RECORD_CONFIG,        //88.��ʱ¼�����
    CMD_GET_SHOOT_CONFIG,         //89.��ȡ��ʱץ�Ĳ���
    CMD_SET_SHOOT_CONFIG,         //90.���ö�ʱץ�Ĳ���
    CMD_GET_FTP_CONFIG,           //91.��ȡFTP����
    CMD_SET_FTP_CONFIG,           //92.����FTP����
    CMD_GET_RF_ALARM_CONFIG,      //93.��ȡ���߱�������
    CMD_SET_RF_ALARM_CONFIG,      //94.�������߱�������
    CMD_GET_EXT_DATA_CONFIG,      //95.��ȡ������չ����(��ƽ̨������������)
    CMD_SET_EXT_DATA_CONFIG,      //96.����������չ����(��ƽ̨������������)
    CMD_GET_FORMAT_PROCESS,       //97.��ȡӲ�̸�ʽ������
    CMD_GET_PING_CONFIG,          //98.PING ���û�ȡ
    CMD_SET_PING_CONFIG,          //99.PING ��������
	//����������
	DDCMD_GET_ALL_PARAMETER = 100,	//��ȡ��������������
	DDCMD_GET_TIME,				//��ȡϵͳʱ��
	DDCMD_SET_TIME,				//����ϵͳʱ��
	DDCMD_GET_SYS_CONFIG,			//��ȡϵͳ����
	DDCMD_SET_SYS_CONFIG,			//����ϵͳ����
	DDCMD_GET_NET_CONFIG,			//��ȡ��������
	DDCMD_SET_NET_CONFIG,			//������������
	DDCMD_GET_COM_CONFIG,			//��ȡ��������
	DDCMD_SET_COM_CONFIG,			//���ô�������
	DDCMD_GET_VIDEO_CONFIG,		//��ȡ��Ƶ����
	DDCMD_SET_VIDEO_CONFIG,		//������Ƶ����
	DDCMD_GET_ALARM_OPT,			//��ȡ����ѡ��
	DDCMD_SET_ALARM_OPT,			//���ñ���ѡ��
	DDCMD_GET_USER_INFO,			//��ȡ�û�������Ϣ
	DDCMD_SET_USER_INFO,			//�����û�������Ϣ
	DDCMD_GET_ALARM_RECORD,		//��ȡ������¼��Ϣ
	DDCMD_GET_ADRRESS_BOOK,		//��ȡ��ַ������
	DDCMD_SET_ADRRESS_BOOK,		//���õ�ַ������
	DDCMD_SET_COMM,				//���÷��ʹ�������
	DDCMD_SET_CMD,					//����͸��������
	DDCMD_GET_YUNTAI_INFO,			//��ȡ��̨��Ϣ
	DDCMD_GET_YUNTAI_CONFIG,		//��ȡ��̨����
	DDCMD_SET_YUNTAI_CONFIG,		//������̨����
	DDCMD_GET_ONELINK_ADDR,		//��ȡ��������·���ӵ���Ϣ
	DDCMD_SET_ONELINK_ADDR,		//���ý�������·���ӵ���Ϣ
	DDCMD_GET_CYCLELINK_ADDR,		//��ȡ������ѭ�����ӵ���Ϣ
	DDCMD_SET_CYCLELINK_ADDR,		//���ý�����ѭ�����ӵ���Ϣ
	DDCMD_GET_EXTINFO,				//��ȡ��չ����
	DDCMD_SET_EXTINFO,				//������չ����
	DDCMD_GET_NTP,					//��ȡNTP����
	DDCMD_SET_NTP,					//����NTP����
	DDCMD_GET_UPNP,				//��ȡUPNP����
	DDCMD_SET_UPNP,				//����UPNP����
	DDCMD_GET_MAIL,				//��ȡMAIL����
	DDCMD_SET_MAIL,				//����MAIL����
	DDCMD_GET_ALARMNAME,			//��ȡ����������
	DDCMD_SET_ALARMNAME,			//���ñ���������
	DDCMD_GET_WFNET,				//��ȡ������������
	DDCMD_SET_WFNET,				//����������������
	DDCMD_GET_SEND_DEST,			//������Ƶ������Ŀ���
	DDCMD_SET_SEND_DEST,			//������Ƶ������Ŀ���

	CMD_GET_VPN_CONFIG = 200,		//200.��ȡVPN���ò���
	CMD_SET_VPN_CONFIG = 201,		//201.����VPN����
	CMD_GET_3G_CONFIG  = 202,		//��ȡ3G����
	CMD_SET_3G_CONFIG  = 203,      //����3G����
	CMD_GET_GPS_CONFIG = 204,
	CMD_SET_GPS_CONFIG = 205,
	CMD_GET_3G_DIALCTRL= 206,
	CMD_SET_3G_DIALCTRL= 207,	
	
	//������չ===================
	CMD_GET_IR_CONFIG = 400,		//��ȡ������Ϣ����
	CMD_SET_IR_CONFIG,				//���ú�����Ϣ����
	CMD_GET_ALL_CONFIGPARAM,		//��ȡ���в���
	CMD_SET_FORMATTING, 		//��ʽ��

	
	CMD_SET_OSD_MSG = 500,
	CMD_CLEAR_OSD_MSG = 501,
	CMD_SET_OSD_START = 502,
	CMD_SET_OSD_CLOSE = 503,
	CMD_CLEAR_OSD_PTZMSG = 504,
	CMD_SET_OSD_PTZMSG = 505,
	CMD_SET_OSD_PTZORG  = 506,
	CMD_GET_OSD_PTZORG  = 507,

	CMD_GET_VI_SENSOR=1000,
	CMD_SET_VI_SENSOR,
	CMD_GET_VI_SCENE,
	CMD_SET_VI_SCENE,
	CMD_GET_VI_CFG,
	CMD_SET_VI_CFG,
}CMD_NET;

typedef enum _RELAY_CHECK_RET
{
	RCRET_SUCCESS = 0,
	RCRET_FAILURE = -1,
	RCRET_AUTO_LINK = 0x0101,	
}RELAY_CHECK_RET;



/*********************************  �����ص�����  ******************************/

//1��ʵʱ����Ƶ�������ص�
typedef int  ( *ChannelStreamCallback)(HANDLE hOpenChannel,void *pStreamData,UINT dwClientID,void *pContext,ENCODE_VIDEO_TYPE encodeVideoType,ULONG frameno);

//2��ʵʱ�Խ���Ƶ�������ص�
typedef int  ( *TalkStreamCallback)(void *pTalkData,UINT nTalkDataLen,void *pContext);

//3����Ϣ֪ͨ��֪ͨ����
typedef int  ( *MsgNotifyCallback)(UINT dwMsgID,UINT ip,UINT port,HANDLE hNotify,void *pPar);

//4������û����ͻ��˵�½ʱ���
typedef int  (*CheckUserPsw)(const CHAR *pUserName,const CHAR *pPsw);

//5���ͻ��˴��ݵ���Ϣ
typedef int  (*ServerMsgReceive)(ULONG ip,ULONG port,CHAR *pMsgHead);

//6������
typedef int	 (*ServerUpdateFile)(int nOperation,int hsock,ULONG ip,ULONG port,int nUpdateType,CHAR *pFileName,CHAR *pFileData,int nFileLen);


//7��ת��������û����ص�
typedef int	 (*RelayCheckUserCallback)(RELAY_TYPE relayType,UINT dwClientIP,USHORT wClientPort,CHAR *pszUserName,CHAR *pszPassword,CHAR *pszDeviceName,UINT dwRequstChannel,INT bOnline,CHAR *pDeviceIP,UINT *pdwDevicePort,CHAR *pContext);

//8�����ķ�����ģʽ�û����ص�
typedef int	 (*CenterCheckUserCallback)(INT bOnLine,DVS_MACHINE_TYPE machineType,UINT dwDeviceID,UINT dwChannelNum,UINT ip,USHORT port,CHAR *pszDeviceName,CHAR *pszUserName,CHAR *pszPassword,LPVOID pNetPar);

//9������¼��NVS�ص�
typedef void (*SearchRecNVSCallback)(CHAR *szNvsBuffer,int nBufferLen);

//10������¼���ļ�
//typedef void (WINAPI *SearchRecFileCallback)(void *pRecFile);
typedef void  (*SearchRecFileCallback)(UINT dwClientID,void *pRecFile);

//11������Ϣ�ص�����
typedef int	 (*MessageNotifyCallback)(UINT wParam, UINT lParam);



/******************************  �����ӿڽṹ���Ͷ���  ***************************/
#ifndef AV_INFO_DEFINE
#define AV_INFO_DEFINE

//1����Ƶ��Ƶ����
typedef struct _AV_INFO
{
    //��Ƶ����
    UINT			nVideoEncodeType;		//��Ƶ�����ʽ
    UINT			nVideoHeight;			//��Ƶͼ���
    UINT			nVideoWidth;			//��Ƶͼ���
    //��Ƶ����
    UINT			nAudioEncodeType;		//��Ƶ�����ʽ
    UINT			nAudioChannels;			//ͨ����
    UINT			nAudioBits;				//λ��
    UINT			nAudioSamples;			//������
}AV_INFO,*PAV_INFO;

#endif //AV_INFO_DEFINE


//2������Ƶ����֡ͷ
typedef struct _FRAME_HEAD
{
	USHORT	zeroFlag;				// 0
	UCHAR   oneFlag;				// 1
	UCHAR	streamFlag;				// ����֡��־ FRAME_FLAG_VP��FRAME_FLAG_VI��FRAME_FLAG_A
	
	ULONG	nByteNum;				//����֡��С
	ULONG	nTimestamp;				//ʱ���
}FRAME_HEAD;

//3,�������

typedef struct _ALARM_STATUS_OUTPUT_NEW
{
	unsigned char year;

	unsigned char month;

	unsigned char day;

	unsigned char week;

	unsigned char hour;

	unsigned char minute;

	unsigned char second;

	unsigned char millsecond; 

	unsigned int SensorAlarm;
	unsigned int MotionAlarm;
	unsigned int ViLoseAlarm;
	unsigned int RFSensorAlarm;
	unsigned int NetAlarm;

	unsigned int SensorAlarmRec[MAX_SENSOR_NUM];
	unsigned int MotionAlarmRec[MAX_VIDEO_NUM];
	unsigned int ViLoseAlarmRec[MAX_VIDEO_NUM];
	unsigned int RFSensorAlarmRec[MAX_RF_SENSOR_NUM];
	unsigned int NetAlarmRec;

	unsigned int OutputStatus;

	unsigned int reserved[19];
}ALARM_STATUS_OUTPUT_NEW;


//4������֪ͨ��Ϣ�ṹ

typedef struct _ALARM_MSG_NOTIFY_NEW
{
	HANDLE hLogonServer;

	UINT dwClientID;

	UINT dwServerIP;

	UINT dwServerPort;

	ALARM_STATUS_OUTPUT_NEW alarmStatus;
}ALARM_MSG_NOTIFY_NEW;



//5������Ƶͨ������

typedef struct _OPEN_CHANNEL_INFO_EX
{
    ULONG                         dwClientID;                       //�ص�����	(��Ӧ�ص��������dwClientID)
    UINT                          nOpenChannel:8;                   //ͨ���ţ�0 �� 3��
    UINT                          nSubChannel:8;                    //0: ��������      1: �򿪴�����
    UINT                          res:16;                            //����
    NET_PROTOCOL_TYPE             protocolType;                     //���ӷ�ʽ��TCP��UDP���ಥ��  
    ChannelStreamCallback         funcStreamCallback;              //����Ƶ�����ݻص����� 
    void                          *pCallbackContext;               //�ص�����2(��Ӧ�ص��������pContext) 
}OPEN_CHANNEL_INFO_EX;

//6������Ƶͨ������
typedef struct _OPEN_VIEWPUSH_INFO
{
	UINT					dwClientID;
	UINT					nViewPushChannel;
	NET_PROTOCOL_TYPE		protocolType;
	AV_INFO				avInformation;
	UINT					nMulticastAddr;
	UINT					nMulticastPort;
	UINT					nScreenCount;
	UINT					nScreenIndex;
}OPEN_VIEWPUSH_INFO;

//7���򿪵ķ�������Ϣ
typedef struct _SERVER_INFO
{
	HANDLE					hServer;
	CHAR					szServerIP[MAX_IP_NAME_LEN+1];
	UINT					nServerPort;
	CHAR					szDeviceName[DVS_NAME_LEN+1];
	UINT					nDeviceID;
	CHAR					szUserName[USER_NAME_LEN+1];
	CHAR					szUserPassword[USER_PASSWD_LEN+1];
	UINT					dwClientID;
	CONNECT_STATUS			logonStatus;
	UINT					nVersion;
	UINT					nLogonID;
	UINT					nPriority;
	UINT					nServerChannelNum;
	UINT					nLanguageNo;
	DVS_MACHINE_TYPE		nMachineType;
	INT						bPalStandard;
	UINT					nMulticastAddr;
	UINT					nMulticastPort;
	AV_INFO					avInformation[MAX_VIDEO_NUM];
}SERVER_INFO;

//8���򿪵�ͨ����Ϣ
typedef struct _CHANNEL_INFO
{
	HANDLE					hOpenChannel;
	CHAR					szServerIP[MAX_IP_NAME_LEN+1];
	UINT					nServerPort;
	CHAR					szDeviceName[DVS_NAME_LEN+1];
	CHAR					szUserName[USER_NAME_LEN+1];
	CHAR					szUserPassword[USER_PASSWD_LEN+1];
	UINT					dwClientID;
	CONNECT_STATUS			openStatus;
	UINT					nVersion;
	UINT					nOpenID;
	UINT					nPriority;
	UINT					nOpenChannelNo;
	UINT					nMulticastAddr;
	UINT					nMulticastPort;
	AV_INFO				avInformation;
	ENCODE_VIDEO_TYPE		encodeVideoType;
	NET_PROTOCOL_TYPE		protocolType;
	ChannelStreamCallback	funcStreamCallback;
	void					*pCallbackContext;
	UINT					dwDeviceID;	//V4.0 add
}CHANNEL_INFO;

//9���򿪵Ľ���������ͨ����Ϣ
typedef struct _VIEWPUSH_INFO
{
	HANDLE				hOpenChannel;
	CHAR				szServerIP[MAX_IP_NAME_LEN+1];
	UINT				nServerPort;
	CHAR				szDeviceName[DVS_NAME_LEN+1];
	CHAR				szUserName[USER_NAME_LEN+1];
	CHAR				szUserPassword[USER_PASSWD_LEN+1];
	UINT				dwClientID;
	CONNECT_STATUS		openStatus;
	UINT				nVersion;
	UINT				nOpenID;
	UINT				nPriority;
	UINT				nOpenChannelNo;
	UINT				nMulticastAddr;
	UINT				nMulticastPort;
	AV_INFO			avInformation;
	ENCODE_VIDEO_TYPE	encodeVideoType;
	NET_PROTOCOL_TYPE	protocolType;
	DVS_MACHINE_TYPE	nMachineType;
	UINT				dwChannelNum;	//���������·��
}VIEWPUSH_INFO;

//10���Խ�����Ϣ
typedef struct _SS_TALK_INFO 
{
	HANDLE				hServer;
	CHAR				szServerIP[MAX_IP_NAME_LEN+1];
	UINT				nServerPort;
	CHAR				szDeviceName[DVS_NAME_LEN+1];
	CHAR				szUserName[USER_NAME_LEN+1];
	CHAR				szUserPassword[USER_PASSWD_LEN+1];
	ULONG		version;	
	ULONG		nMachineType;
	CONNECT_STATUS		logonStatus;
	//audio parameter
	UINT				nAudioEncodeType;
    UINT				nAudioChannels;
    UINT				nAudioBits;
    UINT				nAudioSamples;
}TALKING_INFO;

//11�������㲥���û���Ϣ
typedef struct _BROADCAST_USER
{
	HANDLE	hBroadcastUser;
	CHAR	szServerIP[MAX_IP_NAME_LEN+1];
	UINT	port;
	CHAR	szDeviceName[DVS_NAME_LEN+1];	
	CHAR	szUserName[USER_NAME_LEN+1];
	CHAR	szUserPassword[USER_PASSWD_LEN+1];
	INT	bConnect;
	//SOCKET	hSock;
	//PVOID	pPar;
	//add v4.2
	UINT				machineType;
	ENCODE_VIDEO_TYPE	audioType;
}BROADCAST_USER;

//12��ת����Ƶ������
typedef struct _RELAY_NVS
{
	RELAY_TYPE			relayType;
	CHAR				szServerIP[MAX_IP_NAME_LEN+1];
	USHORT				wServerPort;
	CHAR				szDeviceName[DVS_NAME_LEN+1];
	UINT				dwChannelNo;
	UINT				dwCount;
}RELAY_NVS;	

//13���ٷֱ���Ϣ֪ͨ
typedef struct _PERCENT_NOTIFY
{
	HANDLE				hLogon;
	UINT				dwClientID;
	UINT				dwPercent;
}PERCENT_NOTIFY;

//14����Ƶ�ļ�����
typedef struct _FILE_INFO
{
	CHAR                szFileName[MAX_PATH];
	CHAR				szServerIP[MAX_IP_NAME_LEN+1];
	USHORT				wServerPort;
	CHAR				szUserName[USER_NAME_LEN+1];
	CHAR				szUserPassword[USER_PASSWD_LEN+1];
	INT                bRelay     ; // ���ļ��Ƿ�ͨ��ת��
}FILE_INFO;

//15������Ƶ�ļ�����
typedef struct _OPEN_FILE_INFO
{
	UINT				dwClientID  ;
	UINT				nOpenChannel;
	NET_PROTOCOL_TYPE	protocolType;
	CHAR				szDeviceName[DVS_NAME_LEN+1];
	FILE_INFO        hhFile      ;       
	CHAR                szOpenMode[5];
	UINT				dwSocketTimeOut;
	
    // ���
	UINT				dwFileSize;         // �ļ���С
	UINT				dwStartTime;        // ���ſ�ʼʱ��(����)
	UINT				dwEndTime;          // ���Ž���ʱ��(����)
	
	UINT				nVideoEncodeType;	//��Ƶ�����ʽ
	UINT				nAudioEncodeType;	//��Ƶ�����ʽ	
}OPEN_FILE_INFO;

//16��������������������NVS
typedef struct _SEARCH_REC_NVS
{
	UINT				dwClientID  ;
	// �洢¼���ļ�������
	CHAR                Date[11];			// ����1 ¼������ yyyy-mm-dd
    UCHAR                recType ;			// ����2 ¼������: 0-���У�1-������2-�ֶ���3-��ʱ
	
	//SearchRecNVSCallback	funcSearchRecNvsCallback;	
}SEARCH_REC_NVS;

// 17��������������������¼���ļ�
typedef struct _SEARCH_REC_FILE
{
	UINT				dwClientID  ;

	// �洢¼���ļ�������
    CHAR                szDir[MAX_PATH]; 	// ����1: " Datae\\Ip-NVS\\Camera\\"
	CHAR				szTime1[6];      	// ����2 ʱ���1 hh:mm
	CHAR				szTime2[6];      	// ����2 ʱ���2 hh:mm
    UCHAR                recType ;	    	 // ����3 ¼������: 0-���У�1-������2-�ֶ���3-��ʱ
	
	SearchRecFileCallback	funcSearchRecFileCallback;
}SEARCH_REC_FILE;

//18��ת����ѯ
typedef struct _RELAY_QUERY_INFO
{
	UINT		dwSize;
	UINT		dwServerLogonNum;
	UINT		dwServerPreviewNum;
	UINT		dwServerTalkNum;
	UINT		dwServerBrdNum;
	UINT		dwClientLogonNum;
	UINT		dwClientPreviewNum;
	UINT		dwClientTalkNum;
	UINT		dwClientBrdNum;
	CHAR		reserve[16];
}RELAY_QUERY_INFO;



typedef struct _SEARCH_SER_INFO
{ 
	char				userName[USER_NAME_LEN+1];
	char				userPassword[USER_PASSWD_LEN+1];
	DVS_MACHINE_TYPE	nDeviceType;
	char				szDeviceName[64];
	unsigned long		ipLocal;
	unsigned char		macAddr[6];
	unsigned short		wPortWeb;
	unsigned short		wPortListen;
	unsigned long		ipSubMask;
	unsigned long		ipGateway;
	unsigned long		ipMultiAddr;
	unsigned long		ipDnsAddr;
	unsigned short		wMultiPort;
	int					nChannelNum;
}SEARCH_SER_INFO;

//========================================================================
//				�ġ� ����Ƶ����֡ͷ
//========================================================================

//1������֡��־
#define FRAME_FLAG_VP		0x0b	//��Ƶ��P֡
#define FRAME_FLAG_VI		0x0e	//��Ƶ��I֡
#define FRAME_FLAG_A		0x0d	//��Ƶ֡

//��չ֡ͷ
#define	EXT_HEAD_FLAG	0x06070809
#define	EXT_TAIL_FLAG	0x0a0b0c0d

//��Ƶ�����㷨
typedef enum  _PT_AENC_TYPE_E
{
	PT_AENC_NONE   = 0x0,
	PT_AENC_G726   = 0x01,
	PT_AENC_G722   = 0x02,
	PT_AENC_G711A  = 0x03,
	PT_AENC_ADPCM  = 0x04,
	PT_AENC_MP3    = 0x05,
	PT_AENC_PCM    = 0x06,
	PT_AENC_G711U  = 0x07,
	PT_AENC_AACLC  = 0x08,
	PT_AENC_AMRNB  = 0x09,
}PT_AENC_TYPE_E;


//��Ƶ�����㷨
typedef enum  _PT_VENC_TYPE_E
{
	PT_VENC_NONE   = 0x0,
	PT_VENC_H264   = 0x01,
	PT_VENC_MPEG4  = 0x02,
	PT_VENC_MJPEG  = 0x03,
	PT_VENC_JPEG   = 0x04,
}PT_VENC_TYPE_E;



//��Ƶ����
typedef struct _EXT_FRAME_VIDEO
{
	unsigned short	nVideoEncodeType;	//��Ƶ�����㷨
	unsigned short	nVideoWidth;		//��Ƶͼ���
	unsigned short	nVideoHeight;		//��Ƶͼ���
	unsigned char   nPal;               //��ʽ
	unsigned char   bTwoFeild;			//�Ƿ�����������(������������룬PC����Ҫ��deinterlace)
	unsigned char   nFrameRate;			//֡��
	unsigned char   szReserve[7];		//

} EXT_FRAME_VIDEO;

//��Ƶ����
typedef struct _EXT_FRAME_AUDIO
{
	unsigned short	nAudioEncodeType;	//��Ƶ�����㷨
	unsigned short	nAudioChannels;		//ͨ����
	unsigned short	nAudioBits;			//λ��
	unsigned char   szReserve[2];
	unsigned long	nAudioSamples;		//������ 	
	unsigned long	nAudioBitrate;		//��Ƶ��������
} EXT_FRAME_AUDIO;

typedef union _EXT_FRAME_TYPE
{
	EXT_FRAME_VIDEO	szFrameVideo;
	EXT_FRAME_AUDIO	szFrameAudio;
} EXT_FRAME_TYPE;

typedef struct _EXT_FRAME_HEAD
{
    unsigned long	nStartFlag;			//��չ֡ͷ��ʼ��ʶ
    unsigned short	nVer;				//�汾
    unsigned short	nLength;			//��չ֡ͷ����
	EXT_FRAME_TYPE	szFrameInfo;		
	unsigned long   nTimestamp;			//�Ժ���Ϊ��λ��ʱ���
	unsigned long	nEndFlag;			//��չ֡ͷ��ʼ��ʶ
}EXT_FRAME_HEAD;




typedef INT  (*StreamWriteCheck)(int nOperation,const CHAR *pUserName,const CHAR *pPsw,ULONG ip,ULONG port,OPEN_VIEWPUSH_INFO viewPushInfo,HANDLE hOpen);
typedef INT (*CallbackServerFind)(SEARCH_SER_INFO *pSearchInfo);

/********************************  �塢�����ӿڶ���  *****************************/

//��������
ERR_CODE		NET_Startup(USHORT nBasePort,MsgNotifyCallback msgCallback,CheckUserPsw checkUserPswCallback,ServerUpdateFile updateCallback,ServerMsgReceive msgCmdCallback,StreamWriteCheck streamWriteCheckCallback,ChannelStreamCallback funcChannelCallback);
//�رշ���
ERR_CODE		NET_Cleanup();


//��¼������
ERR_CODE		NET_LogonServer(IN  CHAR *pServerIP,IN  UINT nServerPort,IN  CHAR *pDeviceName,IN	 CHAR *pUserName,IN	 CHAR *pUserPassword,IN UINT dwClientID,OUT  HANDLE *hLogonServer);
//ע��������
ERR_CODE		NET_LogoffServer(IN  HANDLE hServer);
//��ȡ��¼��������Ϣ
ERR_CODE		NET_ReadServerInfo(IN  HANDLE hServer,OUT  SERVER_INFO *serverInfo);

//��������
ERR_CODE		NET_Update(IN HANDLE hServer,IN UPDATE_TYPE nUpdateType,IN CHAR *pFilePathName);


//��ȡ��¼������������Ϣ
ERR_CODE		NET_GetServerConfig(IN  HANDLE hServer,IN  CMD_NET nConfigCommand,OUT  CHAR *pConfigBuf,IN OUT  UINT *nConfigBufSize,IN  OUT  UINT *dwAppend);
//���õ�¼������������Ϣ
ERR_CODE		NET_SetServerConfig(IN  HANDLE hServer,IN  CMD_NET nConfigCommand,IN   CHAR *pConfigBuf,IN  UINT nConfigBufSize,IN  UINT dwAppend);


//����Ƶͨ��
ERR_CODE		NET_OpenChannel(IN  CHAR *pServerIP,IN  UINT nServerPort,IN  CHAR *pDeviceName,IN  CHAR *pUserName,IN  CHAR *pUserPassword,IN  OPEN_CHANNEL_INFO_EX *pOpenInfo,OUT  HANDLE *hOpenChannel);
//�ر���Ƶͨ��
ERR_CODE		NET_CloseChannel(IN  HANDLE hOpenChannel);

//��ȡ����Ƶͨ����Ϣ
ERR_CODE		NET_ReadChannelInfo(IN  HANDLE hOpenChannel,OUT  CHANNEL_INFO *channelInfo);


//����򿪶Խ�
//ERR_CODE		NET_TalkRequsest(IN  CHAR *pServerIP,IN  UINT nServerPort,IN  CHAR *pDeviceName,IN	 CHAR *pUserName,IN	 CHAR *pUserPassword,IN TalkStreamCallback funcTalkCallback,IN void *pContext);
ERR_CODE		NET_TalkRequsest(IN  char *pServerIP, IN  UINT nServerPort,IN  char *pDeviceName,IN	 char *pUserName,IN	 char *pUserPassword,IN TalkStreamCallback funcTalkCallback,IN void *pContext, OUT  TALKHANDLE *hTalkback);

//�����Խ�
//ERR_CODE		NET_TalkStop();
ERR_CODE		NET_TalkStop(IN  TALKHANDLE hTalkback);

//��ȡ�򿪶Խ���Ϣ
//ERR_CODE		NET_TalkReadInfo(TALKING_INFO *talkInfo);
//���ͶԽ�����
//ERR_CODE		NET_TalkSend(IN CHAR *pTalkData,IN UINT nDataLen);
ERR_CODE		NET_TalkSend(IN  TALKHANDLE hTalkback, IN char *pTalkData,IN UINT nDataLen);


//���������豸
ERR_CODE		NET_SearchAllServer(UINT nTimeWait,	 CallbackServerFind  funcServerFind);
//������Ƶ��������������
ERR_CODE		NET_ConfigServer(UCHAR macAddr[6],CHAR *pUserName,CHAR *pUserPassword,
													   CHAR *pIP,CHAR *pDeviceName,CHAR *pSubMask,CHAR *pGateway,CHAR *pMultiAddr,
													   CHAR *pDnsAddr,USHORT wPortWeb,USHORT wPortListen,USHORT wPortMulti);

void NET_UpdatePercentNotify(int hsock,ULONG nPercent);

ERR_CODE        NET_SetNetApiSupportVersion(int nVersion);


#endif


