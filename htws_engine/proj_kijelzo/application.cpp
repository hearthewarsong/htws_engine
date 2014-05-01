/*
 * Application.cpp
 *
 *  Created on: Apr 19, 2014
 *      Author: hearthewarsong
 */

#include "proj_kijelzo_all.h"

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
