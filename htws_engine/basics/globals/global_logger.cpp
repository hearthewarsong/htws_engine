/*
 * global_logger.cpp
 *
 *  Created on: Aug 9, 2014
 *      Author: hearthewarsong
 */

#include "../basics_all.h"

GlobalLogger::GlobalLogger() :os(NULL), communicator(NULL)
{

}

void GlobalLogger::LogLine(const char* area, int level, const char* message)
{
	LogLine(area,level,StringHelper::UTF8to16(message).c_str());
}

void GlobalLogger::LogLine(const char* area, int level, const wchar_t* message)
{
	if (communicator)
	{
		communicator->GetOutStream() << StringHelper::UTF8to16(area).c_str() << L"_" << level << L" " <<  message << L"\n";
	}
	else
	{
		if (!os)
		{
			os = new std::ofstream("htws_global_log.txt");
		}
		*os << message;
	}

}

void GlobalLogger::EnableArea(const char* area, int level)
{
	map<string,int>::iterator it = enabled.find(area);
	if (it == enabled.end())
	{
		enabled.insert(std::pair<string,int>(area,level));
	}
	else
	{
		if (it->second < level) it->second = level;
	}
}

void GlobalLogger::SetLoggerOutput(IWTextCommunicator* communicator)
{
	this->communicator = communicator;
}

bool GlobalLogger::IsEnabled(const char* area, int level)
{
	if (level == 0) return true;
	map<string,int>::iterator it = enabled.find(area);
	return it != enabled.end() &&it->second >= level;
}

GlobalLogger::~GlobalLogger()
{
	if (os)
	{
		delete os;
	}
}

CREATE_STATIC_INSTANCE(GlobalLogger);
