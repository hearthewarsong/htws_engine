#ifndef I_TEXT_COMMUNICATOR_H_
#define I_TEXT_COMMUNICATOR_H_

#include "../basics_all.h"

class ProtEnums
{
public:
	enum Status { Unopened, Connected, Timeout, Closed, Error};
};


class IITextCommunicator
{
protected:
	IITextCommunicator() {}
public:
	virtual bool hasInput() pure;
	virtual bool hasOutput() pure;
	virtual bool isBlocking() pure;
	virtual bool setBlocking(bool value) pure;
	virtual ProtEnums::Status getStatus() pure;
	virtual int getLastError(string& text) pure;
	virtual bool Open(string& arg0, string arg1) pure;
	virtual bool Reinit() pure;
	virtual ~IITextCommunicator() {}
};

class ITextCommunicator : public IITextCommunicator
{
public:
	virtual int Read(string& str);
	virtual bool Write(const string& str);
};

class IWTextCommunicator : public IITextCommunicator
{
public:
	virtual int Read(wstring& str);
	virtual bool Write(wstring& str);
};


#endif /* I_TEXT_COMMUNICATOR_H_ */
