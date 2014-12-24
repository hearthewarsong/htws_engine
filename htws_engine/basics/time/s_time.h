#ifndef S_TIME_H_
#define S_TIME_H_


//TODO implement

class STimeDifference
{
protected:
	unsigned _time;
public:
	STimeDifference(unsigned millisecs) :_time(millisecs) {}
	operator unsigned int()
		{
			return _time;
		}
};

class STime
{
protected:
	unsigned _time;
public:
	STime();
	STime(const STime& sTime);
	STimeDifference operator-(const STime& sTime);
	virtual ~STime();
};

#endif /* S_TIME_H_ */
