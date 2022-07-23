#pragma once
#include <iostream>
#include <vector>
#include "Clickable.h"
#include "Identifiable.h"
#include "Renderable.h"

class Object :	
	virtual public Clickable,
	virtual public Identifiable,
	virtual public Renderable
{
private:


public:
	
	Object(const std::function<void()>& func = [](){});
	virtual ~Object();	

	


	// Inherited via Clickable //TODO make it more relatable to object then to clickable class
	virtual Object* updateClickables(sf::Vector2f& mousePosition) = 0;



};

