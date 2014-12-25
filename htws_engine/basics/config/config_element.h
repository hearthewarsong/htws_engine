/*
 * config_element.h
 *
 *  Created on: Dec 24, 2014
 *      Author: hearthewarsong
 */

#ifndef CONFIG_ELEMENT_H_
#define CONFIG_ELEMENT_H_

class ConfigElement
{
public:
	enum Type
	{
		TypeString = 0,
		TypeInt = 1,
		TypeDouble = 2,
		TypeBool = 3,
		TypeStringList = 4,
		TypeIntList = 5,
		TypeDoubleList = 6,
		TypeBoolList = 7
	};
protected:
	Type type;
	string text;
	typedef union DataValue
	{
	    int v_int;
	    double v_double;
	    bool v_bool;
	} DataValue;
    string v_string;
    vector<int> v_intlist;
	DataValue value;
	void _init(const char* _text);
public:
	ConfigElement() { _init("\"\""); }
	Type GetType() const { return type; }
	ConfigElement(const char* _text);
	ConfigElement(const string&  _text) { _init(_text.c_str()); }
	virtual ~ConfigElement();
	int GetDouble() const { return value.v_double;}
	int GetInt() const { return value.v_int;}
	bool GetBool() const { return value.v_bool; }
	const string& GetString() const { return v_string; }
	const wstring GetWString() const  { return StringHelper::UTF8to16(v_string.c_str()); }
	//const vector<int>& GetIntList() { return value.v_intlist; }
};

#endif /* CONFIG_ELEMENT_H_ */
