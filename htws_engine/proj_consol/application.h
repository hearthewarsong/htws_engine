#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "proj_consol_all.h"

#ifdef PROJECT_CONSOL

class Application : public IApplication
{
protected:
	bool closing;
	bool ClosingEventListener(const CloseEvent& event);
	bool KeyEventListener(const KeyEvent& event);
	auto_ptr<ISystemEventHandler> pSysEventHandler;
	auto_ptr<GConsole> consol;
	string netFile;
	string problemFile;
public:
	Application();
	virtual ~Application();
	void Init(char** args, int argc);
	void Run();
};

#endif /* PROJECT_CONSOL */

#endif /* APPLICATION_H_ */
