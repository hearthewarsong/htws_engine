#include "application.h"

#include "../baselib/graphics/g_console.h"
//#include "proj_consol_all.h"

#ifdef PROJECT_CONSOL


Application::Application() :closing(false), pSysEventHandler(NULL)
{
}

Application::~Application()
{
}

void Application::Init(char** args, int argc)
{
	closing = false;
	if (argc == 3 || true)
	{
		//netFile = args[1];
		//problemFile = args[2];
		netFile = "DPhil-10.pn";
		problemFile = "DPhil-10.prb";

	}
}

void Application::Run()
{
	consol.reset(new GConsole("", 16));
	pSysEventHandler.reset(new SystemEventHandler(&consol->GetSFRenderWindow()));
	pSysEventHandler->AddCloseEventListener(
			new MemberFunction<Application, bool, const CloseEvent&>(this,
					&Application::ClosingEventListener));
	pSysEventHandler->AddKeyEventListener(
			new MemberFunction<Application, bool, const KeyEvent&>(this,
					&Application::KeyEventListener));
	consol->initEventHandling(pSysEventHandler.get());
	consol->Open("", "");
	consol->Write(L"Application Started...\n");
	GlobalLogger::GetInstance()->SetLoggerOutput(consol.get());
	GlobalLogger::GetInstance()->EnableArea(LLA_Config,5);

	consol->Write(Format("Value of mkk.display.background->file_path is \"%s\"", ConfigTree::GetInstance()->GetElementOrDefault("mkk.display.background","file_path","images/background.jpg").GetString().c_str()));
	while(!closing)
	{
		pSysEventHandler->ProcessEvents();
		consol->Update();
		if (consol->isClosed())
		{
			closing = true;
			break;
		}
		wstring line;
		if (consol->GetLine(line))
		{
		}
		consol->Render(NULL);
	}
	consol->Close();
	pSysEventHandler.reset();
}

bool Application::ClosingEventListener(const CloseEvent& event)
{
	closing = true;
	return false;
}

bool Application::KeyEventListener(const KeyEvent& event)
{
	return true;
}

#endif /* PROJECT_CONSOL */
