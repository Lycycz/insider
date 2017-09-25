/******************************************************************************
* ϵͳ���ƣ��豸����
* �ļ����ƣ�param.h
* �汾    ��	V2.0.0.0.2
* ˵��	  ��
			�ӿڽṹ�������Ͷ��壻

			  
			  һ���������� ����
			  		I�� ϵͳ����
			  		II�� �����궨��
			  		III�������̨����
			  		
			  ����ö�����Ͷ���
			  	
			  		

			   ��������������������Ϣ�ṹ
			   		I��   ���ýṹ
			   		II��  ϵͳ����
			   			1������ʱ��
			   			2��������Ϣ
			   			3��NTP����
			   			4���û�����

			   		III��  ��Ƶ����
			   			1����Ƶ����(osd�ַ����ӡ� ��Ƶ���롢 ��ɫ����,   ͼƬ����)
			   			2���豸֧�ֵı����ʽ�Ϳ��
			   			3��ͼ����������
			   			4����Ƶ�����ɫ�ʵ��ں��������
			   			5����Ƶ���볡��������� 
			   			6����Ƶ���������ɫ�ʵ��ںͳ�������
			   			7����Ƶ�źŲ���
			   		IV��  ��Ƶ����
			   			1����Ƶ����
			   			
			   		V��   ��������
			   			1���������ýṹ(�����������������硢pppoe������ DDNS��������������)
			   			2������ WIFI ����
			   			3��UPNP  ����
			   			4��EMAIL����
			   			5�� FTP ����������
			   			6��DDNS����
			   			7��3G����
			   		VI��  �洢����
			   			1��������Ϣ
			   			2��¼��ƻ�
			   			3��ץ�ļƻ�
			   			
			   		VII�� ��������
			   			1���ƶ�����
			   			2��̽ͷ����
			   			3�����籨��
			   			4����Ƶ��ʧ����
			   			5�������������
			   			
			   		VIII����������

					IX����̨
			   			1��͸��ͨѶ
			   			2����̨����
			   			3����̨��Ϣ
			   			
			   		X��  ���������ṹ
			   			1��TW2824����
			   			2����ʱ����
			   			3����չ��Ϣ�ṹ(ntp, upnp, email, alarm in/out, wifi, send dest, auto reset, ftp, rstp, gps)
			   			4���û�����
			   			5���豸���в����ṹ
			   			
			   	�ġ� ����������������Ϣ�ṹ
* ����˵��: ��
******************************************************************************/
#ifndef  __PARAM_H__
#define  __PARAM_H__
	
#define PACKED  __attribute__((packed, aligned(1)))
#define PACKED4 __attribute__((packed, aligned(4)))


 /**************************** ********************************************
						  һ���������� ����
 **************************************************************************/

 // 1�� �����������Ͷ���

typedef	char				CHAR;
typedef	short				SHORT;
typedef int					INT;
typedef	long				LONG;
typedef	unsigned char		UCHAR;
typedef	unsigned short		USHORT;
typedef unsigned int		UINT;
typedef	unsigned long		ULONG;
typedef	int					BOOL;
typedef unsigned long*		HANDLE;
typedef unsigned long  		*TALKHANDLE;
typedef void*				LPVOID;

typedef unsigned char       UInt8;
typedef unsigned short      UInt16;
typedef unsigned int        UInt32;

typedef unsigned char  		 BYTE ;
typedef unsigned long 		 DWORD;


//2��ϵͳ����
#define	IN
#define	OUT
#define	MAX_PATH					256

#define MAX_VIDEO_NUM				4	//������Ƶ���������ͨ����
#define MAX_AUDIO_NUM				4	//������Ƶ��������Ƶ���ͨ����
#define MAX_SENSOR_NUM				4	//̽ͷ����·��
#define MAX_RF_SENSOR_NUM			8	//����̽ͷ���·��
#define MAX_OUTPUT_NUM				4	//̽ͷ���·��
#define MAX_COM_NUM					2	//����������	
#define MAX_USER_NUM				5	//�û�����
#define MAX_LOGON_NUM				10	//���ͬʱ��¼�û���
#define MAX_LINKVIEW_NUM			16	//���ͬʱTCP��UDPԤ���û���
#define MAX_MULTIVIEW_NUM			60	//���ಥ�û���
#define DVS_NAME_LEN           	32	//������Ƶ���������Ƴ���

#define CAM_TITLE_LEN_NEW			64	//31�����֣�63���ַ�
#define CAM_TITLE_LEN				16	//��������ⳤ��(8�����֣�16���ַ�)
#define USER_NAME_LEN 				16	//�û�������󳤶�
#define USER_PASSWD_LEN   			16	//�û�������󳤶�
	
#define DDNS_NAME_LEN				32	//ע���������Ƴ���
#define DDNS_PASS_LEN				16	//ע���������볤��	
#define	DDNS_SERVER_NAME_LEN		32
#define PPPPOE_NAME_LEN			32	//�����û�������
#define PPPPOE_PASSWD_LEN			16	//�����û�������
#define YUNTAI_NAME_LEN			32	//��̨Э�����Ƴ���
#define MAX_YUNTAI_PROTOCOL_NUM	36	//���������̨Э����
#define MAX_PTZ_PROTOCOL_NUM  		4	//�����̨Э����
#define	MAX_IP_NAME_LEN			128	//����IP�����ֵ���󳤶�
#define	IP_STR_LEN					16	//IP��

#define	DOMAIN_NAME_LEN			32  //�����ĳ���
#define EMAIL_TITLE_LEN        	32	//EMAILͷ�����ݳ�
#define DD_URL_ADDR_LEN			32	//URL��ַ����
#define	DD_MAX_ADDR_NUM			32	//��ַ���ĵ�ַ����
#define	DD_MAX_ALARMINFO_NUM		64	//������¼�������ֵ

#ifndef NULL
#define NULL  ((void *)0)
#endif


//3����̨����
#define	YT_UP					1	//��̨��
#define	YT_DOWN					2	//��̨��	
#define	YT_LEFT					3	//��̨��
#define	YT_RIGHT				4	//��̨��
#define	YT_FOCUSADD				5	//�۽�+
#define	YT_FOCUSSUB				6	//�۽�-
#define	YT_IRISADD				7	//��Ȧ+
#define	YT_IRISSUB				8	//��Ȧ-
#define	YT_ZOOMADD				9	//�䱶+
#define	YT_ZOOMSUB				10	//�䱶-
#define	YT_AUTOOPEN				11	//�Զ���
#define	YT_AUTOCLOSE			12	//�Զ���
#define	YT_LAMPOPEN				13	//�ƹ⿪
#define	YT_LAMPCLOSE			14	//�ƹ��
#define	YT_BRUSHOPEN			15	//��ο�
#define	YT_BRUSHCLOSE			16	//��ι�
#define	YT_WATEROPEN			17	//��ˮ��
#define	YT_WATERCLOSE			18	//��ˮ��
#define	YT_PRESET				19	//Ԥ�� + ��
#define	YT_CALL					20	//���� + ��
#define	YT_STOP					21	//ֹͣ
#define	YT_UP_STOP				30	//��̨��-ͣ	
#define	YT_DOWN_STOP			31	//��̨��-ͣ	
#define	YT_LEFT_STOP			32	//��̨��-ͣ
#define	YT_RIGHT_STOP			33	//��̨��-ͣ
#define	YT_FOCUSADD_STOP		34	//�۽�+ -ͣ
#define	YT_FOCUSSUB_STOP		35	//�۽�- -ͣ
#define	YT_IRISADD_STOP		36	//��Ȧ+ -ͣ
#define	YT_IRISSUB_STOP		37	//��Ȧ- -ͣ
#define	YT_ZOOMADD_STOP		38	//�䱶+ -ͣ
#define	YT_ZOOMSUB_STOP		39	//�䱶- -ͣ	
#define YT_PRESET_DEL			70  //Ԥ��λɾ��

//-----------------------------------end--------------------------------


/********************************************************************************
								����ö�����Ͷ���
*********************************************************************************/

// ��Ƶ�����㷨
typedef enum _VIDEO_ENCODER_E
{
    VENC_NONE  = 0x00,
    VENC_H264  = 0x01,
    VENC_MPEG4 = 0x02,
    VENC_MJPEG = 0x03,
    VENC_JPEG  = 0x04,
}VIDEO_ENCODER_E;

//��Ƶ�����㷨
typedef enum _AUDIO_ENCODER_E
{
    AENC_NONE  = 0x00,
    AENC_G726  = 0x01,
    AENC_G722  = 0x02,
    AENC_G711  = 0x03,
    AENC_ADPCM = 0x04,
    AENC_MP3   = 0x05,
}AUDIO_ENCODER_E;

//��Ƶ������
typedef enum _AUDIO_SAMPLERATE_E
{
    AI_SAMPLE_RATE_NONE  = 0, 
    AI_SAMPLE_RATE_8000  = 8000,  /* 8kHz sampling rate      */
    AI_SAMPLE_RATE_11025 = 11025, /* 11.025kHz sampling rate */
    AI_SAMPLE_RATE_16000 = 16000, /* 16kHz sampling rate     */
    AI_SAMPLE_RATE_22050 = 22050, /* 22.050kHz sampling rate */
    AI_SAMPLE_RATE_24000 = 24000, /* 24kHz sampling rate     */
    AI_SAMPLE_RATE_32000 = 32000, /* 32kHz sampling rate     */
    AI_SAMPLE_RATE_44100 = 44100, /* 44.1kHz sampling rate   */
    AI_SAMPLE_RATE_48000 = 48000, /* 48kHz sampling rate     */
}AUDIO_SAMPLERATE_E;

//��Ƶ��������(G726)
typedef enum _AUDIO_BITRATE_E
{ 
    AENC_BITRATE_NONE  = 0,
    AENC_BITRATE_16000 = 16000, 
    AENC_BITRATE_24000 = 24000, 
    AENC_BITRATE_32000 = 32000, 
    AENC_BITRATE_40000 = 40000, 
}AUDIO_BITRATE_E;


//��Ƶ�����ɫ�ʵ��ں�������ã����Ͷ���
typedef enum _VIDEO_IN_SENSOR_E
{
	//ɫ��
	VCT_BRIGHTNESS	=	0X00000001,//����
	VCT_HUE			=	0X00000002,//ɫ��
	VCT_CONTRAST	=	0X00000004,//�Աȶ�
	VCT_SATURATION	=	0X00000008,//���Ͷ�
	VCT_SHARPNESS	=	0X00000010,//���
	VCT_RED			=	0X00000020,//��ɫ
	VCT_GREEN		=	0X00000040,//��ɫ
	VCT_BLUE		=	0X00000080,//��ɫ
	VCT_GAMMA		=	0X00000100,//Gamma

	//��ƽ��
	VCT_AUTOAWB		=	0X00000200,//�Զ���ƽ��
	VCT_AWBRED		=	0X00000400,//��ƽ�� ��
	VCT_AWBGREEN	=	0X00000800,//��ƽ�� ��
	VCT_AWBBLUE		=	0X00001000,//��ƽ�� ��

	//����
	VCT_AUTOAGC		=	0X00002000,//�Զ�����
	VCT_AGCLEVEL	=	0X00004000,//����ֵ

	//���ⲹ��
	VCT_AUTOBLC		=	0X00008000,//�Զ�����
	VCT_BLCLEVEL	=	0X00010000,//����ֵ
	
	//�ع�
	VCT_AUTOEXPOSURE=	0X00020000,//�Զ��ع� 
	VCT_EXPOSURETIME=	0X00040000,//�ֶ��ع�ʱ�� 
	
	//����
	VCT_SHUTTERFIRST=	0X00080000,//���š��ع�����
	VCT_AUTOSHUTTER	=	0X00100000,//�Զ�����
	VCT_SHUTTERSPEED=	0X00200000,//�����ٶ�
	VCT_SLOWSHUTTER	=	0X00400000,//������
	VCT_SLOWSHUTTERLEVEL=0X00800000,//�������ٶ�

	VCT_AUTOAWBMODE =	0X01000000,//1080p Hispeed�Զ���ƽ��ģʽ

	VCT_SENSOR_ALL	=	0xFFFFFFFF,//�������Բ���
}VIDEO_IN_SENSOR_E;

