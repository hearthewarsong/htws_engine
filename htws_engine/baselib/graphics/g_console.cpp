/*
 * GConsole.cpp
 *
 *  Created on: May 1, 2014
 *      Author: hearthewarsong
 */

#include "../baselib_all.h"

//#include "../baselib_all.h"

GConsole::GConsole(string fontName, int fontSize, unsigned cachedLines) :
WindowImpl(string("Console")), fontName(fontName), fontSize(fontSize), cachedLines(
				cachedLines), useFormating(false)
{
	// TODO Auto-generated constructor stub
	outputControl = new TextControl();
	outputControl->SetFontSize(fontSize);
	outputControl->SetColor(Color(0.0,0.0,1.0));
	outputControl->SetWordWrap(GetSize().x);
	AddChildren(outputControl);
	status = ProtEnums::Connected;
	lines.push_back(wstring());
}

GConsole::~GConsole()
{
	// TODO Auto-generated destructor stub
}

void GConsole::Write(const string& text)
{
	_write(StringHelper::UTF8to16(text.c_str()).c_str());
}
bool GConsole::Write(const wstring& text)
{
	_write(text.c_str());
	return true;
}
void GConsole::Write(const char* text)
{
	_write(StringHelper::UTF8to16(text).c_str());;
}
void GConsole::Write(const wchar_t* text)
{
	_write(text);
}


void GConsole::_write(const wchar_t* text)
{
	int currentCharIndex = 0;
	while (text[currentCharIndex] != L'\0')
	{
		if (text[currentCharIndex] == L'\n')
		{
			lines.back().append(text,currentCharIndex);
			lines.push_back(wstring());
			text += currentCharIndex + 1;
			currentCharIndex = 0;
		}
		else
		{
			++currentCharIndex;
		}
	}
	if (currentCharIndex!= 0)
	{
		lines.back().append(text);
	}
	while (lines.size() > cachedLines)
	{
		lines.pop_front();
	}
	_refreshLines();
}
bool GConsole::hasInput()
{
	//TODO implement it;
	return false;
}

bool GConsole::hasOutput()
{
	return true;
}

bool GConsole::isBlocking()
{
	//TODO implement input
	return false;
}

bool GConsole::setBlocking(bool value)
{
	//TODO implement it
	return false;
}

ProtEnums::Status GConsole::getStatus()
{
	return status;
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
	return false;
}

int GConsole::Read(wstring& str)
{
	//TODO implement it;
	return 0;
}

void GConsole::setAllowFormating(bool isAllowed)
{
	useFormating = isAllowed;
}

void GConsole::_refreshLines()
{
	outputControl->SetWordWrap(this->GetSize().x);
	wstring displayedData;
	int lineNumber = 0;
	deque<wstring>::iterator fromIt = lines.begin();
	for(deque<wstring>::reverse_iterator it = lines.rbegin(); it != lines.rend() ; ++it)
	{
		lineNumber += outputControl->GetLineCountIfWrapped(*it);
		if (lineNumber > _getLineNumber())
		{
			fromIt = it.base();
			fromIt++;
		}
	}
	for(;fromIt != lines.end(); ++fromIt)
	{
		displayedData.append(*fromIt);
		if (fromIt +1 != lines.end())
		{
			displayedData.append(L"\n");
		}
	}
	outputControl->SetText(displayedData);
}

int GConsole::_getLineNumber()
{
	return GetSize().y / fontSize;
}
