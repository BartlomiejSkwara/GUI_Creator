#pragma once
#include "BorderedObject.h"
#include <functional>
class ClickableObject :
    virtual public BorderedObject
{
private:
    //Lambda wykonywana po wcisnieciu
    std::function<void()> m_Event;
public:
    ClickableObject();
    ClickableObject(const std::function<void()>& func);
    virtual ~ClickableObject();

    //Zmiana zdarzenia
    void setEvent(const std::function<void()>& func);
    
    //Logika za wciskaniem obiektu
    virtual int updateClickables(sf::Vector2f& mousePosition)=0;
    //Aktywacja lambdy
    void runEvent();

 
};

