#pragma once
#include "BorderedObject.h"
#include <SFML/Graphics/RenderTarget.hpp>

class RenderableObject
	: virtual public BorderedObject
{
private:
public:
	virtual ~RenderableObject();
	//Funkcja renderuje obiekt
	virtual void render(sf::RenderTarget* target) = 0;


};

