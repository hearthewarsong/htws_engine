/*
 * global_logger.h
 *
 *  Created on: Aug 9, 2014
 *      Author: hearthewarsong
 */

#ifndef GLOBAL_LOGGER_H_
#define GLOBAL_LOGGER_H_

class GlobalLogger : public Singleton<GlobalLogger>
{
	map<string,int> enabled;
	std::ofstream*  os;
	IWTextCommunicator * communicator;
public:
	GlobalLogger();
	void LogLine(const char* area, int level, const char* message);
	bool IsEnabled(const char* area, int level);
	void LogLine(const char* area, int level, const wchar_t* message);
	void EnableArea(const char* area, int level);
	void SetLoggerOutput(IWTextCommunicator * communicator);
	virtual ~GlobalLogger();
};

#ifndef HTWS_CONFIG_MAX_LOG_LEVEL
#	define HTWS_CONFIG_MAX_LOG_LEVEL 5
#endif

#define LL(area,level,message)  { \
	if ( GlobalLogger::GetInstance()->IsEnabled(area,level)) \
		GlobalLogger::GetInstance()->LogLine(area,level,message);\
}


#if HTWS_CONFIG_MAX_LOG_LEVEL >= 0
#	define LLFM(message) LL("main",0, message)
#	define LLF(area, message) LL(area, 0, message)
#else
#	define LLFM(message)
#	define LLF(area, message)
#endif

#if HTWS_CONFIG_MAX_LOG_LEVEL >= 1
#	define LL1M(message) LL("main",1, message)
#	define LL1(area, message) LL(area, 1, message)
#else
#	define LL1M(message)
#	define LL1(area, message)
#endif

#if HTWS_CONFIG_MAX_LOG_LEVEL >= 2
#	define LL2M(message) LL("main",2, message)
#	define LL2(area, message) LL(area, 2, message)
#else
#	define LL2M(message)
#	define LL2(area, message)
#endif

#if HTWS_CONFIG_MAX_LOG_LEVEL >= 3
#	define LL3M(message) LL("main",3, message)
#	define LL3(area, message) LL(area, 3, message)
#else
#	define LL3M(message)
#	define LL3(area, message)
#endif

#if HTWS_CONFIG_MAX_LOG_LEVEL >= 4
#	define LL4M(message) LL("main",4, message)
#	define LL4(area, message) LL(area, 4, message)
#else
#	define LL4M(message)
#	define LL4(area, message)
#endif

#if HTWS_CONFIG_MAX_LOG_LEVEL >= 5
#	define LL5M(message) LL("main",5, message)
#	define LL5(area, message) LL(area, 5, message)
#else
#	define LL5M(message)
#	define LL5(area, message)
#endif


#endif /* GLOBAL_LOGGER_H_ */
