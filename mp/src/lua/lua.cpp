#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "public/lua/lua.h"
#include "tier1/interface.h"

class CLua : public ILua
{
public:
	virtual LuaScript LoadScript(const char* script);
	virtual LuaValue CallFunction(LuaScript script, const char* fun, const char* types, ...);
	virtual void ShutdownScript(LuaScript script);
};

LuaScript CLua::LoadScript(const char* script)
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	luaL_loadstring(L,script);
	if (lua_pcall(L, 0, 0, 0))
	{
		return 0;
	}
	return (LuaScript)L;
}

LuaValue CLua::CallFunction(LuaScript script, const char* fun, const char* types, ...)
{
	LuaValue ret;
	ret.type = LUA_INVALID;
	lua_State* L = (lua_State*)script;
	lua_getglobal(L, fun);
	if (lua_type(L, -1) != LUA_TFUNCTION)
	{
		return ret;
	}
	va_list args;
	va_start(args, types);
	int count = strlen(types);
	for (int i = 0; i < count; ++i)
	{
		switch (types[i])
		{
		case 'i':
			lua_pushinteger(L, va_arg(args, int));
			break;
		case 'b':
			lua_pushboolean(L, va_arg(args, bool));
			break;
		case 's':
			lua_pushstring(L, va_arg(args, const char*));
			break;
		case 'f':
			lua_pushnumber(L, va_arg(args, float));
			break;
		default:
			lua_pushnil(L);
			break;
		}
	}
	if (lua_pcall(L, count, 1, 0))
	{
		return ret;
	}
	if (lua_isstring(L, -1))
	{
		ret.type = LUA_STRING;
		ret.val_string = lua_tolstring(L, -1, 0);
	}
	else if (lua_isinteger(L, -1))
	{
		ret.type = LUA_INT;
		ret.val_int = lua_tointeger(L, -1);
	}
	else if (lua_isnumber(L, -1))
	{
		ret.type = LUA_FLOAT;
		ret.val_float = lua_tonumber(L, -1);
	}
	else if (lua_isboolean(L, -1))
	{
		ret.type = LUA_BOOL;
		ret.val_bool = (bool)lua_toboolean(L, -1);
	}

	return ret;
}
void CLua::ShutdownScript(LuaScript script)
{
	lua_State* L = (lua_State*)script;
	lua_close(L);
}

EXPOSE_SINGLE_INTERFACE(CLua, ILua, INTERFACELUA_VERSION);