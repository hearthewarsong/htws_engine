/*
 * StaticRegistry.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: hearthewarsong
 */

#include "../basics_all.h"

stack<DeletableClass*> SingletonRegistry::singletons;

SingletonRegistry::SingletonRegistry()
{

}

SingletonRegistry::~SingletonRegistry()
{
}


void SingletonRegistry::Add(DeletableClass* instance)
{

	SingletonRegistry::singletons.push(instance);
}

void SingletonRegistry::DestroyAll()
{
	while(singletons.size())
	{
		delete singletons.top();
		singletons.pop();
	}
}
