#ifndef SQUIRREL_H
#define SQUIRREL_H
#define INTERFACESQUIRREL_VERSION				"JBSquirrel001"

typedef void* SquirrelScript;

enum SquirrelType
{
	SQUIRREL_INT,
	SQUIRREL_FLOAT,
	SQUIRREL_STRING,
	SQUIRREL_BOOL,

	SQUIRREL_INVALID // must be last
};

struct SquirrelValue  // I FUCKING LOVE TYPED UNIONS GRAAAAAAAAAAAAAAAAAAAH
{
	union
	{
		int val_int;
		float val_float;
		const char* val_string;
		bool val_bool;
	};
	SquirrelType type;
};

typedef int (*SquirrelFunction)(SquirrelScript);
typedef void* (*SquirrelAllocator) (void* ud, void* ptr, size_t osize, size_t nsize);

class ISquirrel
{
public:
	virtual SquirrelScript LoadScript(const char* script, SquirrelAllocator allocator) = 0;
	virtual SquirrelValue CallFunction(SquirrelScript script, const char* fun, const char* types, ...) = 0;
	virtual void ShutdownScript(SquirrelScript script) = 0;
	virtual void AddFunction(SquirrelScript script, const char* name, SquirrelFunction fun) = 0;
	virtual bool GetArgs(SquirrelScript script, const char* types, ...) = 0;
	virtual void PushValue(SquirrelScript script, SquirrelValue val) = 0;

};

#endif
