#ifndef _Decoder_H_
#define _Decoder_H_

#ifdef __cplusplus
extern "C" {
#endif

//========================================================
//�Ƶ�Ƶ�
//========================================================
#ifndef AV_INFO_DEFINE
#define AV_INFO_DEFINE

#define	AVFORMAT_IN_MPEG4					0xF000
#define	AVFORMAT_IN_H264					0xF001

typedef struct _HHAV_INFO
{
    //�Ƶ�
	unsigned int			nVideoEncodeType;		//�Ƶ��ʽ
    unsigned int			nVideoHeight;			//�Ƶͼ��
    unsigned int			nVideoWidth;			//�Ƶͼ��
    //�Ƶ�
	unsigned int			nAudioEncodeType;		//�Ƶ��ʽ
    unsigned int			nAudioChannels;			//ͨ�
    unsigned int			nAudioBits;				//λ�
    unsigned int			nAudioSamples;			//��
}AV_INFO, *PAV_INFO;

#endif //HHAV_INFO_DEFINE

#define DECODER_ERR_INVALID_PARAMETER  -1
#define DECODER_SUCCESS					0

#define DECODER_YUV_420 0x00
#define DECODER_YUV_422 0x01
#define DECODER_RGB_024 0x02
#define DECODER_ARGB_32 0x06


typedef struct _MP6_FILE_HEAD
{
	unsigned long	magicFlag;
	unsigned char	majorVideoType;
	unsigned char	minorVideoType;
	unsigned char	majorAudioType;
	unsigned char	minorAudioType;
	unsigned char	reserved[8];
}MP6_FILE_HEAD;

typedef struct ParseContext{
	unsigned int  FrameStartFound;
	unsigned int  iFrameLength;
	unsigned int  PrevFirstMBAddr;
} ParseContext;
#define MOST_BIT_MASK  0x80000000
#define MAX_AU_SIZE    0x80000

void *CreateH264Decoder();
int   Decoder_ReleaseDecoder(void* pDecoder);
int   Decoder_DecodeOneFrame(void* pDecoder, char* Buf_Src,  int Src_Len, char* Buf_Dst, ENCODE_VIDEO_TYPE encodeVideoType);
//int   Hi264DecLoadAU(unsigned char* pStream, unsigned int iStreamLen, ParseContext *pc);

int   Decoder_InitDecoder_G726(void);
int   Decoder_DecodeData_G726(char *BuffIn, int InNum,unsigned short *BuffOut);
int   Decoder_InitEncoder_G726(void);
int   Decoder_EncodeData_G726( unsigned short *BuffIn, int InNum, char *BuffOut);

#ifdef __cplusplus
}
#endif
#endif //_HHDecoder_H_

