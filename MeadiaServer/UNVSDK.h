#pragma once
#include <imos_public.h>
#include <imos_def.h>
#include <sdk_struct.h>
#include <minwindef.h>

class UNVSDK
{

public:
	static UNVSDK * GetInstance()
	{
		if (m_pInstance == NULL)  //判断是否第一次调用  
			m_pInstance = new UNVSDK();
		return m_pInstance;
	}
	ULONG Login(CHAR szServerAdd[IMOS_IPADDR_LEN], CHAR userName[IMOS_NAME_LEN], CHAR* password, ULONG_32 ulServerPort=8800);
	void Logout();
	~UNVSDK();
	LOGIN_INFO_S mstLoginInfo;
	unsigned int   mulConnectStatus;
	const unsigned int mMaxPlayers=64;

private:
	UNVSDK();
	static UNVSDK *m_pInstance;

};


