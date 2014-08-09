#include "application.h"

#include "../baselib/graphics/g_console.h"
//#include "proj_consol_all.h"

#ifdef PROJECT_CONSOL

Application::Application() :closing(false), pSysEventHandler(NULL)
{
	// TODO Auto-generated constructor stub

}

Application::~Application()
{
	// TODO Auto-generated destructor stub
}

void Application::Init(char** args, int argc)
{
	pSysEventHandler = SystemEventHandler::GetInstance();
	pSysEventHandler->AddCloseEventListener(
			new MemberFunction<Application, bool, const CloseEvent&>(this,
					&Application::ClosingEventListener));
	closing = false;
}

void Application::Run()
{
	GConsole consol("", 16);
	consol.Open("", "");
	consol.Write(L"Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line Proba line 1\n");
	consol.Write(L"Proba line 2\n");
	consol.Write(L"Proba line 3\n");
	while(!closing)
	{
		pSysEventHandler->ProcessEvents();
		consol.Update();
		if (consol.isClosed())
		{
			closing = true;
			break;
		}
		consol.Render(NULL);
	}
}

bool Application::ClosingEventListener(const CloseEvent& event)
{
	closing = true;
	return false;
}

#endif /* PROJECT_CONSOL */
