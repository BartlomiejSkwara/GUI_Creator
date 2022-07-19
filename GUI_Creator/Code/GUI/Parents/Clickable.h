#pragma once
#include "Bordered.h"
#include <functional>
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

    //Logika za wciskaniem obiektu
    virtual int updateClickables(sf::Vector2f& mousePosition)=0;
    //Aktywacja lambdy
    void runEvent();

 

    // Inherited via Bordered
    virtual void setPosition(const sf::Vector2i& position) override = 0;

    virtual void setPosition(int x, int y) override = 0;

    virtual void move(const sf::Vector2i& offset) override = 0;

    virtual void move(int x, int y) override = 0;

};

