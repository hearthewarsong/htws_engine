#ifndef I_APPLICATION_H_
#define I_APPLICATION_H_

class IApplication
{
public:
	virtual void Init(char** args, int argv) pure;
	virtual void Run() pure;
	virtual ~IApplication() {}
};



#endif /* I_APPLICATION_H_ */
