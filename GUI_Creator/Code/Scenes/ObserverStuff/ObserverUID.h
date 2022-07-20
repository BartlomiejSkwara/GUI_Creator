#pragma once
#include "ObserverScene.h"
class ObserverUID :
    public ObserverScene
{
    // Inherited via ObserverScene
    virtual void onNotify(EventType event) override;
};

