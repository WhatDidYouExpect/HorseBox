#ifndef MOUNTINGMENU_H
#define MOUNTINGMENU_H

#include "cbase.h"
#include <vgui/IVGui.h>
#include <vgui_controls/Frame.h>
#include <vgui_controls/CheckButtonList.h>

using namespace vgui;

class MountingMenu : public Frame
{
	DECLARE_CLASS_SIMPLE(MountingMenu, Frame);
public:
	MountingMenu(vgui::VPANEL parent);
	void OnTick();
	void OnClose();
	void PerformLayout();
private:
	CheckButtonList* gamelist;

};


extern MountingMenu* jb_mountingmenu;

#endif