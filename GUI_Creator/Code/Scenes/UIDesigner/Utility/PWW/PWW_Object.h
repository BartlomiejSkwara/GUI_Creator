#pragma once
#include "../GUI_Creator/imgui/imgui.h"
#include "../GUI_Creator/imgui/imgui-SFML.h"
#include "../FocusManager.h"
#include "../GUI_Creator/Code/ResourceManaging/ResourceManager.h"

#define MAX_OBJ_TYPE_LENGTH 15
#define MAX_ID_LENGTH 5
#define DRAG_SPEED 0.025
class PWW_Object
{
protected:
    ResourceManager* resourceManager;

public:
    PWW_Object(Object*editedObject);
    float m_fillColor[4];
    int   m_position[2];

    float m_scale[2];
    int   m_size[2];
    int   m_outline_size;
    float m_outlineColor[4];
	virtual void updateDearIMGUIParamWindow()=0;

};

