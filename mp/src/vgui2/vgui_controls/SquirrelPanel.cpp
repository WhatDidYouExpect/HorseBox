#include "vgui_controls/SquirrelPanel.h"
extern ISquirrel* g_pSquirrel;
using namespace vgui;

SquirrelPanel::SquirrelPanel(SquirrelScript ownerscript, const char* _userdata) : script(ownerscript)
{
	paintFunction[0] = '\x00';
	strncpy(userdata, _userdata, sizeof(userdata));
}

const char* SquirrelPanel::GetUserdata()
{
	return userdata;
}

void SquirrelPanel::SetPaintFunction(const char* name)
{
	strncpy(paintFunction, name,sizeof(paintFunction));
}

void SquirrelPanel::SetOnKeyDownFunction(const char* name)
{
	strncpy(keyDownFunction, name, sizeof(keyDownFunction));
}

void SquirrelPanel::SetOnKeyUpFunction(const char* name)
{
	strncpy(keyUpFunction, name, sizeof(keyUpFunction));
}

void SquirrelPanel::SetOnMouseDownFunction(const char* name)
{
	strncpy(mouseDownFunction, name, sizeof(mouseDownFunction));
}

void SquirrelPanel::SetOnMouseUpFunction(const char* name)
{
	strncpy(mouseUpFunction, name, sizeof(mouseUpFunction));
}

void SquirrelPanel::OnMousePressed(MouseCode code)
{
	if (!mouseDownFunction[0])
		return;
	g_pSquirrel->CallFunction(script, mouseDownFunction, "ui", handle, code);
}
void SquirrelPanel::OnMouseReleased(MouseCode code)
{
	if (!mouseUpFunction[0])
		return;
	g_pSquirrel->CallFunction(script, mouseUpFunction, "ui", handle, code);
}
void SquirrelPanel::OnKeyCodePressed(KeyCode code)
{
	if (!keyDownFunction[0])
		return;
	g_pSquirrel->CallFunction(script, keyDownFunction, "ui", handle, code);
}
void SquirrelPanel::OnKeyCodeReleased(KeyCode code)
{
	if (!keyUpFunction[0])
		return;
	g_pSquirrel->CallFunction(script, keyUpFunction, "ui", handle, code);
}

void SquirrelPanel::Paint()
{
	if (!paintFunction[0])
		return;
	g_pSquirrel->CallFunction(script, paintFunction, "u", handle);
}