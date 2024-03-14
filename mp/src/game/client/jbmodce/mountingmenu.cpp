#include "cbase.h"

#include "mountingmenu.h"

ConVar cl_showmountingmenu("cl_showmountingmenu", "0", FCVAR_CLIENTDLL, "Shows or hides the mounting menu");

MountingMenu* jb_mountingmenu;

MountingMenu::MountingMenu(vgui::VPANEL parent) : Frame(NULL, "MountingMenu")
{
	SetParent(parent);

	SetKeyBoardInputEnabled(true);
	SetMouseInputEnabled(true);

	SetProportional(false);
	SetTitleBarVisible(true);
	SetMinimizeButtonVisible(false);
	SetMaximizeButtonVisible(false);
	SetCloseButtonVisible(true);
	SetSizeable(true);
	SetMoveable(true);
	SetVisible(true);


	SetScheme(vgui::scheme()->LoadSchemeFromFile("resource/SourceScheme.res", "SourceScheme"));

	LoadControlSettings("resource/UI/mypanel.res");

	vgui::ivgui()->AddTickSignal(GetVPanel(), 100);

	gamelist = new CheckButtonList(this, "gamelist");
	KeyValues* kv = new KeyValues("Games");
	gamelist->AddItem("Portal", false, kv);
	gamelist->AddItem("Team Fortress 2", false, kv);
	gamelist->AddItem("Counter-Strike: Source", false, kv);

}

void MountingMenu::OnTick()
{
	BaseClass::OnTick();
	SetVisible(cl_showmountingmenu.GetBool());
}

void MountingMenu::OnClose()
{
	cl_showmountingmenu.SetValue(0);
}

void MountingMenu::PerformLayout()
{
	gamelist->SetBounds(16, 32, 200, 200);
}