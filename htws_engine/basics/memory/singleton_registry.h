#ifndef SINGLETON_REGISTRY_H
#define SINGLETON_REGISTRY_H

#include "../basics_all.h"


class SingletonRegistry
{
private:
	SingletonRegistry();
	~SingletonRegistry();
	static stack<DeletableClass*> singletons;
public:
	static void Add(DeletableClass* instance);
	static void DestroyAll();
};

#endif /* SINGLETON_REGISTRY_H */
