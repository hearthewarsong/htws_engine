#include "application.h"

#ifdef PROJECT_KIJELZO

#include <iostream>
#include <map>
#include <string>
#include <utility>

#include "../basics/file/text_file_reader.h"
#include "../basics/string/string_helper.h"
#include "../basics/templates/basics_macros.h"
//#include "proj_kijelzo_all.h"

Application::Application()
{
	// TODO Auto-generated constructor stub

}

Application::~Application()
{
	// TODO Auto-generated destructor stub
}

void Application::Init(char** args, int argc)
{
}

void Application::Run()
{
	TextFileReader reader("replaces.txt");
	typedef map<wstring,wstring> dictionary;
	map<wstring,wstring> lines;
	if (reader.GetContent(lines))
	{
		foreach(dictionary,lines,it)
		{
			std::cout << StringHelper::UTF16to8(it->first.c_str()) << " = " << StringHelper::UTF16to8(it->second.c_str()) << std::endl;
		}
	}
	else
	{
		std::cout << "fail" << std::endl;
	}
	std::cout << "Ujra fxoryyyyyydul" << std::endl;
}

#endif /* PROJECT_KIJELZO */
