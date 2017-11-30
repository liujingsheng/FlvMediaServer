#pragma once
#ifndef __MSE_API_H__
#define __MSE_API_H__

#include "civetweb.h"
#include "CivetServer.h"
#include <thread>
#include <mutex>
#include <chrono>

#include "UNVPlayer.h"
#include "WebSocktStreamBuf.hpp"
#ifdef _WIN32
#include <iostream>
#include <Windows.h>
#else
#include <unistd.h>
#endif
#define IMOS_CAM  "songxia"

using namespace std;
typedef struct tWebSockInfo {
	int webSockState;
	unsigned long initId;
	struct mg_connection *conn;
} tWebSockInfo;

#define MAX_NUM_OF_WEBSOCKS (256)
typedef struct tWebSockContext {
	int runLoop;
	void *thread_id;
	tWebSockInfo *socketList[MAX_NUM_OF_WEBSOCKS];
} tWebSockContext;

class WebSoecktConnection
{
public:
	WebSoecktConnection(struct mg_connection * conn)
		:m_conn(conn)
	{

	}

	virtual ~WebSoecktConnection()
	{

	}
	char* GetCameraName(const char* url) const
	{
		char *delim = "/";
		char *p[3];
		char *next_token = 0;

		char *buf = new char[strlen(url) + 1];
		strcpy_s(buf, strlen(url) + 1, url);
		p[0] = strtok_s(buf, delim, &next_token);
		int i = 1;
		while (((p[i] = strtok_s(NULL, delim, &next_token))) && i<3)
		{
			i++;
		}

	
		if(p[1]!=NULL)
		{

			char* cameraName = (char*)malloc(IMOS_CODE_LEN);
			memset(cameraName, 0, IMOS_CODE_LEN);//
			strcpy_s(cameraName, strlen(p[1])+1, p[1]);
			return cameraName;
		}
		else
		{
			return NULL;
		}

	}

	bool Start()
	{
		ostream* st = new ostream(new WebSocketStreambuf(m_conn));	
		const struct mg_request_info *rq = mg_get_request_info(m_conn);		
	    char* cameraName =GetCameraName(rq->local_uri);
		if(cameraName==NULL)
		{
			//close the websocket;
			mg_websocket_write(m_conn, WEBSOCKET_OPCODE_CONNECTION_CLOSE, NULL, 0);
			return false;
		}
		m_player.SetStream(st);
		m_player.Startmonitor(cameraName);
		return true;
	}
	bool Stop()
	{
		m_player.Stopmonitor();
		return true;
	}

	struct mg_connection *m_conn;
	std::string m_camerCode;
	UNVPlayer m_player;

};

typedef std::map<struct mg_connection *, WebSoecktConnection *> WebSocketConnectionsMap;

class WebSocketHandler : public CivetWebSocketHandler
{
public:
	WebSocketHandler()
	{
	}

	~WebSocketHandler()
	{
	}

	bool handleConnection(CivetServer *server, const struct mg_connection *conn) override
	{
		printf("%s Conneting\n", __FUNCTION__);
		return true;
	}

	bool handleData(CivetServer *server, struct mg_connection *conn, int bits, char *data, size_t data_len) override
	{

		printf("%s  %d\n", __FUNCTION__, data_len);
		int mop=bits & 0x0f;
		switch (mop)
		{
		case WEBSOCKET_OPCODE_CONNECTION_CLOSE:
			return false;
			break;

		default:
			return true;
			break;
		}
	
		
	}

	void handleClose(CivetServer *server, const struct mg_connection *conn) override
	{
		std::lock_guard<std::mutex> guard(m_pLock);
		printf("%s Close\n", __FUNCTION__);

		if (m_pConnMap[(struct mg_connection *)conn] != NULL)
		{
			(WebSoecktConnection*)m_pConnMap[(struct mg_connection *)conn]->Stop();
			delete m_pConnMap[(struct mg_connection *)conn];
		}
		m_pConnMap.erase((struct mg_connection *)conn);
		return;
	}

	void handleReadyState(CivetServer *server, struct mg_connection *conn) override
	{
		std::lock_guard<std::mutex> guard(m_pLock);

		printf("%s Start\n", __FUNCTION__);

		WebSoecktConnection * pConn = new WebSoecktConnection(conn);
		pConn->Start();
		m_pConnMap[conn] = pConn;

	}

private:
	std::mutex m_pLock;
	WebSocketConnectionsMap m_pConnMap;

};

#endif /* __MSE_API_H__ */
