#include "UNVPlayer.h"
#include <imos_errcode.h>
#include <imos_public.h>
#include <sdk_func.h>
#include <xp_func.h>
#include "stdio.h"
#include <cstdlib>
#include "UNVSDK.h"
#include "splitter.h"
using namespace Cnvt;

UNVPlayer::UNVPlayer() : m_pBufferIn(nullptr), m_pBufferOut(nullptr), m_nFrameSize(0)
{
}

ULONG UNVPlayer::Startmonitor(CHAR* szCameraCode)
{
	ULONG ulRet = ERR_COMMON_SUCCEED;

#if 0
	/* 询问是否设置实时播放时图像的流畅性，默认为实时性优先, (可选) */
	CHAR set;
	ULONG choose = 0;
	printf("Do you want to Set Realtime Fluency? ");
	set = getchar();
	while (getchar() != '\n');  //过滤多余字符
	if (set == 'y')
	{
		printf(" 1. XP_PICTURE_FLUENCY_PRIORITY \n");
		printf(" 2. XP_PICTURE_TIME_FLUENCY_AUTO \n");
		printf(" 3. XP_PICTURE_HIGH_LOWDELAY \n");
		printf(" Default. XP_PICTURE_TIME_PRIORITY \n");
		printf("Choose: ");
		scanf("%d", &choose);
		getchar();
		switch (choose)
		{
		case 1:
			ulRet = IMOS_SetRealtimeFluency(XP_PICTURE_FLUENCY_PRIORITY);
			if (ERR_COMMON_SUCCEED != ulRet)
			{
				printf("IMOS_SetRealtimeFluency return fail, errorcode is %lu. \n", ulRet);
				return -1;
			}
			break;
		case 2:
			ulRet = IMOS_SetRealtimeFluency(XP_PICTURE_TIME_PRIORITY);
			if (ERR_COMMON_SUCCEED != ulRet)
			{
				printf("IMOS_SetRealtimeFluency return fail, errorcode is %lu. \n", ulRet);
				return -1;
			}
			break;
		case 3:
			ulRet = IMOS_SetRealtimeFluency(XP_PICTURE_HIGH_LOWDELAY);
			if (ERR_COMMON_SUCCEED != ulRet)
			{
				printf("IMOS_SetRealtimeFluency return fail, errorcode is %lu. \n", ulRet);
				return -1;
			}
			break;
		default:
			break;
		}
		printf("IMOS_SetRealtimeFluency Success!\n");
	}
	else
	{
	}
#endif
	UNVSDK* sdk = UNVSDK::GetInstance();

 	ulRet = IMOS_GetChannelCode(&sdk->mstLoginInfo.stUserLoginIDInfo, pcChannelCode);
	if (ERR_COMMON_SUCCEED != ulRet)
	{
		printf("IMOS_GetChannelCode failed!\n");
		return -1;
	}

	ulRet = IMOS_SetParseVideoDataCB(&sdk->mstLoginInfo.stUserLoginIDInfo,
		pcChannelCode, UNVPlayer::ParseVideoOutputToFile, BOOL_TRUE, (LONG_REAL)this);
	if (ERR_COMMON_SUCCEED != ulRet)
	{
		printf("IMOS_SetDecodeVideoDataCB failed!\n");
		return -1;
	}
	ulRet = IMOS_StartMonitor(&sdk->mstLoginInfo.stUserLoginIDInfo, szCameraCode, pcChannelCode, 0, 0);
	if (ERR_COMMON_SUCCEED != ulRet)
	{
		printf("IMOS_StartMonitor return fail, errorcode is %lu. \n", ulRet);
		printf("Startmonitor fail!\n");
		return -1;
	}
	printf("Startmonitor success!\n");
	return ulRet;
}

