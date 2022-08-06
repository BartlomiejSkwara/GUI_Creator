#pragma once
#include <iostream>
#include <vector>
#include "../GUI_Creator/Code/Events and stuff/EventsHandling/EventHandler.h"
#include "Identifiable.h"
#include "Renderable.h"
#include "Bordered.h"
#include "../GUI_Creator/Code/ResourceManaging/ResourceManager.h"

enum class FindMode {
	FIND_AND_DO_NOTHING = -1,
	FIND_AND_REMOVE     = 0,
	FIND_AND_MOVE_UP    = 1,
	FIND_AND_MOVE_DOWN  = 2
};

class Object :	
	virtual public EventHandler,
	virtual public Identifiable,
	virtual public Renderable,
	virtual public Bordered
{
private:


public:
	
	Object();
	virtual ~Object();	

	


	// Inherited via Clickable //TODO make it more relatable to object then to clickable class
	virtual Object* updateClickables(sf::Vector2f& mousePosition) = 0;
	

	virtual void setScale(float x, float y) = 0;
	virtual std::pair<float, float> getScale() = 0;

	//Used to search for certain object (obj is returned if found)
	virtual Object* find(Object* soughtObj, FindMode fm = FindMode::FIND_AND_DO_NOTHING);



	// Inherited via EventHandler
	virtual bool handleEvent(Event& event) = 0;

};

