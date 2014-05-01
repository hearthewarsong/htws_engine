#ifndef I_COMMUNICATOR_H_
#define I_COMMUNICATOR_H_

#include "../basics_all.h"

class ProtEnums
{
public:
	enum Status { Unopened, Connected, Timeout, Closed, Error};
};


class IICommunicator
{
protected:
	IICommunicator() {}
public:
	virtual bool hasInput() pure;
	virtual bool hasOutput() pure;
	virtual bool isBlocking() pure;
	virtual bool setBlocking(bool value) pure;
	virtual ProtEnums::Status getStatus() pure;
	virtual int getLastError(string& text) pure;
	virtual bool Open(const string& arg0, const string& arg1) pure;
	virtual void Close() pure;
	virtual bool Reinit() pure;
	virtual ~IICommunicator() {}
};

class ITextCommunicator : public IICommunicator
{
public:
	virtual int Read(string& str) pure;
	virtual bool Write(const string& str) pure;
};

class IWTextCommunicator : public IICommunicator
{
public:
	virtual int Read(wstring& str) pure;
	virtual bool Write(wstring& str) pure;
};

class IBinaryCommunicaror: public IICommunicator
{
public:
	virtual int Read(byte buffer[], int buffer_size) pure;
	virtual bool Write(byte msg[], int msg_size) pure;
};


#endif /* I_COMMUNICATOR_H_ */
