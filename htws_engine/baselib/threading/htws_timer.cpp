/*
 * htws_timer.cpp
 *
 *  Created on: Oct 10, 2014
 *      Author: hearthewarsong
 */

#include "../baselib_all.h"

namespace htws
{

Timer::Timer(IFunction<void>* task, unsigned millisecs) :task(task), millisecs(millisecs)
{
}

Timer::~Timer()
{
}

void htws::Timer::Start()
{
	//sf::Thread();
}

void htws::Timer::Stop()
{
}


} /* namespace htws */
