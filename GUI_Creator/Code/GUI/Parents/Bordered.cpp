#include "Bordered.h"

Bordered::Bordered()
{
}

Bordered::~Bordered()
{
}


/// <summary>
/// Funkcaj sprawdza czy dany punkt znajduje si� w 
/// </summary>
/// <param name="point"></param>
/// <returns></returns>
bool Bordered::checkIfObjectContainsPoint(sf::Vector2f& point)
{
	return  (getGlobalBounds().contains(point.x, point.y));
}


const sf::FloatRect& Bordered::getGlobalBounds() const
{
	return m_frame.getGlobalBounds();
}

const sf::Color* Bordered::getColorBorder() const
{
	return &(m_frame.getOutlineColor());
}

const sf::Color* Bordered::getColorFill() const
{
	return &(m_frame.getFillColor());
}

int Bordered::getBorderThickness()
{
	return m_frame.getOutlineThickness();
}



void Bordered::setBorderSize(int x, int y)
{
	m_frame.setSize(sf::Vector2f((float)x, (float)y));
}



void Bordered::setColorBorder(int r, int g, int b, int a)
{
	m_frame.setOutlineColor(sf::Color(r, g, b, a));
}

void Bordered::setColorFill(int r, int g, int b, int a)
{
	m_frame.setFillColor(sf::Color(r, g, b, a));
}

void Bordered::setBorderThickness(int v)
{
	m_frame.setOutlineThickness(v);
}

