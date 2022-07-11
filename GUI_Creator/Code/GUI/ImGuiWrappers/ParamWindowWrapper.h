#pragma once
#include "../GUI_Creator/imgui/imgui.h"
#include "../GUI_Creator/imgui/imgui-SFML.h"

class ParamWindowWrapper
{

public:
	virtual void updateDearIMGUIParamWindow()=0;
};

