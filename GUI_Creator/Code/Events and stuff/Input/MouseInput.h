#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../ObserverStuff/Observer.h"
#include "../GUI_Creator/Code/GUI/Parents/Object.h"
#include <unordered_map>
class MouseInput
{
private:

	std::unordered_map<EventType, std::vector<Event>* >  m_eventsMap;

	//// Data stuff ////
	static MouseInput* mouseInput;

	//This function has to be constantly running in game update to have info about mouse status pressing/clicking etc
	void updateMouseStatus();
	//This function is responsible for getting info about cursors position inside of window 
	void updateMousePosition();
	MouseInput();
	//Last clicked obj
	Object* lastClickedObject;
	//Object* hoveredObject;

	////	////	////



	//// Observer stuff ////
	
	//Observer
	Observer* m_observer;
	void initBasicEvents();
	
	////	////	////






public:

	

	//// Data stuff ////

	//Mouse positions
	sf::Vector2i mousePositionWindow;
	sf::Vector2f mousePositionView;
	sf::Vector2f mousePositionViewLastKnown;

	sf::RenderWindow* context;

	//Mouse status
	bool mouseHeld;
	bool mouseClicked;


	//Last clicked obj
	void    setLastClickedObject(Object* obj);
	Object* getLastClickedObject();

	

	//Investigates current state of mouse input
	void updateMouse();


	//Use this when setting up singleton for the first time 
	void setContext(sf::RenderWindow* contextWindow);

	//Instantiates Mouse info or returns it
	static MouseInput* getMouseInf();

	////	////	////






	//// Observer stuff ////
	
	//Event stuff
	void addEvent(EventType type, const std::function<void()>& func = []() {}, EventScope scope = EventScope::ScopeObject);
	void addEvent(Event ev);
	void removeEvent(Event ev);
	void clearEventMap();
	
	//Notifies all of the subscribed observers that something happend
	void notify(EventType etype);

	void addObserver(Observer* obs);
	

	////	////	////


	
	

	
	
};

