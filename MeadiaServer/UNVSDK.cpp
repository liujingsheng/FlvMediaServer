#include "UNVSDK.h"
#include <imos_errcode.h>
#include <sdk_func.h>
#include <string.h>
#include "stdio.h"
#include <cstdlib>
UNVSDK* UNVSDK::m_pInstance=0;
UNVSDK::UNVSDK(): mulConnectStatus(0)

{

}
ULONG UNVSDK::Login(CHAR szServerAdd[IMOS_IPADDR_LEN], CHAR userName[IMOS_NAME_LEN], CHAR* password, ULONG_32 ulServerPort)
{
	ULONG ulRet = ERR_COMMON_SUCCEED;

	char szOutput[IMOS_PASSWD_ENCRYPT_LEN];

	ulRet = IMOS_Initiate(szServerAdd, ulServerPort, BOOL_TRUE, BOOL_TRUE);
	if (ERR_COMMON_SUCCEED != ulRet)
	{
		printf("IMOS_Initiate return fail, errorcode is %lu. \n", ulRet);
		return -1;
	}

	ulRet = IMOS_Encrypt(password, strlen(password), szOutput); //”√ªß√‹¬Îº”√‹
	if (ERR_COMMON_SUCCEED != ulRet)
	{
		printf("IMOS_Encrypt return fail, errorcode is %lu. \n", ulRet);
		printf("Connect fail!\n");
		return -1;
	}

	//ulRet = IMOS_Login(IMOS_USER, szOutput, "N/A", &gstLoginInfo);
	ulRet = IMOS_LoginEx(userName, szOutput, szServerAdd, "N/A", &mstLoginInfo);
	if (ERR_COMMON_SUCCEED != ulRet)
	{
		printf("IMOS_Login return fail, errorcode is %lu. \n", ulRet);
		printf("Connect fail!\n");
		return -1;
	}

	PLAY_WND_INFO_S * stPlayWndInfo = (PLAY_WND_INFO_S *)malloc(mMaxPlayers * sizeof(PLAY_WND_INFO_S));
	ulRet = IMOS_StartPlayer(&mstLoginInfo.stUserLoginIDInfo, mMaxPlayers, stPlayWndInfo);
	if (ERR_COMMON_SUCCEED != ulRet)
	{
		printf("IMOS_StartPlayer return fail, errorcode is %lu. \n", ulRet);
		printf("Connect fail!\n");
		return -1;
	}
	mulConnectStatus = 1;
	return  ulRet;
}
void UNVSDK::Logout()
{
	mulConnectStatus = 0;
	(void)IMOS_StopPlayer(&mstLoginInfo.stUserLoginIDInfo);
	(void)IMOS_LogoutEx(&mstLoginInfo.stUserLoginIDInfo);
	(void)IMOS_CleanUp(&mstLoginInfo.stUserLoginIDInfo);
}
UNVSDK::~UNVSDK()
{
}