//��Ƶ���볡�����ã����Ͷ���
typedef enum _VIDEO_IN_SCENE_E
{
	//��Ȧ
	VCT_AUTOIRIS	=	0X00000001,//�Զ���Ȧ
	VCT_IRISLEVEL	=	0X00000002,//��Ȧ��ƽ

	//�۽�
	VCT_AUTOFOCUS	=	0X00000004,//�Զ��۽�
	VCT_FOCUSLEVEL	=	0X00000008,//����

	//�䱶
	VCT_ZOOMSPEED	=	0X00000010,//�䱶�ٶ�
	VCT_AUTOPTZSPEED=	0X00000020,//�����������

	//��ƽ����
	VCT_AUTOALC		=	0X00000040,//�Զ���ƽ����
	VCT_ALCLEVEL	=	0X00000080, //��ƽ����ֵ
	
	//��ת��
	VCT_CTB			=	0X00000100,//��ת��

	//����
	VCT_SCENE		=	0X00000200,//����
	VCT_MIRROR		=	0X00000400,//����
	VCT_FLIP		=	0X00000800,//��ת
	VCT_AUTOFLIP	=	0X00001000,//�Զ���ת
	VCT_PWDFREQ1	=	0X00002000,//����Ƶ��1
	VCT_PWDFREQ2	=	0X00004000,//����Ƶ��2

	//����
	VCT_IREXIST		=	0X00008000,//�Ƿ��к���
	VCT_IRCFMODE	=	0X00010000,//IRCFģʽ
	VCT_IRLIGHTTYPE	=	0X00020000,//���������
	//
	VCT_WDR 		=	0X00040000,//�Ƿ��п�̬
	VCT_WDRLEVEL	=	0X00080000,//��̬��ֵ
	VCT_LOWILLUM	=	0X00100000,//���ն�
	VCT_IMAGEMODE	=	0X00200000,//ͼ��ģʽ
	//
	VCT_VI_SIZE     =   0X00400000,//��Ƶ����ߴ�
	VCT_CTBLEVEL	=	0X00800000,//��ת�ڷ�ֵ������ת��Ϊ�Զ�ʱ��Ч
	VCT_MINFOCUSLEN =   0X01000000,//������С�۽�����
	VCT_IRLEVEL		=   0X02000000,//ҹ��������		
	VCT_LENSCORRECTION =0X04000000,//��ͷУ��		
	VCT_SMARTNR     = 	0x08000000,//���ܽ��� 0 ~ 255  0Ϊ��
	VCT_3DNR   	    =	0X10000000,//3D����		
	VCT_3DNRLEVEL	= 	0x20000000,//3D����ֵ

	VCT_SCENE_ALL	=	0xFFFFFFFF,//�������Բ���
}VIDEO_IN_SCENE_E;


typedef enum _WF_AUTH_TYPE		//����֤��������
{
	WF_AUTH_NONE	= 0x00,
	WF_AUTH_WEP		= 0x01,
	WF_AUTH_WPA		= 0x02,
	WF_AUTH_WPA2	= 0x03,
	WF_AUTH_WPAWPA2	= 0x04,
}WF_AUTH_TYPE;


typedef enum _WF_ENC_TYPE		//������֤����
{
	WF_ENC_NONE		= 0x00,		//WEP  ����ϵͳ
	WF_ENC_WEP		= 0x01,		//WEP  �����ܳ�
	WF_ENC_TKIP		= 0x02,		//WEP  �Զ�ѡ��
	WF_ENC_AES		= 0x03,
}WF_ENC_TYPE;


// 3G��������ģʽ   0-������ 1-ÿ������ʱ��  2-ÿ������ʱ��  3-������ÿ���ʱ�䣬Ҳ����ÿ�µ�ʱ��
typedef enum T3G_TIME_CTRL_MODE
{
	NO_LIMITED    = 0x00,
	DAY_LIMITED   = 0x01,
	MONTH_LIMITED = 0x02,
	ALL_LIMITED   = 0x03,
}T3G_TIME_CTRL_MODE;// ����ģʽ


//����Э������
typedef enum _NET_PROTOCOL_TYPE
{
    NET_PROTOCOL_TCP 	= 0,		//TCPЭ��
    NET_PROTOCOL_UDP 	= 1,		//UDPЭ��
    NET_PROTOCOL_MULTI = 2			//�ಥЭ��
}NET_PROTOCOL_TYPE;
//---------------------------------------------end---------------------------------




/**************************** ********************************************
						 �����������������ýṹ
**************************************************************************/

//-----------------------------------------------------------//
// CMS_NET (��������)    CMD_GET_XX(��ȡ������������)    CMD_SET_XX (���ò�����������)


//-----------------------------I�����ýṹ-----------------------------------------
//ʱ��νṹ������һ�����ʼʱ��ͽ���ʱ��

typedef struct _TIME_SEGMENT_NEW 
{
	UINT 		bDetectOpen;				//��⿪��
	UCHAR        nBgnHour ;					//��ʼʱ
	UCHAR        nBgnMinute ;				//��ʼ��
	UCHAR        nEndHour ;					//����ʱ
	UCHAR        nEndMinute ;				//������
}TIME_SEGMENT_NEW;

typedef  struct  _DVS_TIME
{
	UCHAR		year ;
	UCHAR		month ;
	UCHAR		day ;
	UCHAR		week ;
	UCHAR		hour   ;
	UCHAR		minute ;
	UCHAR		second ;
	UCHAR		millisecond;							
} DVS_TIME, *PDVS_TIME;



typedef struct _DATE_TIME_ST
{
	UINT			second : 6;							//��:  0 ~ 59
	UINT			minute : 6;							//��:  0 ~ 59
	UINT			hour : 5;							//ʱ:  0 ~ 23
	UINT			day : 5;							//��:  1 ~ 31
	UINT			month : 4;							//��:  1 ~ 12
	UINT			year : 6;							//��:  2000 ~ 2063
}DATE_TIME_ST;
//---------------------------------------------------------------------------------------


//-----------------------------II��ϵͳ�����ṹ-----------------------------------

//1������ʱ��ṹ
//CMD_NET   CMD_GET_TIME  CMD_SET_TIME
typedef  struct  _DVS_DATE
{
	UCHAR		year;									//��
	UCHAR		month;									//��
	UCHAR		day;									//��
	UCHAR		week;									//��
	UCHAR		hour;									//Сʱ
	UCHAR		minute;									//����
	UCHAR		second;									//��
}PACKED DVS_DATE;

//2��������Ϣ
//CMS_NET : CMD_GET_SYS_CONFIG		 CMD_SET_SYS_CONFIG      
typedef struct _DVS_CONFIG
{
   	CHAR               	sysName[DVS_NAME_LEN + 1];		//����
	UCHAR				sysInputNum;					//·��
	UCHAR				sysType;						//�����ͺ�	0:CIF  1:HD1  2:D1  
	UCHAR				sysVideoFormat;				//�����ʽ	
    UCHAR				sysLanguage;					//����
    UCHAR				sysStandard;					//��ʽ		0:PAL  1:NTSC
    UCHAR				AD[2];
	UINT      			sysID;  						//ÿ̨�����и�ID��  	
	UINT      			sysVer;  						//����汾  		
}PACKED DVS_CONFIG;


//3��NTP  ����
//CMS_NET: 	CMD_GET_NTP		CMD_SET_NTP    
typedef struct _NTP_CONFIG
{
	UINT			ntpOpen;							//NTP����
	UINT			ntpTimeZone;						//ʱ��
	CHAR			ntpHost[DOMAIN_NAME_LEN];			//NTP Server
}NTP_CONFIG;


//4���û�����
//CMS_NET:	CMD_GET_USER_CONFIG	  CMD_SET_USER_CONFIG    		  
typedef struct _USER_CONFIG
{
	UINT 		Level;									//Ȩ��
	CHAR 		Name[USER_NAME_LEN + 1];				//�û���
	CHAR 		Password[USER_PASSWD_LEN + 1];			//�û�����
	CHAR 		AD[2];
} PACKED USER_CONFIG;

//------------------------------end-------------------------------------

//-------------------------------III����Ƶ����-----------------------------

// osd  �������ꡢ����
typedef struct _OSD_CTRL_ST
{
	UINT		Show;						//0: ��  1: ��
	USHORT		X;							//x��y����ʾ��λ�ã���λ�õķ�ΧΪ0-704��0-576����ͼ��ķֱ����޹أ�x����Ϊ4�ı�����
	USHORT		Y;
} OSD_CTRL_ST ;

//��Ƶ�������
typedef struct _VENC_CTRL_ST
{
	UINT        Open;						//�Ƿ������루��������
	UINT		EncType;					//�����㷨
	UINT		EncFormat;					//�����ʽ(D1, HD1, CIF)
	UINT		Width;						//���
	UINT		Height;						//�߶�
	
	UINT		KeyInterval;			    //I ֡���
	UINT		Bitrate ;					//����
	float		FrameRate ;					//֡��float
	UINT		BitflowType; 			    //��������(0:VBR, 1:CBR)
	UINT		Qulity;						//����0--5
	UINT		Profile;				 	//0: baseline 1:main profile
	UINT       Reserved[7];
} VENC_CTRL_ST ;


//��Ƶ���
typedef struct _VIDEO_SIZE
{
	USHORT		Width;							//��
	USHORT		Height;							//��
}VIDEO_SIZE;


//=======================================
//ץ��ͼƬ����
//=======================================
typedef struct _PICTURE_CONFIG					//sizeof() = 148
{
	UINT		dwSize;							//���ṹ����

	UINT     	EncType;						//ץͼ��ʽ(.jpg, bmp) 
	UINT     	EncFormat;						//ͼƬ��������(24λ�� 32λ) 
	UINT     	Width;
	UINT     	Height;
	UCHAR		TwoFeild;						//
	UCHAR 		qulity;							//(1~5)
	UCHAR     	reseved[42];
}PICTURE_CONFIG;


