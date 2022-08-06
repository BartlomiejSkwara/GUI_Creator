#pragma once

#include <iostream>
#include "EventHandler.h"

/// <summary>
/// For now all events are handled by normal Event handler , this class is still left in case of quick multiplication of event types
/// </summary>
class MouseEventHandler : public EventHandler
{
private:

public:

    MouseEventHandler(EventType type, const std::function<void()>& func = []() {}, EventScope scope = EventScope::ScopeObject);
    virtual ~MouseEventHandler();
    
   
  
    //virtual void handle(Event passedEvent) = 0;


    //Common interface with other event handler classe
    virtual bool handleEvent(Event& event) override = 0;

    //Class specific events handler
    virtual bool handleMouseEvent(Event& event) = 0;


};

