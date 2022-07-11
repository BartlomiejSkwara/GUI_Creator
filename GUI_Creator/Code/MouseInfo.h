#pragma once
#include <SFML/System/Vector2.hpp>
struct MouseInfo
{
	//Mouse positions
	sf::Vector2i mousePositionWindow;
	sf::Vector2f mousePositionView;
	sf::Vector2f mousePositionViewLastKnown;


	//Mouse status
	bool mouseHeld;
	bool mouseClicked;

};