//1, ��Ƶ����(osd�ַ����ӡ� ��Ƶ���롢 ��ɫ����,   ͼƬ����)
//CMS_NET:  CMD_GET_VIDEO_CONFIG_NEW	 	CMD_SET_VIDEO_CONFIG_NEW
typedef struct _VIDEO_CONFIG_NEW
{
	UINT			dwSize;						//���ṹ����

	VENC_CTRL_ST 	stMainVEncCtrl;			//����������
	VENC_CTRL_ST 	stMinVEncCtrl;				//����������
	PICTURE_CONFIG	stPictureCfg;				//ץ��ͼƬ����

	OSD_CTRL_ST		stDateOSD; 					// 0:����������,   1:��������
	OSD_CTRL_ST		stTimeOSD; 					// 0:������ʱ��,   1:����ʱ��
	OSD_CTRL_ST		stWeekOSD; 					// 0:����������,   1:�������� 
	OSD_CTRL_ST		stTitleOSD;					// 0:�����ӱ���,   1:���ӱ��� 
	OSD_CTRL_ST		stBitrateOSD;				// 0:����������,   1:�������� 	
	
	char    		Title[CAM_TITLE_LEN_NEW];	//�����ַ�(64���ַ�  31������)

    UCHAR 			Brightness;				    //����
	UCHAR 			Hue;						//ɫ��
	UCHAR 			Saturation;				    //���Ͷ�
	UCHAR 			Contrast;					//�Աȶ�

	USHORT 			Protocol;					//Э����(0 ~ MAX_PAN_PROTOCOL_NUM - 1)
	USHORT 			YTAddr;						//��������ַ
	UCHAR			mtClear;
	UCHAR			mtRed;
	UCHAR			mtBlue;
	UCHAR			mtGamma;
	UCHAR			nOsdPrefer;   				//0: XXXX-XX-XX ������ 
								 				//1: XX-XX-XXXX ������ 
												//2: XXXX��XX��XX�� 
												//3: XX��XX��XXXX��
							  
								
	UCHAR       	nOsdColor;	 			// 	osd��ɫ0��ɫ 1 �� 2�� 3�� 4 ��
	UCHAR      	 	nScene;      
	UCHAR       	nOSDClientNum;
	UCHAR        	reseved[24];
}VIDEO_CONFIG_NEW;


//2�� �豸֧�ֵı����ʽ�Ϳ��
//CMS_NET : CMD_GET_SUPPORT_AV_FMT

typedef struct _SUPPORT_AV_FMT
{
	UINT		dwSize;						//���ṹ����
	
	UINT		MainVideoFmt[8];			//�����������ʽ
	UINT		MinVideoFmt[8];				//�����������ʽ
	UINT		PictureFmt[8];				//ͼƬ�����ʽ

	VIDEO_SIZE  MainVideoSize[8];			//������ ����	
	VIDEO_SIZE  MinVideoSize[8];			//������ ����	
	VIDEO_SIZE  PictureSize[8];				//ͼƬ ����	

	UINT		AudioFmt[8];				//��Ƶ�����ʽ
	UINT		AudioSampleRate[8];			//��Ƶ������
	UINT		AudioBitrate[8];			//��Ƶ����
	UINT		AuidoAEC;					//�Ƿ�֧�ֻ�������

	UCHAR     	reserve[32];	
}SUPPORT_AV_FMT;


typedef struct _AREA_RECT
{
	USHORT		X;							//X����	
	USHORT		Y;							//Y����
	USHORT		W;							//���
	USHORT		H;							//�߶�
} AREA_RECT;


//3��ͼ����������
//CMS_NET:	CMD_GET_VMASK_CONFIG		CMD_SET_VMASK_CONFIG 	

typedef struct _VIDEOMASK_CONFIG_NEW
{
	UCHAR 			MaskOpen;					//��Ƶ���ο���		0:��         1����
	UCHAR			AA[3];
	AREA_RECT		MaskArea[9];				//��Ƶ��������		
}VIDEOMASK_CONFIG_NEW;


//4����Ƶ�����ɫ�ʵ��ں�������� size=64+32=96
//CMS_NET: CMD_GET_VI_SENSOR		CMD_SET_VI_SENSOR

typedef struct _VIDEO_IN_SENSOR_S
{
	VIDEO_IN_SENSOR_E	eValidSupport;		/*��Ч֧�ֵĲ������ò�������ʱ����Ч
											�ڻ�ȡ��ʱ����Ч�������ж��豸�Ƿ�֧�ָò���
											*/

	VIDEO_IN_SENSOR_E	eValidSetting;		/*������Ч�Ĳ������ò�����ȡʱ����Ч
											�����õ�ʱ����Ч������ָ���������õĲ���
											*/

	//ɫ��
	UInt8		byBrightness;				/*����;			0 ~ 255*/
	UInt8		byBrightnessDefault;		/*����ȱʡֵ;	*/
	UInt8		byBrightnessStep;			/*���ȵ��ڲ���;	*/

	UInt8		byHue;						/*ɫ��;			0 ~ 255*/
	UInt8		byHueDefault;				/*ɫ��ȱʡֵ;	*/
	UInt8		byHueStep;					/*ɫ�ȵ��ڲ���;	*/
	
	UInt8		byContrast;					/*�Աȶ�;	0 ~ 255*/
	UInt8		byContrastDefault;			/*�Աȶ�ȱʡֵ;	0 ~ 255*/
	UInt8		byContrastStep;			/*�Աȶȵ��ڲ���;	0 ~ 255*/

	UInt8		bySaturation;				/*���Ͷ�;	0 ~ 255*/
	UInt8		bySaturationDefault;		/*���Ͷ�ȱʡֵ;*/
	UInt8		bySaturationStep;			/*���Ͷȵ��ڲ���;*/

	UInt8		bySharpness;				/*���;		0 ~ 255*/
	UInt8		bySharpnessDefault;		/*���ȱʡֵ;*/
	UInt8		bySharpnessStep;			/*��ȵ��ڲ���;*/

	UInt8		byRed;						/*��ɫ;		0 ~ 255*/
	UInt8		byRedDefault;				/*��ɫȱʡֵ;*/
	UInt8		byRedStep;					/*��ɫ���ڲ���;*/

	UInt8		byGreen;					/*��ɫ;		0 ~ 255*/
	UInt8		byGreenDefault;			/*��ɫȱʡֵ;*/
	UInt8		byGreenStep;				/*��ɫ���ڲ���;*/

	UInt8		byBlue;						/*��ɫ;		0 ~ 255*/
	UInt8		byBlueDefault;				/*��ɫȱʡֵ;*/
	UInt8		byBlueStep;					/*��ɫ���ڲ���;*/

	UInt8		byGamma;					/*gamma;	0 ~ 255*/
	UInt8		byGammaDefault;			/*gammaȱʡֵ;*/
	UInt8		byGammaStep;				/*gamma���ڲ���;*/


	//��ƽ��
	UInt8		byAutoAwb;					/*�Զ���ƽ��;	0�Զ�, 1 �ֶ�*/
	
	UInt8		byAwbRed;					/*��ƽ�� ��;	0 ~ 255*/
	UInt8		byAwbRedDefault;			/*��ƽ�� ��ȱʡֵ;*/
	UInt8		byAwbRedStep;				/*��ƽ�� ����ڲ���;*/

	UInt8		byAwbGreen;					/*��ƽ�� ��;	0 ~ 255*/
	UInt8		byAwbGreenDefault;			/*��ƽ�� ��ȱʡֵ;*/
	UInt8		byAwbGreenStep;			/*��ƽ�� �̵��ڲ���;*/

	UInt8		byAwBblue;					/*��ƽ�� ��;	0 ~ 255*/
	UInt8		byAwBblueDefault;			/*��ƽ�� ��ȱʡֵ;*/
	UInt8		byAwBblueStep;				/*��ƽ�� �����ڲ���;*/

	//���������   1080P   byAgcLevel --> �������ֵ
	//						  720P   byAgcLevel --> AGC
	//							     byAutoAgc  --> �������ֵ
 	//����
	UInt8		byAutoAgc;					/*�Զ�����;		0�Զ�, 1 �ֶ�*/
	UInt8		byAgcLevel;					/*����ֵ;		0 ~ 255*/
	UInt8		byAgcLevelDefault;			/*����ֵȱʡֵ;*/
	UInt8		byAgcLevelStep;			/*����ֵ���ڲ���;*/


	//���ⲹ��
	UInt8		byAutoBlc;					/*�Զ�����;		0�Զ�, 1 �ֶ�*/
	UInt8		byBlcLevel;					/*����ֵ;		0 ~ 255*/
	UInt8		byBlcLevelDefault;			/*����ֵȱʡֵ;*/
	UInt8		byBlcLevelStep;			/*����ֵ���ڲ���;*/
	

	//�ع�
	UInt8		byAutoExposure;			/*0�Զ� 1 �ֶ�*/
	UInt16		wExpoSuretime;				/*�ֶ��ع�ʱ��	F1.6=16
													F2.2=22
													F3.2=32
													F4.4=44
													F6.4=64
													F8.8=88
													F12.0=120
													F17.0=170
													F24.0=240
													F34.0=340
											*/


	//����
	UInt8		byShutterFirst;			/*���š��ع�����;	0��������, 1 �ع�����*/
	UInt8		byAutoShutter;				/*�Զ�����;		0�Զ�, 1 �̶�*/
	UInt16		wShutterSpeed;				/*�����ٶ�;		1		= 1
													1/2		= 2
													1/4		= 4
													1/8		= 8
													1/16	= 16
													1/25	= 25
													1/50	= 50
													1/100	= 100
													1/150	= 150
													1/200	= 200
													1/250	= 250
													1/300	= 300
													1/400	= 400
													1/1000	= 1000
													1/2000	= 2000
													1/4000	= 4000
													1/10000	= 10000
												*/
	UInt8		bySlowShutter;					/*������;		0��,   1 ��*/

	UInt8		bySlowShutterLevel;			/*�������ٶ�;	0 ~ 255*/
	UInt8		bySlowShutterLevelDefault;	/*�������ٶ�ȱʡֵ;*/
	UInt8		bySlowShutterLevelStep;		/*�������ٶȵ��ڲ���;*/
	
	UInt8		byAwbAutoMode;					//�Զ���ƽ��ģʽ,������ƽ��Ϊ�Զ�ʱ��Ч
	UInt8		byMaxAgc;						//�������ֵ   (�Զ�ģ������)
	UInt16		wExpTimeMax;					//�Զ��ع�������ֵ  
	UInt8		byAntiFog;						//ȥ��
	UInt8       byAntiFalseColor;              //ȥα��
	UInt8       byAntiDIS;                      //ȥ��
	UInt8       byRotate;                       //��ת

	UInt8		byRes[24];
}VIDEO_IN_SENSOR_S,*LPVIDEO_IN_SENSOR_S;


