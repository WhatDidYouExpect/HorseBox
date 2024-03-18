#ifndef SQUIRRELPANEL_H
#define SQUIRRELPANEL_H

#ifdef _WIN32
#pragma once
#endif

#include <vgui_controls/Panel.h>
#include "squirrel/squirrel.h"

namespace vgui
{
	class SquirrelPanel : public Panel
	{
		DECLARE_CLASS_SIMPLE(SquirrelPanel, Panel);
	public:
		SquirrelPanel(SquirrelScript ownerscript, SquirrelHandle* _handle);
		virtual void Paint();
		void SetPaintFunction(const char* name);
	private:
		SquirrelScript script;
		SquirrelHandle* handle;
		char paintFunction[256];
	};
}

#endif