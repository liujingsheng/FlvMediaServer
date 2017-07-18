#pragma once
#ifndef __VE_WEB_SERVER_H__
#define __VE_WEB_SERVER_H__

#include "CivetServer.h"
#include "WebHandler.hpp"
#ifdef WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#define DOCUMENT_ROOT "."
//#define PORT "8801,8843"
#define PORT "8801"
#define SSL_CERT "./ssl/server.pem"


class SWebServer
{
public:
	SWebServer(std::vector<std::string> cpp_options) :pServer(new CivetServer(cpp_options)), server(*pServer)
	{
		server.addWebSocketHandler("/h5sws", h_mse);

	}
	~SWebServer() {}

private:
	WebSocketHandler h_mse;
	CivetServer *pServer;
	CivetServer &server;
};

#endif /* __VE_WEB_SERVER_H__ */
