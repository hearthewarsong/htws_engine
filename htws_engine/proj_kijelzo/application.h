#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "proj_kijelzo_all.h"

#ifdef PROJECT_KIJELZO

class Application : public IApplication
{
public:
	Application();
	virtual ~Application();
	void Init(char** args, int argc);
	void Run();
};

#endif /* PROJECT_KIJELZO */

#endif /* APPLICATION_H_ */
