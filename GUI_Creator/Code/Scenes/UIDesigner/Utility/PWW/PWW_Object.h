#pragma once
#include "../GUI_Creator/imgui/imgui.h"
#include "../GUI_Creator/imgui/imgui-SFML.h"
#include "../SelectionManager.h"
#define MAX_LABEL_LENGTH 15
#define MAX_OBJ_TYPE_LENGTH 15
#define MAX_ID_LENGTH 5
class PWW_Object
{
protected:
    SelectionManager* selectManager;

public:
    PWW_Object();
    float m_selectionIndicatorSize;
    float m_signifierColor[4];


    float m_fillColor[4];
    int   m_position[2];

    int   m_outline_size;
    float m_outlineColor[4];
    float m_scale;
	virtual void updateDearIMGUIParamWindow()=0;
};

