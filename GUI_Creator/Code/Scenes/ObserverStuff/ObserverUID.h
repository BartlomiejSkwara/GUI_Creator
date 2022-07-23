#pragma once
#include "ObserverScene.h"
#include "../../Input/MouseInfo.h"
#include <iostream>

class ObserverUID :
    public ObserverScene
{
    // Inherited via ObserverScene
    virtual void onNotify(EventType event, Object* caller) override;
};

