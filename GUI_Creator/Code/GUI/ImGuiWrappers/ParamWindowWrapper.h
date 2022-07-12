#pragma once
#include "../GUI_Creator/imgui/imgui.h"
#include "../GUI_Creator/imgui/imgui-SFML.h"

class ParamWindowWrapper
{
protected:
    static float s_selectionIndicatorSize;
    static float s_signifierColor[4];


    static float s_fillColor[4];
    static int   s_position[2];

    static int   s_outline_size;
    static float s_outlineColor[4];

public:
	virtual void initVariables() = 0;
	virtual void updateDearIMGUIParamWindow()=0;
};

