#pragma once
#include "IdentifiableObject.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Color.hpp>
//Dodaj do niego funkcje od zmiany koloru cia³a i borderu i konstruktor który mo¿e te¿ to zrobiæ
class BorderedObject :
    virtual public IdentifiableObject
{

private:

public:
    virtual ~BorderedObject();

    //Funkcja sprawdza czy kursor lub punkt jest wewn¹trz obiektu;
    virtual bool checkIfObjectContainsPoint(sf::Vector2f& point) = 0;

   
    //Funkcja zwraca wymiary danego obiektu
    virtual const sf::FloatRect& getGlobalBounds() const = 0;
    virtual const sf::Color* getColorBorder() const = 0;
    virtual const sf::Color* getColorFill() const   = 0;
    virtual int  getBorderThickness() = 0;

    virtual void setColorBorder(int r, int g, int b, int a) = 0;
    virtual void setColorFill(int r, int g, int b, int a)   = 0;
    virtual void setPosition(const sf::Vector2i& position)  = 0;
    virtual void setPosition(int x, int y) = 0;
    virtual void setBorderThickness(int v) = 0;

    virtual void move(const sf::Vector2f& offset) = 0;
};

