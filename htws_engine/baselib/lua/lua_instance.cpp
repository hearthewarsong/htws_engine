#include "../baselib_all.h"

LuaInstance::LuaInstance()
{
	  state =  luaL_newstate();
	// load Lua libraries
	static const luaL_Reg lualibs[] =
	{
		{ "base", luaopen_base },
		{ NULL, NULL}
	};

	const luaL_Reg *lib = lualibs;
	for(; lib->func != NULL; lib++)
	{
		lib->func(state);
		lua_settop(state, 0);
	}
}

void LuaInstance::Test()
{
	luaL_dostring(state,"print('Hello World!')");
}

LuaInstance::~LuaInstance()
{
	lua_close(state);
}

