#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
class MouseInfo
{
private:
	static MouseInfo* mouseInfo;
	//This function has to be constantly running in game update to have info about mouse status pressing/clicking etc
	void updateMouseStatus();
	//This function is responsible for getting info about cursors position inside of window 
	void updateMousePosition();
	MouseInfo();
public:

	//Mouse positions
	sf::Vector2i mousePositionWindow;
	sf::Vector2f mousePositionView;
	sf::Vector2f mousePositionViewLastKnown;

	sf::RenderWindow* context;

	//Mouse status
	bool mouseHeld;
	bool mouseClicked;



	//All of the updates combined in one function
	void updateMouse();
	
	
	//Use this when setting up singleton for the first time 
	void setContext(sf::RenderWindow* contextWindow);

	//Use this whe 
	static MouseInfo* getMouseInf();
	
	
};