//5����Ƶ���볡��������� size=32+64=96
//CMS_NET:  CMD_GET_VI_SCENE	CMD_SET_VI_SCENE   
typedef struct _VIDEO_IN_SCENE_S
{
	VIDEO_IN_SCENE_E	eValidSupport;		/*��Ч֧�ֵĲ������ò�������ʱ����Ч
											�ڻ�ȡ��ʱ����Ч�������ж��豸�Ƿ�֧�ָò���
											*/

	VIDEO_IN_SCENE_E	eValidSetting;		/*������Ч�Ĳ������ò�����ȡʱ����Ч
											�����õ�ʱ����Ч������ָ���������õĲ���
											*/

	//��Ȧ
	UInt8		byAutoIris;					/*�Զ���Ȧ;		0�Զ�, 1 �ֶ�*/
	UInt8		byIrisLevel;				/*��Ȧ��ƽ;			0 ~ 255*/
	UInt8		byIrisLevelDefault;		/*��Ȧ��ƽȱʡֵ;*/
	UInt8		byIrisLevelStep;			/*��Ȧ��ƽ���ڲ���;*/


	//�۽�
	UInt8		byAutoFocus;				/*�Զ��۽�;		0�Զ�, 1 �ֶ�*/

	UInt8		byFocusLevel;				/*����;				0 �� 255*/
	UInt8		byFocusLevelDefault;		/*����ȱʡֵ;*/
	UInt8		byFocusLevelStep;			/*������ڲ���;*/


	//�䱶
	UInt8		byZoomSpeed;				/*�䱶�ٶ�;		0 ����,  1 �����ٶ�*/
	UInt8		byAutoPtzSpeed;			/*�����������; 0��,   1 ��*/


	//��ƽ����
	UInt8		byAutoAlc;					/*�Զ���ƽ����;	AutoALC	0�Զ� 1 �ֶ�*/

	UInt8		byAlcLevel;					/*��ƽֵ;			ALC Level	0 ~ 255*/
	UInt8		byAlcLevelDefault;			/*��ƽȱʡֵ;		ALC Level	*/
	UInt8		byAlcLevelStep;			/*��ƽֵ���ڲ���;	ALC Level	*/


	//��ת��
	UInt8		byCtb;						/*��ת��;		0��,   1 ��*/


	//����
	UInt8		byScene;					/*����;			0 ~ 255*/
	UInt8		byMirror;					/*����;			0��,   1 ��*/
	UInt8		byFlip;						/*��ת;			0��,   1 ��*/
	UInt8		byAutoFlip;					/*�Զ���ת;		0��,  1 ��*/
	UInt8		byPwdFreq1;					/*����Ƶ��1;	0 60HZ,	1 50HZ*/
	UInt8		byPwdFreq2;					/*����Ƶ��2;	0 60HZ,	1 50HZ,	2 ����*/


	//����
	UInt8		byIRExist;					/*�Ƿ��к���	0��,   1 ��*/
	UInt8		byIRCFMode;					/*IRcfģʽ;		0 OUT=>IN, 1 IN=>OUT*/
	UInt8		byIRLightType;				/*���������;	0 ������,  1 850mm,   2 950mm*/
	UInt8		byWDR;						/*��̬		0��,   1 ��*/
	UInt8		byWDRLevel;					/*��̬		0 ~ 255*/
	UInt8		byLowIllumination;			/*���ն�		1Ĭ��AF
													2���ն�AF�Ż�����
													3���նȵ��ԴAF�Ż�����								
											*/
	UInt8		byImageMode;				/*ͼ��ģʽ		0 ģʽ 1��  1 ģʽ 2 */

	UInt16      u16ViWidth;        		 	/*��Ƶ���� ���*/
	UInt16		u16ViHeight;       			/*��Ƶ���� �߶�*/
	UInt8		byCtbLevel;					/*��ת�ڷ�ֵ���Զ���ת��ʱ��Ч*/
	UInt8		byMinFocusLen;				/*������С�۽�����*/			  
	UInt8		byIRLevel;					/*ҹ�������� */		          
	UInt8 		byLensCorrection; 			/*��ͷУ��	0: ��	1����  */ 
	UInt8       bySmartNR;					//���ܽ���  0 ~ 255 0: �� 
	UInt8       bySmartNRDefault;			//���ܽ���  Ĭ��ֵ 
	UInt8 		by3DNR; 					/*3D ����   0: ��	1����  */  
	UInt8       by3DNRLevel;				//3D����ֵ 
	UInt8		byRes[48];					//
}VIDEO_IN_SCENE_S,*LPVIDEO_IN_SCENE_S;

//6����Ƶ���������ɫ�ʵ��ںͳ�������
//��С196(sizeof(VIDEO_IN_CFG_S))
//CMS_NET:	CMD_GET_VI_CFG		CMD_SET_VI_CFG  

typedef struct _VIDEO_IN_CFG_S
{
	UInt32				dwSize;		    /*�ṹ��С*/
	VIDEO_IN_SENSOR_S	struViSensor;	/*��Ƶ��������*/
	VIDEO_IN_SCENE_S	struViScene;	/*��Ƶ���볡���������*/
}VIDEO_IN_CFG_S,*LPVIDEO_IN_CFG_S;


//7����Ƶ�źŲ���
//CMS_NET:	CMD_GET_VIDEO_SIGNAL_CONFIG 	 CMD_SET_VIDEO_SIGNAL_CONFIG
typedef struct __VIDEO_SIGNAL_CONFIG
{
	UCHAR				ChannelNo;						//ͨ����	0 ~ PORTNUM - 1
	UCHAR 				ChannelNum;						//ͨ����<NVS�ܵ�ͨ��������Ϊ��·����·�Ĳ���Ĭ��ֵ�ǲ�ͬ��>
	UCHAR 				Brightness;						//����
	UCHAR 				Hue;							//ɫ��
	UCHAR 				Saturation;						//���Ͷ�
	UCHAR 				Contrast;						//�Աȶ�
}VIDEO_SIGNAL_CONFIG;


//-------------------------------end------------------------------------


//-----------------------------IV����Ƶ����--------------------------
//1����Ƶ����
//CMS_NET   CMD_ GET_AUDIO_CONFIG  CMD_SET_AUDIO_CONFIG
typedef struct _AUDIO_CONFIG
{
	UCHAR		Open:1;									//��Ƶ�Ƿ��
	UCHAR		MicOrLine:1;							//��Ƶ����ģʽ����˻�������
	UCHAR		resver:6;
	UCHAR		Type;
	UCHAR		AD[2];
				//ѹ����ʽ
	UINT		Bitrate ;								//����
	UINT		SampleBitrate ;
}PACKED AUDIO_CONFIG;
//-------------------------------end------------------------------------

//-----------------------------V����������---------------------------
//1���������ýṹ(�����������������硢pppoe������ DDNS��������������)
//CMS_NET: CMD_GET_NET_CONFIG     CMD_SET_NET_CONFIG

typedef struct _NET_CONFIG
{	
	UINT             	IPAddr ;						//IP��ַ
	UINT             	SubNetMask ;					//����
	UINT             	GateWay ;						//����

   	USHORT             	ComPortNo;						//���ý��տͻ�������˿ں�        UDP	
   	USHORT             	WebPortNo;						//Webserver�˿�     			  TCP
	UINT             	MultiCastIPAddr ;				//�ಥIP��ַ
   	USHORT             	MultiCastPortNo;				//UDP������ʼ�˿�<�ಥ����>
	
	UCHAR			   	RT8139MAC[6];      				//�˹�����������MAC��ַ		5---0��Ч
   	UCHAR             	DHCP;							//DHCP ����					0	��		1:��
   	
	UCHAR             	PppoeOpen;						//PPPOE ����     	
	CHAR				PppoeName[PPPPOE_NAME_LEN+1];	//�����û���
	CHAR				PppoePass[PPPPOE_PASSWD_LEN+1]; //��������	
	UINT             	PppoeTimes;   					//����ʱ��
	UINT             	PppoeIPAddr ;					//PPPOEIP��ַ		�����ش�IP	
	
	UINT				DdnsOpen;						//DDNS����
	CHAR				DdnsName[DDNS_NAME_LEN+1];		//ע����������
	CHAR				DdnsPass[DDNS_PASS_LEN+1];		//ע����������	
	
	CHAR				DdnsIP[DDNS_SERVER_NAME_LEN+1];	//DDNS������
	CHAR				AAD[1];
	USHORT				DdnsPortNo;						//DDNS�������˿�
	USHORT				DdnsMapWebPort;					//����WEBӳ��˿�
	USHORT				DdnsMapDataPort;				//��������ӳ��˿�
	CHAR				ABD[2];

	UINT				DNSHostIP;						//DNS��IP

	INT					ConnectCenter;					//�Ƿ�������������
	CHAR				ConnectCenterIP[DDNS_SERVER_NAME_LEN+1];//����IP
	CHAR				ACD[1];
	USHORT				ConnectCenterPort;						//���Ķ˿�

	USHORT				appFunction;					//ʵ�ֹ��ܶ���,��bitλ��ʾ:0-PPPOE,1-NTP,2-UPNP,3-WF,4-MAIL,5-������
	UCHAR				tcpSendInterval;
	UCHAR				udpSendInterval;
	USHORT				PacketMTU;

	UCHAR				CaptureMode;					//ץ��ģʽ
	UCHAR				CapturePort[MAX_SENSOR_NUM];	//ץ��ͨ��(0-3bit: �ֱ��ʾ1 ~ 4��ͨ��  1:��  0: ��)
	CHAR				AED[1];
	union
	{
	  UINT       		DdnsIP2;						
 	  UINT      		DNSHostIP2;						
	};						//DDNS 2��IP,�������ֽڴ���
	USHORT				DdnsPortNo2;					//DDNS 2�Ķ˿�

	CHAR				sysByname[DVS_NAME_LEN+1];		//����
	UCHAR				domainSetState;					//0���ɹ���1�����ִ��ڣ��޸���������2���������룻3��ʧ��
}PACKED NET_CONFIG;

//2������ WIFI ����
//CMS_NET:  CMD_GET_WFNET    CMD_SET_WFNET
typedef struct _WF_NET_CONFIG
{
	UINT			dwSize;							//��С
	USHORT			wfOpen;							//�Ƿ������
	USHORT			dhcpOpen;						//DHCP����
	//
	UINT			ipAddress;						//IP��ַ
	UINT			subMask;						//��������
	UINT			gateWay;						//����
	UINT			dnsIP1;							//DNS������1 IP
	UINT			dnsIP2;							//DNS������2 IP
	UCHAR			macAddress[6];
	//
	UCHAR			ssidLen;						//SSID���Ƴ���
	UCHAR			pswLen;							//���볤��

	CHAR			ssidName[34];					//SSID����
	CHAR			pswText[34];					//����
	UINT			channel;						//ͨ��
	UINT			bps;
	UINT			type;
	UCHAR			wfAuthType;						//����֤��������
	UCHAR			wfEncType;						//������֤����
	UCHAR			wfPswType;
	CHAR			reserve[9];
}WF_NET_CONFIG;

//3��UPNP  ����
//CMS_NET:	CMD_GET_UPNP   CMD_SET_UPNP

typedef struct _UPNP_CONFIG
{
	USHORT			upnpOpen;						//UPNP����
	UCHAR			upnpEthNo;						//UPNP���� 0�����ߣ�1������
	UCHAR			upnpMode;						//UPNPģʽ 0��ָ����1���Զ�
	USHORT			upnpPortWeb;					//UPNP WEB�˿�
	USHORT			upnpPortData;					//UPNP DATA�˿�
	UINT			upnpHost;						//UPNP����
	USHORT			upnpStatusWeb;					//UPNP WEB״̬
	USHORT			upnpStatusData;				//UPNP DATA״̬
}UPNP_CONFIG;

