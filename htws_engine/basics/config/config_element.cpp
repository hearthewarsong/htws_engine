/*
 * config_element..cpp
 *
 *  Created on: Dec 24, 2014
 *      Author: hearthewarsong
 */

#include "../basics_all.h"

ConfigElement::ConfigElement(const char* _text)
{
	_init(_text);
}

void ConfigElement::_init(const char* _text)
{
	text = _text;
	text = StringHelper::trim(text);
	if( text.empty() )
	{
		LLF(LLA_Config,"Error: Config option is empty");
	}
	if (text[0] == '@')
	{
		LLF(LLA_Config,"Error: Config lists not implemented yet");
	}
	else if (text[0] == '"')
	{
		v_string = text.substr(1,text.size()-2);
		type = TypeDouble;
	}
	else if (text[0] == 'f')
	{
		value.v_double = atof(text.c_str()+1);
		type = TypeDouble;
	}
	else if (text == "true" || text == "false")
	{
		if (text == "true")
		{
			value.v_bool = true;
		}
		else
		{
			value.v_bool = false;
		}
		type = TypeBool;
	}
	else
	{
		value.v_int = atoi(text.c_str());
		type = TypeInt;
	}
}

ConfigElement::~ConfigElement()
{
	// TODO Auto-generated destructor stub
}
