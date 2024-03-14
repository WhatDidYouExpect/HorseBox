#include "lua.hpp"
#include "lua/lua.h"
#include "tier1/interface.h"

class CLua : public ILua
{
	virtual void LoadScript(const char* script);

};

EXPOSE_SINGLE_INTERFACE(CLua, ILua, INTERFACELUA_VERSION);