//4��EMAIL����
//CMS_NET :  CMD_GET_MAIL     CMD_SET_MAIL
typedef struct _MAIL_CONFIG
{
	CHAR			smtpServer[DOMAIN_NAME_LEN];	//���ͷ�����
	CHAR			pop3Server[DOMAIN_NAME_LEN];	//���շ�����
	CHAR			fromMailAddr[DOMAIN_NAME_LEN];	//�ʼ����͵�ַ
	CHAR			toMailAddr[DOMAIN_NAME_LEN];	//�ʼ����յ�ַ
	CHAR			ccMailAddr[DOMAIN_NAME_LEN];	//�ʼ����͵�ַ
	CHAR			smtpUser[DOMAIN_NAME_LEN];		//SMTP �û���
	CHAR			smtpPassword[DOMAIN_NAME_LEN];  //SMTP �û�����
	CHAR			pop3User[DOMAIN_NAME_LEN];		//POP3 �û���
	CHAR			pop3Password[DOMAIN_NAME_LEN];	//POP3 �û�����
		
	UINT			motionMailOpen;					//��Ƶ�ƶ�����MAIL����
	UINT			motionMail[MAX_VIDEO_NUM];		//��Ƶ�ƶ�����ץ�ķ���MAIL����
	UINT			sensorMailOpen;					//̽ͷ��������MAIL����
	UINT			sensorMail[MAX_SENSOR_NUM];		//̽ͷ��������ץ�ķ���MAIL����
	UINT			viloseMailOpen;		

	UINT			timeMailOpen;					//��ʱ����(/��)
	UINT			timeVideoMail[MAX_VIDEO_NUM];	//��Ƶ��ʱץ�ķ���MAIL����
	
	CHAR			subjectMail[EMAIL_TITLE_LEN];	//�ʼ�ͷ
	CHAR			textMail[EMAIL_TITLE_LEN];		//�ʼ�����
		
	UINT			sendMailCount;					//״̬: ���͵�email����	
	UINT			sendNow;						//��������
	USHORT			smtpPort;						//SMTP �˿�
	USHORT			popPort;						//POP3 �˿�
	USHORT			protocolType;					//SSL
	CHAR			res[6];
}MAIL_CONFIG;


//5�� FTP ����������
//CMS_NET: CMD_GET_FTP_CONFIG  CMD_SET_FTP_CONFIG

typedef struct __FTP_CONFIG
{
    char			ftpURL[64];
    char			ftpPath[64];
    UINT			ftpPort;
    char			ftpUser[32];
    char			ftpPsw[32];

    char			ftpURL2[64];
    char			ftpPath2[64];
    UINT			ftpPort2;
    char			ftpUser2[32];
    char			ftpPsw2[32];
	
	USHORT			StartPort;				
	USHORT			EndPort;	
	UCHAR           retransimission;
    char			res[27];
}FTP_CONFIG;


//6��DDNS����
//CMS_NET: CMD_GET_DDNS  CMD_SET_DDNS
typedef struct _DDNS_SET
{
	INT					bDdnsStart;
	CHAR				szDdnsIP[DDNS_SERVER_NAME_LEN+1];
	UINT				dwDdnsPort;
	CHAR				szDdnsName[DVS_NAME_LEN+1];
	UINT				dwMapWebPort;
	UINT				dwMapDataPort;
}PACKED4 DDNS_SET;

//��ý�����  rtsp
typedef struct _MEDIA_SERVER
{
	UCHAR				bRtspOpen; 		//RTSP  ���񿪹�
	UCHAR				bMmsOpen;		//no
	USHORT				rtspPort;		//����RTSP  ����˿�
	UCHAR				bRtspAuth;		//�Ƿ���֤
	UCHAR				bRtspPassive;	//0: ������������  1: �����ȴ��ͻ�������
	USHORT				maxPacketSize;	//RTSP MTU
	UINT				rtspActiveIp;	//��������ʱRTSP��IP��ַ
	USHORT				rtspActiveport;//��������ʱRTSP�Ķ˿�
	USHORT				mmsPort;       //no
}MEDIA_SERVER;


//GPS ����
//CMS_NET: CMD_GET_GPS_CONFIG    CMD_SET_GPS_CONFIG
typedef struct _GPS_INFO
{
	UCHAR		bGpsOpen;
	UCHAR		gpsStatus;
	USHORT		serverPort;
	UINT		serverIP;
	UCHAR		bGpsOSD;
	UCHAR		gpsPlatform;
	UCHAR		phoneNum[11];
	UCHAR       	reportTime;	//ljm 2009-09-25 
	UCHAR		res[2];
	//BYTE		res[3];
}GPS_INFO;


//3G���������ݽṹ
typedef struct _3G_NET_CONFIG_S
{
	unsigned char       nSize;
	unsigned char       n3gOpen;			//3g ����
	unsigned char       n3gType;			//3g ���� 0 evdo 1 wcdma 2 td
	unsigned char       n3gSecType;			//3g ��֤����  0 �Զ�ѡ�� 1 pap 2 chap
	unsigned char       n3gParam;		    //���Ҫ����Щ���� 
	char        		sz3gUsr[32];		//3g �����û���			
	char        		sz3gPsw[32];		//3g ��������
	char        		sz3gApn[32];		//3g apn 
	char        		sz3gTelNum[16];    //3g ���ź���
	char        		sz3gLocalIp[16];
	char        		sz3gRemoteIp[16];
	char        		sz3gPara1[16];
	char        		sz3gPara2[16];
	unsigned char       res[16]; 
}PACKED T3G_NET_CONFIG_S;//200�ֽ�


typedef struct _SS_3G_INFO_S
{
	unsigned char 	  moduleExits;   		// 1 module exits else 0
	unsigned char     moduleStatus;  		// 1 ok else 0
	unsigned char     simExits;      		// 1 umi exits  else 0
	unsigned char     sigal;         		// 
	unsigned char     serviceStatus; 		// srv status 
	// 0 no srv status
	// 1 a restrict srv status
	// 2 a good srv
	// 3 a restrict district srv
	// 4 sleep status
	unsigned char     roamStatus;    		// 0 not roam 1 roam
	unsigned char     networkType ;  	    // 0 not service
	// 1 AMPS
	// 2 CDMA
	// 3 GSM/GPRS
	// 4 HDR
	// 5 WCDMA
	// 6 GPS
	// 7 GSM/WCDMA
	// 8 CDMA/HDR HYBIRD
	unsigned char     refresh      ;
	unsigned char     initModule   ;
	unsigned char     initDail	   ;
	unsigned char	  c3gstatus	   ;		// 3G״̬
	unsigned char     res          ;		// ����ʧ�ܴ���,���Բ�ʹ��
	char      		  softWareVer[128];   	// software version
	char      		  hardWareVer[128];  	// hardware version
	char      		  moduleType[32] ;   	// module type
}PACKED SS_3G_INFO_S, *PSS_3G_INFO_S;

//3G  ʱ��
typedef struct _T3G_TIME_CTRL_S// 20101125 �ṹ����,ʵ���ֽڶ���
{
	BYTE		t3gtimectrlopen;		// 3G������ʱ�Ƿ��� 0-�ر�  1-����
	BYTE		t3gdaylimitedend;		// ��־λ-ÿ����ʱ����     0-δ��  1-�ѵ�
	BYTE		t3gmonthlimitedend;		// ��־λ-ÿ����ʱ����   0-δ��  1-�ѵ�
	BYTE		t3gdaylimited;			// ����ÿ�첦��ʱ��   0-������
	T3G_TIME_CTRL_MODE	t3gtimectrlmode;// 3Gʱ������ģʽ
	DWORD		t3gdialusedtime;		// �Ѿ�����ʱ��
	DWORD		t3gmonthlimited;		// ����ÿ�²���ʱ��   0-������
	BYTE		t3openlimitedmonth;		// �����趨��ʱ���·�
	BYTE		t3openlimitedday;// �����趨��ʱ�ĺ���
	BYTE		revers[2];// �ֽڶ���
	TIME_SEGMENT_NEW	t3gtimesegment[4];// ����ÿ��4�����趨ʱ���
}PACKED T3G_TIME_CTRL_S;// 50���ֽ� = 1+4+4+1+1+1+4+1+1+4*(4+4)


//7��3G �ܲ���
//CMS_NET  CMD_GET_3G_CONFIG   CMD_SET_3G_CONFIG
typedef struct _T3Ginfo_S
{
	T3G_NET_CONFIG_S  t_3ginfo;
	T3G_TIME_CTRL_S   t_3gTime;
	SS_3G_INFO_S	  t_3ginfo1;
}T3Ginfo_S;

//---------------------------end-----------------------------------------



//----------------------------------VI���洢����-------------------------------

//1��������Ϣ
//1��CMS_NET:  CMD_GET_DISK_INFO   
typedef struct _DISK_INFO
{
	UINT	DiskNum;						//���̸���
	UCHAR	DiskType[8];					//��������
	UINT	TotalSize[8];					//�����ܿռ��С
	UINT	FreeSize[8];					//����ʣ��ռ�
	UCHAR	Reserved[8];					//BYTE	Reserved[4];	2008.9.23
}DISK_INFO;

//2�����̲���
typedef struct _DISK_MANAGE
{
	UCHAR	Cmd;
	UCHAR	Data;
	UCHAR	Reserved[126];
}DISK_MANAGE;

//3�����̸�ʽ������
typedef struct _DISK_FORMAT_PROCESS
{
	UINT	DiskType;							//��������
	UINT	Status;								//��ʽ��״̬
	UINT	Process;							//����()
	UINT	Reserved[5];
}DISK_FORMAT_PROCESS;

//��ʱ¼��
typedef struct _CH_TIMER_RECORD_CONFIG		//sizeof() = 140
{
	USHORT					KeepTime;			//��������(��)
	USHORT					RecordSvaeMode;	//bit0 ���ش洢  bit1 ftp�ϴ�  bit2 email
	UINT					reserve[2];

	TIME_SEGMENT_NEW		tSchTable1[8] ;		//ĳ��ͨ���Ķ�ʱ¼��ʱ���1 (64)
	TIME_SEGMENT_NEW		tSchTable2[8] ;		//ĳ��ͨ���Ķ�ʱ¼��ʱ���2 (64)
}CH_TIMER_RECORD_CONFIG;	


//4��¼��ƻ�
//CMS_NET : CMD_SET_RECORD_CONFIG				CMD_GET_RECORD_CONFIG	(unsupport)
typedef struct _TIMER_RECORD_CONFIG			//sizeof() = 592
{
	UCHAR					PackageTime;	  						//���ʱ��(����)
	UCHAR 					OverWrite;        						//�Զ�����
	UCHAR     				MainVEnc;								//¼����� 0: ������  1: ������
	UCHAR     				CheckDisk;								//ϵͳ����ʱ���д���ɨ��
	USHORT					nSaveDays;	
	UCHAR     				reserve[24];

	CH_TIMER_RECORD_CONFIG	ChRecordCfg[MAX_VIDEO_NUM];				//ͨ����¼�����(140 * 4 = 560)
}TIMER_RECORD_CONFIG;


