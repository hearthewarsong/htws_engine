/*
 * string_helper.h
 *
 *  Created on: Apr 19, 2014
 *      Author: hearthewarsong
 */

#ifndef STRING_HELPER_H_
#define STRING_HELPER_H_

class StringHelper
{
public:
	StringHelper();
	virtual ~StringHelper();

	static string &ltrim(string &s);
	static string &rtrim(string &s);
	static string &trim(string &s);

	static wstring &ltrim(wstring &s);
	static wstring &rtrim(wstring &s);
	static wstring &trim(wstring &s);

	static string UTF16to8(const wchar_t * in);
	static wstring UTF8to16(const char * in);

};

#endif /* STRING_HELPER_H_ */
