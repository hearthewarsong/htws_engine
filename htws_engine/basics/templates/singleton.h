/*
 * singleton.hpp
 *
 *  Created on: Apr 16, 2014
 *      Author: hearthewarsong
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

template<class DescandantType>
class Singleton: protected DeletableClass
{
protected:
	Singleton()
	{
	}
	static DescandantType * instance;

	virtual ~Singleton()
	{
	}
public:
	static DescandantType * GetInstance()
	{
		if (instance == NULL)
		{
			instance = new DescandantType();
			SingletonRegistry::Add(instance);
		}
		return instance;
	}

	friend class SingletonRegistry;

};

#define CREATE_STATIC_INSTANCE(className) template<> \
className* Singleton<className>::instance = NULL

#endif /* SINGLETON_H_ */