//��ʱץ��
typedef struct _CH_TIMER_SHOOT_CONFIG		//sizeof() = 140
{
	USHORT 					KeepTime;								//��������(��)
	USHORT					ShootSaveMode;							//bit0 ���ش洢  bit1 ftp�ϴ�  bit2 email

	UINT					ShootNum;								//����ץ������()
	float					ShootInterval;							//����ץ��ʱ����(��)  0: ����ץ��

	TIME_SEGMENT_NEW		tSchTable1[8] ;							//ĳ��ͨ���Ķ�ʱץ��ʱ���1 (40)
	TIME_SEGMENT_NEW		tSchTable2[8] ;							//ĳ��ͨ���Ķ�ʱץ��ʱ���2 (40)
}CH_TIMER_SHOOT_CONFIG;

//5��ץ�ļƻ�
//CMS_NET: CMD_GET_SHOOT_CONFIG   CMD_SET_SHOOT_CONFIG
typedef struct _TIMER_SHOOT_CONFIG			//sizeof() = 592
{
	UCHAR 					OverWrite;								//�Զ�����
	UCHAR     				reserve[31];

	CH_TIMER_SHOOT_CONFIG	ChShootCfg[MAX_VIDEO_NUM];				//ͨ����¼�����(92 * 4 = 368)
}TIMER_SHOOT_CONFIG;

//------------------------------------end------------------------------------------


//----------------------------------VII����������-----------------------------
//������������
typedef struct _ALARM_LINKAGE 
{
	UINT 		Output;						//�����������				     bit.0---bit.3	
	UINT 		AutoClearTime;		        //�����Զ����ʱ��	

	UINT 		Record_PC;					//PC�˱�������¼��ͨ��			 bit.0---bit.3
	UINT 		Record_Dev;					//�豸�˱�������¼��ͨ��		 bit.0---bit.3
	UINT		RecordSvaeMode;				//bit0 ���ش洢  bit1 ftp�ϴ�  bit2 email
	UINT		RecordTime;					//����¼��ʱ��(��)

	UINT		ShootSaveMode;				//bit0 ���ش洢  bit1 ftp�ϴ�  bit2 email
	UINT		ShootChns;					//ץ��ͨ��(bit.0 ~ bit.3)
	UINT		ShootNum;					//����ץ������()
	float		ShootInterval;				//����ץ��ʱ����(��)  0: ����ץ��

	UINT		EMail;						//����email
	UINT		Reserved;					//����
} ALARM_LINKAGE;

//1���ƶ��������
//CMS_NET: CMD_GET_VMOTION_CONFIG_NEW  CMD_SET_VMOTION_CONFIG_NEW
typedef struct _VIDEOMOTION_CONFIG_NEW
{
	UINT			dwSize;						//���ṹ����

	UINT 			DetectLevel;			    //�ƶ����������
	UINT 			DetectOpen;				    //�ƶ���⿪��

	AREA_RECT		DetectArea[9];				//�ƶ��������			

	TIME_SEGMENT_NEW  tSchTable1[8] ;		    //�ƶ����ʱ���1				 0: ÿ��
	TIME_SEGMENT_NEW  tSchTable2[8] ;		    //�ƶ����ʱ���1				 0: ÿ��

	ALARM_LINKAGE	stAlarmLink;				//��������

	UCHAR			reseved[128];
}VIDEOMOTION_CONFIG_NEW ;


//2��̽ͷ�����������
//CMS_NET: CMD_GET_SENSOR_ALARM_NEW 	CMD_SET_SENSOR_ALARM_NEW

typedef struct _SENSOR_CONFIG_NEW 
{
	UINT				dwSize;						//���ṹ����

	UINT				SensorType;					//0:����̽ͷ	1:����̽ͷ
	UINT 				DetectOpen;				    //��⿪��

	TIME_SEGMENT_NEW  	tSchTable1[8] ;		    	//̽ͷ���ʱ��1				     0: ÿ��
	TIME_SEGMENT_NEW 	tSchTable2[8] ;		    	//̽ͷ���ʱ��1				     0: ÿ��

	ALARM_LINKAGE		stAlarmLink;				//��������

	UCHAR				reseved[32];
}SENSOR_CONFIG_NEW;


//3��������߱�������
//CMS_NET: CMD_GET_NET_ALARM_CONFIG  CMD_SET_NET_ALARM_CONFIG

typedef struct _NET_ALARM_CONFIG 
{
	UINT			dwSize;						//���ṹ����

	UINT 			DetectOpen;				    //��⿪��
	
	ALARM_LINKAGE	stAlarmLink;				//��������

	UCHAR			reseved[32];
} NET_ALARM_CONFIG;


//4����Ƶ��ʧ����
//CMS_NET:	CMD_GET_VLOST_CONFIG_NEW  CMD_SET_VLOST_CONFIG_NEW
typedef struct _VIDEOLOSE_CONFIG_NEW
{
	UINT			dwSize;						//���ṹ����

	UINT			DetectOpen;					//��Ƶ��ʧ���

	ALARM_LINKAGE	stAlarmLink;				//��������

	UCHAR			reseved[32];
} VIDEOLOSE_CONFIG_NEW;



//����̽ͷ���� (��֧��)
typedef struct _RF_ALARM_CONFIG
{
	UINT			dwSize;						//���ṹ����

	UINT			SensorType;					//0:����̽ͷ	1:����̽ͷ
	UINT 			DetectOpen;				    //��⿪��

	TIME_SEGMENT_NEW  tSchTable1[8] ;		    //̽ͷ���ʱ��1				     0: ÿ��
	TIME_SEGMENT_NEW  tSchTable2[8] ;		    //̽ͷ���ʱ��1				     0: ÿ��

	ALARM_LINKAGE	stAlarmLink;				//��������

	UCHAR			reseved[32];
}RF_ALARM_CONFIG;


//5������̵�������
//CMS_NET:	CMD_SET_OUTPUT_CTRL
typedef struct __OUTPUT_CTRL
{
	UCHAR				ChannelNo;						//�̵�����	0 ~ MAX_OUTPUT_NUM - 1
	UCHAR				Status;							//0����		1: ��	
}OUTPUT_CTRL;

//
typedef struct _ALARM_INOUT_NAME
{
	CHAR			alarmInName[MAX_SENSOR_NUM][CAM_TITLE_LEN+2];	//̽ͷ��
	CHAR			alarmOutName[MAX_OUTPUT_NUM][CAM_TITLE_LEN+2];	//���������
}ALARM_INOUT_NAME;



typedef  struct  _ALARM_INFO
{
	UCHAR	SensorAlarm[MAX_SENSOR_NUM];				//̽ͷ����
	UCHAR	SensorAlarmOut[MAX_SENSOR_NUM];				//̽ͷ�������
	UCHAR	MotionAlarm[MAX_VIDEO_NUM];					//��Ƶ�ƶ�
	UCHAR	MotionAlarmOut[MAX_VIDEO_NUM];				//��Ƶ�ƶ��������
	UCHAR	ViLoseAlarm[MAX_VIDEO_NUM];					//��Ƶ��ʧ
	UCHAR	ViLoseAlarmOut[MAX_VIDEO_NUM];				//��Ƶ��ʧ�������
} ALARM_INFO;








//----------------------------------end--------------------------------------------



//---------------------------------VIII����������--------------------------------

//1����������
//CMS_NET:  CMD_GET_COM_CONFIG    CMD_SET_COM_CONFIG
typedef struct __COM_CONFIG
{
	UINT 				Baudrate;						//���ڲ�����				300---115200
	UCHAR				Databit;						//��������λ����			5=5λ 6=6λ 7=7λ 8=8λ	����=8λ
	UCHAR				Stopbit;						//ֹͣλλ��				1=1λ 2=2λ ����=1λ
	UCHAR				CheckType;						//У��						0=��  1=��  2=ż  3=��1  4=��0 
	UCHAR				Flowctrl; 						//������/Ӳ����/������		����
}COM_CONFIG;


//----------------------------------��̨-------------------------------------
typedef struct _SERIAL_PROTOCOL_S
{
	ULONG			baudrate : 20;						//������(bps) 300 ~ 115200
	ULONG			dataBits : 4;						//�����м�λ  5: 5λ 6: 6λ 7: 7λ 8: 8λ
	ULONG			stopBits : 2;						//ֹͣλ:     1: 1λ 2: 2λ
	ULONG			parity   : 3;						//У��        0: ��  1: ��  2:ż   3: ��1  4:��0 
	ULONG			flowControl : 2;					//����        0: ��  1: ������     2:Ӳ����
}SERIAL_PROTOCOL_S;


typedef struct _DEV_SERIAL_CHN_S
{
	UINT				dwSize;
	UINT				bExist;							//�Ƿ����: ֻ��
	CHAR				szName[64];	
	SERIAL_PROTOCOL_S	stSerialProtocol;
	UCHAR				byRes[16];
}DEV_SERIAL_CHN_S;


//1��͸��ͨѶ
//CMS_NET : CMD_SET_COMM_SENDDATA
typedef struct __COMM_CTRL
{
	UCHAR				COMMNo;							//���ں�	0 ~ 1
	UCHAR				AD[3];
	
	DEV_SERIAL_CHN_S	COMConfig;						//��������
	USHORT				DataLength;						//���ݳ���
	UCHAR				Data[256];						//����
	UCHAR				AE[2];
}PACKED COMM_CTRL;

//2����̨����
//CMS_NET: CMD_SET_PAN_CTRL
typedef struct __PAN_CTRL
{
	UCHAR				ChannelNo;						//ͨ����	0 ~ PORTNUM - 1
	UCHAR				COMMNo;							//���ں�	0 ~ 1
	UCHAR				PanType;						//��̨Э����� 0 ~ YUNTAI_PROTOCOL_NUM - 1
	UCHAR				PanCmd;							//��̨��������
	UCHAR				Data1;							//����1		��Ԥ�á����úţ�
	UCHAR				Data2;							//����2		�����ã�
}PAN_CTRL;

//3����̨��Ϣ
//CMS_NET:  CMD_GET_YUNTAI_CONFIG
typedef struct _YUNTAI_INFO
{
	CHAR 		Name[YUNTAI_NAME_LEN + 1];				//��̨����
	CHAR 		AD[3];
	COM_CONFIG	ComSet;									//ͨѶЭ��<������...>
}PACKED YUNTAI_INFO;

//------------------------------end---------------------------------


//----------------------------IX����������-----------------------

//1��TW2824����
//CMS_NET: CMD_SET_TW2824
typedef struct _TW2824_CTRL
{
	UCHAR				Page;							//ҳ
	UCHAR 				RegNo;							//�Ĵ���
	UCHAR 				Data;							//����
	UCHAR				AD[1];
	UINT				nReserved[8];					//����
}TW2824_CTRL;

typedef struct _COMM_DATA_NOTIFY
{
	HANDLE					hLogonServer;
	UINT					dwClientID;
	UINT					dwServerIP;
	UINT					dwServerPort;
	COMM_CTRL				commCtrl;
}COMM_DATA_NOTIFY;


