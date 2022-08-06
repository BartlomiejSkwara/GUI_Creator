#pragma once
#include "Event.h"
#include "HandlerFlags.h"
#include <unordered_map>

class EventHandler
{
protected:
    std::unordered_map<EventType,Event> m_events;
public:

    EventHandler();
    ~EventHandler();

    //Change lambda
    void setEvent(Event ev);


    //Handles events
    virtual bool handleEvent(Event& event) = 0;
    
    //Runs local and/or global event depending on events scope 
    void runEvent(Event& event);
};

