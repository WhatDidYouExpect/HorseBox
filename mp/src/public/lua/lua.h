#ifndef LUA_H
#define LUA_H
#define INTERFACELUA_VERSION				"JBLua001"

typedef void* LuaScript;

enum LuaType
{
	LUA_INT,
	LUA_FLOAT,
	LUA_STRING,
	LUA_BOOL,

	LUA_INVALID // must be last
};

struct LuaValue  // I FUCKING LOVE TYPED UNIONS GRAAAAAAAAAAAAAAAAAAAH
{
	union
	{
		int val_int;
		float val_float;
		const char* val_string;
		bool val_bool;
	};
	LuaType type;
};

class ILua
{
public:
	virtual LuaScript LoadScript(const char* script) = 0;
	virtual LuaValue CallFunction(LuaScript script, const char* fun, const char* types, ...) = 0;
	virtual void ShutdownScript(LuaScript script) = 0;
};

#endif
