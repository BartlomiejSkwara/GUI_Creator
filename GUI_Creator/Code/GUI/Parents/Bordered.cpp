#include "Bordered.h"

Bordered::Bordered()
{
}

Bordered::~Bordered()
{
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

