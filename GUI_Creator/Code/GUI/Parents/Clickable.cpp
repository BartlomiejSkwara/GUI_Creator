#include "Clickable.h"



Clickable::Clickable(const std::function<void()>& func)
	:m_Event(func)
{
}

Clickable::~Clickable()
{
}

void Clickable::setEvent(const std::function<void()>& func)
{
	m_Event = func;
}


/// <summary>
/// Funkcaj sprawdza czy dany punkt znajduje siê w 
/// </summary>
/// <param name="point"></param>
/// <returns></returns>
bool Clickable::checkIfObjectContainsPoint(sf::Vector2f& point)
{
	return  (getGlobalBounds().contains(point.x, point.y));
}


void Clickable::runEvent()
{
	m_Event();
}



