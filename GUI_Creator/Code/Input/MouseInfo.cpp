#include "MouseInfo.h"
#include <SFML/Window/Mouse.hpp>

MouseInfo* MouseInfo::mouseInfo = nullptr;
void MouseInfo::updateMouseStatus()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        if (mouseHeld == false)
        {
            //std::cout<<"Sone pressed the mouse\n";
            mouseClicked = true;
            mouseHeld = true;
        }
        else
        {
            //std::cout << "Mouse is being held\n";
            mouseClicked = false;
        }

    }
    else
    {
        //std::cout << "Sone released the mouse\n";
        mouseHeld = false;
    }
}
void MouseInfo::updateMousePosition()
{
    mousePositionWindow = sf::Mouse::getPosition(*context);
    mousePositionViewLastKnown = mousePositionView;
    mousePositionView = context->mapPixelToCoords(mousePositionWindow);
}
MouseInfo::MouseInfo()
{
    mouseHeld = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}
void MouseInfo::updateMouse()
{
    updateMouseStatus();
    updateMousePosition();
}
void MouseInfo::setContext(sf::RenderWindow* contextWindow)
{
    this->context = contextWindow;
}
MouseInfo* MouseInfo::getMouseInf()
{
	if (!mouseInfo)
	{
		mouseInfo = new MouseInfo();
	}
	return mouseInfo;
}
