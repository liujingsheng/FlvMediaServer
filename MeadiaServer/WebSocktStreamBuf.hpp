#pragma once
#include <iostream>
using namespace std;
class WebSocketStreambuf : public std::streambuf 
{
public:
	WebSocketStreambuf(mg_connection * conn) : _conn(conn)
	{

	}

	std::streamsize xsputn(const char *s, std::streamsize n) override 
	{
	
		auto x = mg_websocket_write(_conn, WEBSOCKET_OPCODE_BINARY, s, (size_t)n);
		return x > 0 ? x : 0;
	}

	virtual ~WebSocketStreambuf() 
	{

	}

private:

	mg_connection * _conn;


};