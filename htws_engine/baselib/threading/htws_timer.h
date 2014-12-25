#ifndef HTWS_TIMER_H_
#define HTWS_TIMER_H_

namespace htws
{

class Timer
{
protected:
	unique_ptr<IFunction<void> > task;
	unsigned millisecs;
public:
	Timer(IFunction<void>* task, unsigned millisecs);
	void Start();
	void Stop();
	virtual ~Timer();
};

} /* namespace htws */

#endif /* HTWS_TIMER_H_ */
