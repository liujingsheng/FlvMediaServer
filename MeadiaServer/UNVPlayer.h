#pragma once
#include <imos_public.h>
#include <imos_def.h>
#include <xp_datatype.h>
#include <sdk_struct.h>
#include "converter.h"
using namespace Cnvt;
class UNVPlayer
{
public:
	UNVPlayer();
	ULONG Startmonitor( CHAR* szCameraCode);
	ULONG Stopmonitor();
	std::ostream* _streamOut;
	void SetStream(std::ostream* ost);
	int Convert();
	void StreamOut();
	void static STDCALL ParseVideoOutputToFile(IN const USER_LOGIN_ID_INFO_S *pstUserLoginIDInfo,
		IN const CHAR *pcChannelCode,
		IN const XP_PARSE_VIDEO_DATA_S *pstParseVideoData,
		IN LONG_REAL lUserParam,
		IN LONG_REAL lReserved);
	~UNVPlayer();
private:
    unsigned char *m_pBufferIn, *m_pBufferOut;
    ULONG_32 m_nFrameSize;
	CHAR pcChannelCode[IMOS_CODE_LEN];
	CConverter m_cnvt;

};

inline void UNVPlayer::SetStream(std::ostream* ost)
{

	_streamOut = ost;
	m_cnvt.SetStream(ost);
}

