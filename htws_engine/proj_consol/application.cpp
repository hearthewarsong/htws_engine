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
	GlobalLogger::GetInstance()->EnableArea("petri",5);

	vector<string> Tests;
	//Tests.push_back("DPhil-10");
	Tests.push_back("Cegar_Vegtelen");
	//Tests.push_back("SlottedRing-100");
	foreach(vector<string>,Tests,t)
	{
		std::clock_t clockStart = std::clock();
		//Petrinet calculation:
		petri::PertiFileHandler fileHandler;
		petri::PetriNet* net = fileHandler.LoadPetriNetFromFile(FilePath((*t + ".pn").c_str()));
		if (!net)
		{
			LLFM("faildet to load petri net");
		}
		petri::ReachibilityProblem* problem = fileHandler.LoadReachibilityProblem(FilePath((*t +".prb").c_str()));
		if (!problem)
		{
			LLFM("faildet to load reachibility problem");
		}
		petri::ModuloStateSpaceExplorer moduloExplorer;

		if (net && problem)
		{
			net->SetInitialMarking(problem->GetStartingMarking());
			moduloExplorer.ExaminePetriNet(*net);
			if (moduloExplorer.HasMarking(problem->GetEndMarking()))
			{
				consol->Write("Marking is reachable!\n");
			}
			else
			{
				consol->Write("Marking is unreachable!\n");
			}
		}
		delete problem;
		delete net;

		std::clock_t clockFinish= std::clock();

		consol->Write(Format("Algorith ended for %s in %d milliseconds. Size of graph: %d \n", (*t).c_str() %  ((clockFinish - clockStart) * 1000.0 / CLOCKS_PER_SEC) % moduloExplorer.GetGraphSize() ));
	}
		consol->Write("Algorithm ended!\n");

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
