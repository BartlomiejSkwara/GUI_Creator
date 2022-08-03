#pragma once
#include "Bordered.h"
#include <functional>
#include <iostream>
class Clickable :
    virtual public Bordered
{
private:
    //Lambda wykonywana po wcisnieciu
    std::function<void()> m_Event;
public:

    Clickable(const std::function<void()>& func = [](){});
    virtual ~Clickable();

    //Zmiana zdarzenia
    void setEvent(const std::function<void()>& func);
    
    //Funkcja sprawdza czy kursor lub punkt jest wewn¹trz obiektu;
    bool checkIfObjectContainsPoint(sf::Vector2f& point);


    //Aktywacja lambdy
    void runEvent();

  


};

