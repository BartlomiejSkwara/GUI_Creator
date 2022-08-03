#pragma once
#include "ObserverScene.h"
#include "../../Input/MouseInfo.h"
#include "../UIDesigner/Utility/SelectionManager.h"
#include <iostream>
#include "../GUI_Creator/imgui/imgui.h"
#include "../GUI_Creator/imgui/imgui-SFML.h"

class ObserverUID :
    public ObserverScene
{
    // Inherited via ObserverScene
    virtual void onNotify(EventType event, Object* caller) override;
};

