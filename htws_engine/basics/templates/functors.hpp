#ifndef FUNCTORS_HPP_
#define FUNCTORS_HPP_

#include "../basics_all.h"

template<typename RetType, typename ... Args>
class IFunction
{
public:
	virtual RetType Call(Args ... args) pure;
	virtual RetType operator()(Args... args)
	{
		return Call(args...);
	}
	virtual ~IFunction()
	{
	}
};

template<typename ... Args>
class IFunction <void, Args...>
{
public:
	virtual void Call(Args ... args) pure;
	virtual void operator()(Args... args)
	{
		Call(args...);
	}
	virtual ~IFunction()
	{
	}
};

template<class C, typename RetType, typename ... Args>
class MemberFunction: public IFunction<RetType, Args...>
{
public:
	typedef RetType (C::*FuncType)(Args...);
	MemberFunction(C * instance, FuncType funct) :
			_instance(instance), _funct(funct)
	{
	}
	virtual RetType Call(Args ... args)
	{
		return ((*_instance).*_funct)(args...);
	}
	virtual ~MemberFunction()
	{
	}
protected:
	C* _instance;
	FuncType _funct;
};

template<class C, typename ... Args>
class MemberAction: public IFunction<void, Args...>
{
public:
	typedef void (C::*FuncType)(Args...);
	MemberAction(C * instance, FuncType funct) :
			_instance(instance), _funct(funct)
	{
	}
	virtual void Call(Args ... args)
	{
		((*_instance).*_funct)(args...);
	}
	virtual ~MemberAction()
	{
	}
protected:
	C* _instance;
	FuncType _funct;
};

template<typename RetType, typename ... Args>
class NormalFunction: IFunction<RetType, Args...>
{
public:
	typedef RetType (*FuncType)(Args...);
	NormalFunction(FuncType funct) :
			_funct(funct)
	{
	}
	virtual RetType Call(Args ... args)
	{
		return (_funct)(args...);
	}
	virtual ~NormalFunction()
	{
	}
protected:
	FuncType _funct;
};

template<typename ... Args>
class NormalAction: IFunction<void, Args...>
{
public:
	typedef void (*FuncType)(Args...);
	NormalAction(FuncType funct) :
			_funct(funct)
	{
	}
	virtual void Call(Args ... args)
	{
		(_funct)(args...);
	}
	virtual ~NormalAction()
	{
	}
protected:
	FuncType _funct;
};

template<typename ... Args>
class FunctionGroup
{
protected:
	typedef std::vector<IFunction<void, Args...> *> FuncContainer;
	FuncContainer _functions;
public:
	FunctionGroup()
	{

	}
	void Call_All(Args ... args)
	{
		for (int i = 0; i < _functions.size(); ++i)
		{
			_functions[i]->Call(args...);
		}
	}
	void operator()(Args ... args)
	{
		for (unsigned i = 0; i < _functions.size(); ++i)
		{
			_functions[i]->Call(args...);
		}
	}
	void Add(const IFunction<void, Args...>& func)
	{
		_functions.push_back(new IFunction<void, Args...>(func));
	}
	bool Remove(const IFunction<void, Args...>& func)
	{
		for (int i = 0; i < _functions.size(); ++i)
		{
			if (*(_functions[i]) == func)
			{
				delete _functions[i];
				_functions.erase(_functions.begin() + i);
				return true;
			}
		}
		return false;
	}
	~FunctionGroup()
	{
		for (unsigned i = 0; i < _functions.size(); ++i)
		{
			delete _functions[i];
		}
	}
};


#endif /* FUNCTORS_HPP_ */