//2��������Ϣ����
typedef struct _DEBUG_CONFIG
{
	UCHAR				Status;							//0����		1: ��
}DEBUG_CONFIG;


//3����־��ѯ
//CMD_FING_LOG
typedef struct _FIND_LOG_S
{
	UINT		nSize;					//�ṹ��С
	UINT		nSelectMode;			//��ѯ��ʽ:0��ȫ����1�������ͣ�2����ʱ�䣬3����ʱ�������
	UINT		nType;					//��������
    DVS_TIME	stStartTime;
	DVS_TIME	stEndTime;
}FIND_LOG_S;

typedef struct _LOG_ITEM_S
{
	UINT		nSize;					//�ṹ��С
	UINT		nAlarmType;				//��������
	UINT        nChn;					//ͨ���š����߱�����IP��ַ
	DVS_TIME	tAlarmTime;	
	char		szNote[12];
}LOG_ITEM_S;



//4����¼���û��û���Ϣ

typedef struct _USER_DETAIL
{
	INT					bLogon;							//TRUE-��½�û�,FALSE-Ԥ���û�
	UINT 				Level;							//Ȩ��
	CHAR 				Name[USER_NAME_LEN+1];			//�û���
	CHAR 				Password[USER_PASSWD_LEN+1];	//�û�����
	NET_PROTOCOL_TYPE	protocolType;					//Э��
	UINT				clientIP;						//IP
	UINT				clientPort;						//�˿�
}PACKED4 USER_DETAIL;

typedef struct _USER_INFO
{
	UINT				dwLogonNum;
	UINT				dwPreviewNum;
	USER_DETAIL			userDetail[MAX_LOGON_NUM+MAX_LINKVIEW_NUM+MAX_MULTIVIEW_NUM];
}PACKED4 USER_INFO;


//��Ƶ����������
typedef struct _SEND_DEST
{	
	UINT			dwSet[MAX_VIDEO_NUM];			//���Ϳ���
	UINT			dwStreamSend[MAX_VIDEO_NUM];	//���Ϳ���
	UINT			dwStreamDestIP[MAX_VIDEO_NUM];	//Ŀ��IP,�����ֽ�˳��
	UINT			dwStreamDestPort[MAX_VIDEO_NUM];//Ŀ�Ķ˿�
	CHAR			res[16];
}SEND_DEST;
//�Զ�����ע��
typedef struct _AUTO_RESET_TIME
{
	UCHAR			open;				//bit 1:hour,bit 2:day,bit 3:week	
	UCHAR			second;
	UCHAR			minute;
	UCHAR			hour;
	UCHAR			week;				//0 �����գ�1 ����һ��2 ���ڶ� 

	UCHAR			res[3];
}AUTO_RESET_TIME;


//5, ��չ��Ϣ�ṹ(�޸Ķ��壬 ��С��ԭ�ṹ��ͬ�� ��������Ҳ��ͬ)
//CMS_NET: CMD_GET_EXTINFO   CMD_SET_EXTINFO

typedef struct _EXTINFO_CONFIG_NEW
{
	UINT				nSize;					//�ṹ��С(1328)

	NTP_CONFIG			ntpConfig;				//ntp
	
	UPNP_CONFIG			upnpConfig;				//upnp
		
	MAIL_CONFIG			mailConfig;				//MAIL
	
	ALARM_INOUT_NAME	alarmInOutName;		//ALARM IN/OUT NAME
	
	WF_NET_CONFIG		wfConfig;				//WF NETWORK
	
	SEND_DEST			sendDest;				//SEND DEST
	
	AUTO_RESET_TIME		autoResetTime;			//AUTO RESET 

	FTP_CONFIG			ftpCfg;					//FTP ����������

	MEDIA_SERVER		mediaServer;			//��ý�����

	GPS_INFO			gpsInfo;				//GPS ��Ϣ,

	UCHAR               reportWanIp;            //�����ϱ�����IP��ַ
	UCHAR               reportIpInterval;       //
	char				reserve[6];			

	//char				reserve[16];  
	//char				reserve[40];  
}EXTINFO_CONFIG_NEW;


//�û�����
typedef struct __USERDATA_CONFIG
{
	int		nDataLen;
	char	userData[252];
}USERDATA_CONFIG;


//6, �豸���в�����sizeof = 10248��
//CMS_NET: CMD_GET_ALL_CONFIGPARAM

typedef struct _DVS_Parameter_ST
{
	UINT						dwSize;						//���ṹ����

    char                		sysName[DVS_NAME_LEN + 4];

	UCHAR						sysInputNum;		        //·��
	UCHAR						sysType;			        //�����ͺ�	0:CIF  1:HD1  2:D1  
	UCHAR						sysVideoFormat;		        //�����ʽ	0:D1,1:HD1,2:CIF,3:VGA 4:HVGA 5:CVGA 6:QCIF 7:QVGA
    UCHAR						sysLanguage;		        //����

    UINT						sysStandard;		        //��ʽ		0:PAL  1:NTSC

    UINT      					sysID;  	            //ÿ̨�����и�ID
	UINT      					sysVer;  	            //����汾  

	VIDEO_CONFIG_NEW	    	sysVideo[MAX_VIDEO_NUM];	
	VIDEOMOTION_CONFIG_NEW		sysVideoMotion[MAX_VIDEO_NUM];
	VIDEOMASK_CONFIG_NEW    	sysVideoMask[MAX_VIDEO_NUM];	
	VIDEOLOSE_CONFIG_NEW    	sysVideoLose[MAX_VIDEO_NUM];	
	AUDIO_CONFIG		    	sysAudio[MAX_AUDIO_NUM];
	NET_CONFIG					sysNet;
	COM_CONFIG					sysCom[MAX_COM_NUM];
	SENSOR_CONFIG_NEW	   	 	sysSensor[MAX_SENSOR_NUM];
	USER_CONFIG					sysUser[MAX_USER_NUM];

    EXTINFO_CONFIG_NEW			sysExtConfig;				//��չ����

	DISK_INFO					DiskInfo;					//�洢�豸��Ϣ

	TIMER_RECORD_CONFIG			TimerRecordCfg;
	TIMER_SHOOT_CONFIG			TimerShootCfg;				//��ʱץ�Ĳ���

	RF_ALARM_CONFIG				rfAlarmCfg[MAX_RF_SENSOR_NUM];	//����̽ͷ����
	NET_ALARM_CONFIG			netAlarmCfg;					//������߱���

	USERDATA_CONFIG				userData;					//�û�����

	UINT						YunTaiProtocolNum;
	YUNTAI_INFO 				YunTaiInfo[MAX_PTZ_PROTOCOL_NUM];	

	UCHAR						reserved[256];				//����

} DVS_Parameter_New;


/*
typedef struct _DVS_Parameter_New
{
	UINT					dwSize;						//���ṹ����
    char                    sysName[DVS_NAME_LEN + 4];
	UCHAR					sysInputNum;		        //·��
	UCHAR					sysType;			        //�����ͺ�	0:CIF  1:HD1  2:D1  
	UCHAR					sysVideoFormat;		        //�����ʽ	0:D1,1:HD1,2:CIF,3:VGA 4:HVGA 5:CVGA 6:QCIF 7:QVGA
    UCHAR					sysLanguage;		        //����
    UINT					sysStandard;		        //��ʽ		0:PAL  1:NTSC
    UINT      				sysID;  	                //ÿ̨�����и�ID
	UINT      				sysVer;  	                //����汾  s
	VIDEO_CONFIG_NEW	    sysVideo[MAX_VIDEO_NUM];	
	VIDEOMOTION_CONFIG_NEW	sysVideoMotion[MAX_VIDEO_NUM];
	VIDEOMASK_CONFIG_NEW    sysVideoMask[MAX_VIDEO_NUM];	
	VIDEOLOSE_CONFIG_NEW    sysVideoLose[MAX_VIDEO_NUM];	
	AUDIO_CONFIG		    sysAudio[MAX_AUDIO_NUM];
	NET_CONFIG			    sysNet;
	COM_CONFIG			    sysCom[MAX_COM_NUM];
	SENSOR_CONFIG_NEW	    sysSensor[MAX_SENSOR_NUM];
	USER_CONFIG			    sysUser[MAX_USER_NUM];

    EXTINFO_CONFIG_NEW		sysExtConfig;				//��չ����
	DISK_INFO				DiskInfo;					//�洢�豸��Ϣ
	TIMER_RECORD_CONFIG		TimerRecordCfg;
	TIMER_SHOOT_CONFIG		TimerShootCfg;				//��ʱץ�Ĳ���
	RF_ALARM_CONFIG			rfAlarmCfg[MAX_RF_SENSOR_NUM];	//����̽ͷ����
	NET_ALARM_CONFIG		netAlarmCfg;					//������߱���
	USERDATA_CONFIG			userData;					//�û�����
	UINT					YunTaiProtocolNum;
	YUNTAI_INFO 			YunTaiInfo[MAX_PTZ_PROTOCOL_NUM];	
	UCHAR					reserved[256];				//����

} DVS_Parameter_New;

*/
//=======================================
//������չ����(��ƽ̨������������)
//=======================================
typedef struct __EXT_DATA_CONFIG
{
	UINT		nSize;					//�ṹ��С
	UINT		nType;	
       UINT		nDataLen;
    char		szData[512];
}EXT_DATA_CONFIG;



//����1
typedef struct _CONFIG_ENCPAR
{ 
    UINT u32PicWidth;   
    UINT u32PicHeight;     
    UINT u32CapSel; 
    UINT u32StaticParam; 
    UINT u32TargetBitrate; 
    UINT u32TargetFramerate; 
    UINT u32Gop;             
    UINT u32MaxQP;        
    UINT u32PreferFrameRate; 
    UINT u32Strategy; 
    UINT u32VencMode;        
    UINT u32BaseQP;         
    UINT u32MaxBitRate;   
}CONFIG_ENCPAR; 

//����2
typedef struct _PING_CONFIG
{
	BOOL	bPingOpen;
	BOOL	bDisconnectReboot;
	BOOL	bDisconnectAlarm;
	UINT	dwPingNum;
	UINT   dwPingPeriod;
	char	szPingServer[64];
}PING_CONFIG;

//---------------------------end------------------------------------




/**************************** ********************************************
						 �ġ��������������ýṹ
**************************************************************************/

//---------------------------------------------------------//
//1��ϵͳʱ��
typedef  struct  _DD_NVD_DATE
{
	UCHAR		year;									//��
	UCHAR		month;									//��
	UCHAR		day;									//��
	UCHAR		week;									//��
	UCHAR		hour;									//Сʱ
	UCHAR		minute;									//��
	UCHAR		second;									//��
}DD_NVD_DATE, *PDD_NVD_DATE;