ULONG UNVPlayer::Stopmonitor()
{
	ULONG ulRet = ERR_COMMON_SUCCEED;
	UNVSDK* sdk = UNVSDK::GetInstance();
	ulRet = IMOS_StopMonitor(&sdk->mstLoginInfo.stUserLoginIDInfo, pcChannelCode, 0);
	if (ERR_COMMON_SUCCEED != ulRet)
	{
		printf("IMOS_StopMonitor return fail, errorcode is %lu. \n", ulRet);
		return -1;
	}
	IMOS_FreeChannelCode(&sdk->mstLoginInfo.stUserLoginIDInfo, pcChannelCode);
	printf("IMOS_StopMonitor success!\n");
	return ulRet;

}

/* 解码后回放媒体流数据回调函数 */

void  STDCALL UNVPlayer::ParseVideoOutputToFile(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
	IN const CHAR *pcChannelCode,
	IN const XP_PARSE_VIDEO_DATA_S *pstParseVideoData,
	IN LONG_REAL lUserParam,
	IN LONG_REAL lReserved)
{

	printf("ParseVideo callback, %s: size:%1u codeformat:%1u videoframetype:%1u %lu*%lu time:%llu\n", pcChannelCode,
		pstParseVideoData->ulDataLen,
		pstParseVideoData->ulVideoCodeFormat,
		pstParseVideoData->ulVideoFrameType,
		pstParseVideoData->ulHeight,
		pstParseVideoData->ulWidth,
		pstParseVideoData->dlTimeStamp
	);
	printf("\n");
	//for (int i = 0; i < 5; i++)
	//{
	//	printf("%x, ", pstParseVideoData->pucData[i]);
	//}
	//printf("\n");

	auto player = (UNVPlayer*)lUserParam;
	player->m_pBufferIn = (UCHAR*)malloc(pstParseVideoData->ulDataLen * sizeof(UCHAR));
	//player->m_pBufferOut = (UCHAR*)malloc(pstParseVideoData->ulDataLen*sizeof(UCHAR));
	memcpy(player->m_pBufferIn, pstParseVideoData->pucData, pstParseVideoData->ulDataLen);
	player->m_nFrameSize = pstParseVideoData->ulDataLen;
	player->m_cnvt.SetTimeStamp(pstParseVideoData->dlTimeStamp);
	player->Convert();
	//player->StreamOut();
	free(player->m_pBufferIn);
	//free(player->m_pBufferOut);

}
void UNVPlayer::StreamOut()
{

	int nOffset = 0;
	int count = 0;

	while (1)
	{
		int nNaluSize = 0;
		int nNaluHeaderSize = 0;
		unsigned char* oneNalu = 0;
		oneNalu = Cnvt::GetOneNalu(m_pBufferIn + nOffset, m_nFrameSize - nOffset, nNaluSize, nNaluHeaderSize);
		if (oneNalu == 0)
			break;
		u4 nNaluSize_u4(nNaluSize);
		_streamOut->write((char *)nNaluSize_u4._u, 4);
		_streamOut->write((char *)oneNalu, nNaluSize);

		free(oneNalu);
		nOffset += nNaluSize - 1;
		if (nOffset >= m_nFrameSize - 4)
			break;
		count++;

	}
}

int UNVPlayer::Convert()
{
	int nOffset = 0;
	int count = 0;

	while (1)
	{
		int nNaluSize = 0;
		int nNaluHeaderSize = 0;
		unsigned char* oneNalu = 0;
		oneNalu = Cnvt::GetOneNalu(m_pBufferIn + nOffset, m_nFrameSize - nOffset, nNaluSize, nNaluHeaderSize);
		if (oneNalu == 0)
			break;

		m_cnvt.Convert((char *)oneNalu, nNaluSize);
		free(oneNalu);
		if (nNaluHeaderSize == 3)
		{
			nOffset += nNaluSize - 1;
		}
		else if (nNaluHeaderSize == 4)
		{
			nOffset += nNaluSize;
		}
	
		if (nOffset >= m_nFrameSize - nNaluHeaderSize)
			break;
		count++;

	}

	return 1;

}

UNVPlayer::~UNVPlayer()
{
}
