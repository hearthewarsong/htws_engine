#include "../modules/modules_all.h"

#if defined(PROJECT_MKK)
#include "../proj_kijelzo/proj_kijelzo_all.h"
#else
#error No active project, pls define it.
#endif


int main(int argc, char* argv[])
{
	do
	{
		htws_globals::Restart = false;
		Application application;
		application.Init(argv,argc);
		application.Run();
		SingletonRegistry::DestroyAll();
	}
	while(htws_globals::Restart);
	return 0;
}