//2��ϵͳ����
typedef struct _DD_SYSTEM_PARAM 
{
   	CHAR               	Name[DVS_NAME_LEN + 1];			//����
	UCHAR				Type;							//�����ͺ�	0:CIF  1:HD1  2:D1  
    UCHAR				Language;						//����
    UCHAR				Standard;						//��ʽ		0:PAL  1:NTSC
	UINT      			ID;  	        				//ÿ̨�����и�ID��  	
	UINT      			RS485Addr;       				//RS485��ַ  		
	UINT      			RS485Func;       				//RS485����  			
	UINT      			RS485Baud;       				//RS485������  			
	UINT      			Version;         				//����汾  
	UCHAR      			RemoteID;         				//ң��ID��  	
	UCHAR				Audio;							//��������	
	UCHAR				TimeOn;							//ʱ����ʾ����				
	UCHAR				DispMode;						//��ʾģʽ(1�����桢4�Ļ���)
	UCHAR				ImageQulity;					//����ͼ������
	UCHAR				Reserve[31];					//����
}PACKED DD_SYSTEM_PARAM;

//3���������
typedef struct _DD_NET_CONFIG
{
	UINT             	IPAddr ;						//IP��ַ
	UINT             	SubNetMask ;					//����
	UINT             	GateWay ;						//����

   	USHORT             	ComPortNo;						//���ý��տͻ�������˿ں�        UDP	
   	USHORT             	WebPortNo;						//Webserver�˿�     			  TCP
	UINT             	MultiCastIPAddr ;				//�ಥIP��ַ
   	USHORT             	MultiCastPortNo;				//UDP������ʼ�˿�<�ಥ����>
	
	UCHAR			   	RT8139MAC[6];      				//�˹�����������MAC��ַ		5---0��Ч
   	UCHAR             	DHCP;							//DHCP ����					0	��		1:��
	UCHAR				AD[1];
	
   	USHORT             	PppoeOpen;						//PPPOE ����         	
	UINT             	PppoeIPAddr ;					//PPPOEIP��ַ �������ش�IP��
	CHAR				PppoeName[PPPPOE_NAME_LEN+1];	//�����û���
	CHAR				PppoePass[PPPPOE_PASSWD_LEN+1];	//��������		
	CHAR				ADD[2];	
	UINT				DdnsOpen;						//DDNS����
	CHAR				DdnsName[DDNS_NAME_LEN+1];		//ע����������
	CHAR				DdnsPass[DDNS_PASS_LEN+1];		//ע����������	

	
	CHAR				DdnsIP[DDNS_SERVER_NAME_LEN+1];	//DDNS������
	CHAR				ASD[1];
	
	USHORT				DdnsPortNo;						//DDNS�������˿�
	USHORT				DdnsMapWebPort;					//����WEBӳ��˿�
	USHORT				DdnsMapDataPort;				//��������ӳ��˿�
	CHAR				ASDD[2];

	UINT				DNSHostIP;						//DNS��IP
	INT				ConnectCenter;					//�Ƿ�������������
	CHAR				ConnectCenterIP[DDNS_SERVER_NAME_LEN+1];//����IP
	CHAR				AAD[1];
	
	USHORT				ConnectCenterPort;						//���Ķ˿�

	USHORT				appFunction;					//fix me
	UCHAR				tcpSendInterval;
	UCHAR				udpSendInterval;
	USHORT				PacketMTU;

	UCHAR				CaptureMode;					//ץ��ģʽ
	UCHAR				CapturePort[MAX_SENSOR_NUM];	//ץ��ͨ��(0-3bit: �ֱ��ʾ1 ~ 4��ͨ��  1:��  0: ��)

	UINT				DdnsIP2;						//DDNS 2��IP,�������ֽڴ���
	USHORT				DdnsPortNo2;					//DDNS 2�Ķ˿�

	CHAR				sysByname[DVS_NAME_LEN+1];		//����
	UCHAR				NetReserve[1];					//����
} PACKED DD_NET_CONFIG ;

//4����������
typedef struct __DD_COM_PARAM
{
	UINT 				Baudrate;						//���ڲ�����				300---115200
	UCHAR				Databit;						//��������λ����			5=5λ 6=6λ 7=7λ 8=8λ	����=8λ
	UCHAR				Stopbit;						//ֹͣλλ��				1=1λ 2=2λ ����=1λ
	UCHAR				CheckType;						//У��						0=��  1=��  2=ż  3=��1  4=��0 
	UCHAR				Flowctrl; 						//������/Ӳ����/������		����
}PACKED DD_COM_CONFIG;


//5��ͼ�����
typedef struct _DD_IMAGE_PARAM
{
	UCHAR 	Bright;										// ����
	UCHAR 	Shades;										// ɫ��
	UCHAR 	Contrast;									// �Աȶ�
	UCHAR 	Saturate;									// ���Ͷ�
	UCHAR 	MenuBright;									// �˵�����
}PACKED DD_IMAGE_CONFIG;

//6����������
typedef struct __DD_ALARMOUT_PARAM
{
	UCHAR 				Open;							//��������<0: ��  1: ��>
	UCHAR				SensorAlarm[4];					//̽ͷ��������	.0 ~ 3 1--4��̽ͷ	0,1λ: �ֱ��ʾ�̵���1 2��״̬  <0: ��  1: ��>
	UCHAR				MotionAlarm[4];					//��Ƶ�ƶ�����	.0 ~ 3 1--4��̽ͷ	0,1λ: �ֱ��ʾ�̵���1 2��״̬  <0: ��  1: ��>
	UCHAR				ViLoseAlarm[4];					//��Ƶ��ʧ����	.0 ~ 3 1--4��̽ͷ	0,1λ: �ֱ��ʾ�̵���1 2��״̬  <0: ��  1: ��>
	UCHAR				Reserve[8];						//����	
}PACKED DD_ALARMOUT_CONFIG;


//7���û�����
typedef struct _DD_USER_CONFIG
{
	UINT 		Level;									//Ȩ��
	CHAR 		Name[17];				//�û���
	CHAR 		Password[17];			//�û�����
	CHAR 		AD[2];
}PACKED DD_USER_CONFIG;


//8��������Ϣ��Ŀ
typedef struct __DD_ALARM_ITEM
{
	UINT 				IPAddr;							//IP
	CHAR				URL[DD_URL_ADDR_LEN + 1];		//URL��ַ
	CHAR				AVD[3];
	UINT				ComPortNo;						//ͨѶ�˿�
	DD_NVD_DATE			AlarmTime;						//����ʱ��
	UCHAR				SensorAlarm;					//̽ͷ��������	.0 ~ 3 1--4��̽ͷ	<0: �ޱ���  1: �б���>
	UCHAR				MotionAlarm;					//��Ƶ�ƶ�����	.0 ~ 3 1--4����Ƶ	<0: �ޱ���  1: �б���>
	UCHAR				ViLoseAlarm;					//��Ƶ��ʧ����	.0 ~ 3 1--4����Ƶ	<0: �ޱ���  1: �б���>
	UCHAR				Reserve[8];						//����
	CHAR				AD[2];
}PACKED DD_ALARM_ITEM;


//9��������Ϣ��¼
typedef struct __DD_ALARM_INFO
{
	USHORT				Count;							//������¼����
	CHAR				AD[2];
	DD_ALARM_ITEM		Alarms[DD_MAX_ALARMINFO_NUM];	//������¼����
}PACKED DD_ALARM_INFO;


//10����ַ��
typedef struct __DD_ADDRBOOK_PARAM
{
	CHAR				Name[DDNS_NAME_LEN + 1];			//����
	CHAR				URL[DD_URL_ADDR_LEN + 1];		//URL��ַ
	USHORT             	ComPortNo;						//ͨѶ�˿�
	UCHAR				ChannelNo;						//ͨ����
	UCHAR				Protocol;						//0: TCP  1:�ಥ   2:UDP
	UCHAR				DNSOpen;						//0: ��   1:��
	UCHAR				AD;
	USHORT				StayTime;						//ͣ��ʱ��	5--3600��
	UCHAR				AutoLink;						//�Զ�����	0:��  1:��
	UCHAR				AudioOpen;						//������	0:��  1:��	
	UCHAR				TalkOpen;						//�Խ���	0:��  1:��
	CHAR				UserName[USER_NAME_LEN + 1];	//�û���
	CHAR				UserPass[USER_PASSWD_LEN + 1];	//�û�����	
	UCHAR				Reserve[8];						//����	
	UCHAR				AD2;
}PACKED DD_ADDRBOOK_CONFIG;


//11��͸��ͨѶ
typedef struct __DD_COMM_CTRL
{
	UCHAR				COMMNo;							//���ں�	0 ~ 1
	UCHAR				ADG[3];
	COM_CONFIG			COMConfig;						//��������
	USHORT				DataLength;						//���ݳ���
	UCHAR				Data[256];						//����
	UCHAR				AD[2];
}PACKED DD_COMM_CTRL;


//12��������������ṹ
typedef struct __DD_DEVICE_CTRL
{
	UCHAR				CMD;							//����
	UCHAR 				Data1;							//����1
	UCHAR 				Data2;							//����2
	UCHAR				AD[1];
	UINT				nReserved[8];					//����
}PACKED DD_DEVICE_CTRL;


//13����̨��Ϣ
typedef struct _DD_PROTOCOL_INFO
{
	CHAR 		Name[YUNTAI_NAME_LEN + 1];				//��̨����
	UCHAR		Exist;									//�Ƿ����
	UCHAR		nReserved[8];							//����
}PACKED DD_PROTOCOL_INFO;

//14����̨����

typedef struct _DD_YUNTAI_SET
{
	CHAR 		Name[YUNTAI_NAME_LEN + 1];				//��̨����
	UCHAR 		YTAddr;									//��������ַ
	UCHAR		AD[2];
	COM_CONFIG	ComSet;									//ͨѶЭ��<������...>
	
	UCHAR		nReserved[8];							//����
}PACKED DD_YUNTAI_SET;


//15��ϵͳ���в���(�������ò��������紫����)

typedef struct _DD_NVD_CONFIG 
{
	DD_SYSTEM_PARAM 		sysParam;					//ϵͳ����
	DD_NET_CONFIG			sysNet;						//��������
	DD_COM_CONFIG			sysCom[MAX_COM_NUM];		//��������
	DD_IMAGE_CONFIG			sysImage;					//ͼ�����
	UCHAR					ADD[3];
	DD_USER_CONFIG			sysUser[MAX_USER_NUM];		//�û�
	DD_ALARMOUT_CONFIG		sysAlarmOut;				//�������
		
	DD_PROTOCOL_INFO 		YunTaiInfo[MAX_VIDEO_NUM];	//��̨��Ϣ
	UCHAR					AD[2];
	DD_YUNTAI_SET 			YunTaiSet[MAX_VIDEO_NUM];	//��̨Э������		
} PACKED DD_NVD_CONFIG ;


//16����չ��Ϣ�ṹ
typedef struct _DD_EXTINFO_CONFIG
{
	UINT			nSize;						//�ṹ��С

	//ntp
	NTP_CONFIG		ntpConfig;

	//upnp
	UPNP_CONFIG		upnpConfig;
	
	//MAIL
	MAIL_CONFIG		mailConfig;

	//ALARM IN/OUT NAME
	ALARM_INOUT_NAME alarmInOutName;

	//WF NETWORK
	WF_NET_CONFIG	wfConfig;

	//SEND DEST
	SEND_DEST		sendDest;
	
	CHAR			reserve[480];
}DD_EXTINFO_CONFIG;


#endif
