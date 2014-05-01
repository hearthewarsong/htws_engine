
#ifndef TEXT_TCP_CLIENT_H_
#define TEXT_TCP_CLIENT_H_

class ITextTcpClient : public IWTextCommunicator
{
public:
	virtual int Read(wstring& str) pure;
	virtual bool Write(wstring& str) pure;
	virtual bool hasInput() pure;
	virtual bool hasOutput() pure;
	virtual bool isBlocking() pure;
	virtual bool setBlocking(bool value) pure;
	virtual ProtEnums::Status getStatus() pure;
	virtual int getLastError(string& text) pure;
	virtual bool Open(const string& arg0, const string& arg1) pure;
	virtual void Close() pure;
	virtual bool Reinit() pure;
};

#if defined(HTWS_NETWORK_DUMMY)
class TextTcpClient : public ITextTcpClient
{
protected:
	ProtEnums::Status status;
public:
	TextTcpClient();
	virtual ~TextTcpClient();
	virtual int Read(wstring& str);
	virtual bool Write(wstring& str);
	virtual bool hasInput();
	virtual bool hasOutput();
	virtual bool isBlocking();
	virtual bool setBlocking(bool value);
	virtual ProtEnums::Status getStatus();
	virtual int getLastError(string& text);
	virtual bool Open(const string& arg0, const string& arg1);
	virtual void Close();
	virtual bool Reinit();
};
#elif defined(HTWS_NETWORK_WINSOCKETS)
class TextTcpClient : ITextTcpClient
{
protected:
	ProtEnums::Status status;
public:
	TextTcpClient();
	virtual ~TextTcpClient();
	virtual int Read(wstring& str);
	virtual bool Write(wstring& str);
	virtual bool hasInput();
	virtual bool hasOutput();
	virtual bool isBlocking();
	virtual bool setBlocking(bool value);
	virtual ProtEnums::Status getStatus();
	virtual int getLastError(string& text);
	virtual bool Open(string& arg0, string arg1);
	virtual void Close();
	virtual bool Reinit();
};
#else
#error no network type defined. pls use: HTWS_NETWORK_WINSOCKETS, HTWS_NETWORK_DUMMY etc.
#endif /* HTWS_NETWORK_TYPE */

#endif /* TEXT_TCP_CLIENT_H_ */
