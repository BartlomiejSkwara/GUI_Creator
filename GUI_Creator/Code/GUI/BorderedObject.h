#pragma once
#include "IdentifiableObject.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
//Dodaj do niego funkcje od zmiany koloru cia�a i borderu i konstruktor kt�ry mo�e te� to zrobi�
class BorderedObject :
    virtual public IdentifiableObject
{

private:

public:
    virtual ~BorderedObject();
    //Funkcja zwraca wymiary danego obiektu
    virtual const sf::FloatRect & getGlobalBounds() const = 0;
    //Funkcja sprawdza czy kursor lub punkt jest wewn�trz obiektu;
    virtual bool checkIfObjectContainsPoint(sf::Vector2f& point) = 0;

    virtual void setPosition(const sf::Vector2i& position) = 0;
    virtual void setPosition(int x, int y) = 0;

    virtual void move(const sf::Vector2f& offset) = 0;
};

