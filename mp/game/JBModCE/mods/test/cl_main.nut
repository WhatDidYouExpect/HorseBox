function DrawEpicPanel(panel)
{
	if(GetConvar("cl_showepicbutton") == "1")
	{
		VGUISetMouseInputEnabled(panel,true);
		ExecuteConsoleCommand("cl_showepicbutton 0");
	}
	if(GetConvar("cl_hideepicbutton") == "1")
	{
		VGUISetMouseInputEnabled(panel,false);
		VGUISetKeyBoardInputEnabled(panel,false);
		ExecuteConsoleCommand("cl_hideepicbutton 0");
	}
}

function EpicPress(panel, code)
{
	ExecuteConsoleCommand("ent_create prop_physics model models/props_c17/furnituretable002a.mdl");
}

function LevelInitPreEntity()
{
	ExecuteConsoleCommand("setinfo cl_showepicbutton 0");
	ExecuteConsoleCommand("setinfo cl_hideepicbutton 0");
	local th = VGUICreatePanel();
	VGUISetBounds(th,16,16,50,42);
	VGUISetPaintFunction(th,"DrawEpicPanel");
	VGUISetOnMouseDownFunction(th,"EpicPress");
	VGUIMakePopup(th);
	VGUISetMouseInputEnabled(th,false);
}