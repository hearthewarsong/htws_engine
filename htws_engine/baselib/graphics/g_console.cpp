/*
 * GConsole.cpp
 *
 *  Created on: May 1, 2014
 *      Author: hearthewarsong
 */

#include "../baselib_all.h"

//#include "../baselib_all.h"

GConsole::GConsole(string fontName, int fontSize, unsigned cachedLines) :
		fontName(fontName), fontSize(fontSize), cachedLines(cachedLines), useFormating(false)
{
	// TODO Auto-generated constructor stub

}

GConsole::~GConsole()
{
	// TODO Auto-generated destructor stub
}

void GConsole::Write(const string& text)
{
	lines.push_back(StringHelper::UTF8to16(text.c_str()));
	if (lines.size() > cachedLines) lines.pop_front();
}
bool GConsole::Write(const wstring& text)
{
	lines.push_back(text);
	if (lines.size() > cachedLines) lines.pop_front();
	return true;
}
void GConsole::Write(const char* text)
{
	lines.push_back(StringHelper::UTF8to16(text));
	if (lines.size() > cachedLines) lines.pop_front();
}
void GConsole::Write(const wchar_t* text)
{
	lines.push_back(text);
	if (lines.size() > cachedLines) lines.pop_front();
}

bool GConsole::hasInput()
{
}

bool GConsole::hasOutput()
{
}

bool GConsole::isBlocking()
{
}

bool GConsole::setBlocking(bool value)
{
}

ProtEnums::Status GConsole::getStatus()
{
}

int GConsole::getLastError(string& text)
{
}

bool GConsole::Open(const string& arg0, const string& arg1)
{
}

void GConsole::Close()
{
}

bool GConsole::Reinit()
{
}

int GConsole::Read(wstring& str)
{
}

void GConsole::setAllowFormating(bool isAllowed)
{
	useFormating = isAllowed;
}
