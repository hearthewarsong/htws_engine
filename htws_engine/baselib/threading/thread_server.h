#ifndef THREAD_SERVER_H_
#define THREAD_SERVER_H_

namespace htws
{

struct Task
{
public:
	auto_ptr<IFunction<void> > task;
	STimeDifference interval;
	STime startTickCount;
	bool repeat;
	Task(IFunction<void>* task, unsigned interval, bool repeat) :task(task), interval(interval), repeat(repeat)
	{
		startTickCount = STime();
	};
	~Task() {}
};

class WorkThread
{
protected:
	list<Task *> tasks;
	string name;
	~WorkThread()
	{

	}
public:
	WorkThread(const char* name) :name(name) {}
	const string& GetName() { return name; }
	void Start();
	void Close();
};

class ThreadServer
{
	map<string,WorkThread*> threads;
public:
	ThreadServer();
	virtual ~ThreadServer();
};

} /* namespace htws */

#endif /* THREAD_SERVER_H_ */
