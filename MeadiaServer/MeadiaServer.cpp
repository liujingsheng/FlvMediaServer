
#include <thread>
#include <mutex>
#include <chrono>
#include "webserver.hpp"
#include "UNVSDK.h"
#include <windows.h>
#include <direct.h>
#define IMOS_HOST "192.168.1.199"
#define IMOS_USER "loadmin"
#define IMOS_PASS "Admin123"


/*volatile*/ bool g_bExit = false;

BOOL CALLBACK CosonleHandler(DWORD ev)
{
	BOOL bRet = FALSE;
	switch (ev)
	{
	case CTRL_SHUTDOWN_EVENT:
	case CTRL_C_EVENT:
	case CTRL_CLOSE_EVENT:
	
		auto sdk = UNVSDK::GetInstance(); 
		sdk->Logout();
		printf("exiting ...\n");
		g_bExit = true;
		bRet = TRUE;
		break;

	}
	return bRet;
}
int main(int argc, char *argv[])
{
	char * root= _getcwd(NULL, 0);
	const char * www= "\\www";
	strcpy_s(root + strlen(root), strlen(www)+1, www);
	printf("  Connect by http://localhost:8801, replace localhost with your ip\n");

	const char *options[] = {
		"document_root", root,
		"listening_ports", PORT,0 };
	auto sdk= UNVSDK::GetInstance();
	if(sdk->Login(IMOS_HOST, IMOS_USER, IMOS_PASS)!=0)
	{
		printf("log to UNV server failed!\n");
	}
	else
	{
		printf("log to UNV server successed!\n");
	}
	std::vector<std::string> cpp_options;
	for (int i = 0; i<(sizeof(options) / sizeof(options[0]) - 1); i++) {
		cpp_options.push_back(options[i]);
	}

	SWebServer *  pWebServer = new SWebServer(cpp_options);

	SetConsoleCtrlHandler(CosonleHandler, TRUE);
	while (!g_bExit)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
