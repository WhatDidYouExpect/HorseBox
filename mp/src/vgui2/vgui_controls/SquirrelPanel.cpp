#include "vgui_controls/SquirrelPanel.h"
extern ISquirrel* g_pSquirrel;
using namespace vgui;

SquirrelPanel::SquirrelPanel(SquirrelScript ownerscript, SquirrelHandle* _handle) : script(ownerscript), handle(_handle)
{
	paintFunction[0] = '\x00';
}

void SquirrelPanel::SetPaintFunction(const char* name)
{
	strncpy(paintFunction, name,sizeof(paintFunction));
}

void SquirrelPanel::Paint()
{
	if (!paintFunction[0])
		return;
	g_pSquirrel->CallFunction(script, paintFunction, "u", handle);
}