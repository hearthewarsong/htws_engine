#include "../drivers_all.h"

#if defined(HTWS_NETWORK_DUMMY)

TextTcpClient::TextTcpClient()
{
	this->status = ProtEnums::Unopened;
}

TextTcpClient::~TextTcpClient()
{
	// TODO Auto-generated destructor stub
}

int TextTcpClient::Read(wstring& str)
{
	str = wstring();
	return 0;
}

bool TextTcpClient::Write(wstring& str)
{
	return true;
}

bool TextTcpClient::hasInput()
{
	return true;
}

bool TextTcpClient::hasOutput()
{
	return true;
}

bool TextTcpClient::isBlocking()
{
	return false;
}

bool TextTcpClient::setBlocking(bool value)
{
	return false;
}

ProtEnums::Status TextTcpClient::getStatus()
{
	return status;
}

int TextTcpClient::getLastError(string& text)
{
	text = "none.";
	return 0;
}

bool TextTcpClient::Open(const string& arg0, const string& arg1)
{
	status = ProtEnums::Connected;
}

void TextTcpClient::Close()
{
	status = ProtEnums::Closed;
}

bool TextTcpClient::Reinit()
{
	status = ProtEnums::Connected;
}

#elif defined(HTWS_NETWORK_WINSOCKETS)

#error not implemented yet
TextTcpClient::TextTcpClient()
{
	this->status = ProtEnums::Unopened;
}

TextTcpClient::~TextTcpClient()
{
	// TODO Auto-generated destructor stub
}



#else
#error no network type defined. pls use: HTWS_NETWORK_WINSOCKETS, HTWS_NETWORK_DUMMY etc.
#endif /* HTWS_NETWORK_TYPE */
