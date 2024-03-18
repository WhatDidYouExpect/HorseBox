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
		void SetOnKeyDownFunction(const char* name);
		void SetOnKeyUpFunction(const char* name);
		void SetOnMouseDownFunction(const char* name);
		void SetOnMouseUpFunction(const char* name);

		virtual void OnMousePressed(MouseCode code);
		virtual void OnMouseReleased(MouseCode code);
		virtual void OnKeyCodePressed(KeyCode code);
		virtual void OnKeyCodeReleased(KeyCode code);

	private:
		SquirrelScript script;
		SquirrelHandle* handle;
		char paintFunction[256];
		char keyDownFunction[256];
		char keyUpFunction[256];
		char mouseDownFunction[256];
		char mouseUpFunction[256];
	};
}

#endif