/*
 * lua_instance.h
 *
 *  Created on: Oct 13, 2014
 *      Author: hearthewarsong
 */

#ifndef LUA_INSTANCE_H_
#define LUA_INSTANCE_H_

class LuaInstance
{
protected:
	lua_State* state;
public:

	LuaInstance();
	void Test();
	//void AddFunction(const char* name, );
	virtual ~LuaInstance();
};

#endif /* LUA_INSTANCE_H_ */
