#include "../basics_all.h"


#ifdef HTWSC_PLATFORM_LINUX
#include <sys/time.h>

unsigned long GetTickCount()
{
  struct timeval tv;
  if( gettimeofday(&tv, NULL) != 0 )
    return 0;

  return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

#elif defined(HTWSC_PLATFORM_WINDOWS)
#error No GetTickCount included for windwos
#else
#error No GetTickCount implemented for this platform
#endif

STime::STime()
{
	_time = GetTickCount();
}

STime::STime(const STime& sTime)
{
	_time = sTime._time;
}

STimeDifference STime::operator -(const STime& sTime)
{
	return STimeDifference(_time-sTime._time);
}

STime::~STime()
{
	// TODO Auto-generated destructor stub
}

