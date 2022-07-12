#include "ButtonObject.h"

///Przyda³aby siê tu jakaœ dokumentacja 
ButtonObject::ButtonObject(std::string ID, sf::Font& font,std::string label ,float positionX, float positionY, const std::function<void()>& func, float sizeX, float sizeY, int charSize, float scale)
	:IdentifiableObject(ID), ClickableObject(func)
{
	
	m_frame.setSize(sf::Vector2f(sizeX * scale, sizeY * scale));
	m_frame.setOutlineColor(sf::Color::White);
	m_frame.setOutlineThickness(3.f);
	m_frame.setFillColor(sf::Color(120, 120, 120, 255));

	m_text.setCharacterSize((unsigned int)(charSize * scale));

	initText(font, label);
	setPosition(positionX,positionY);
}

ButtonObject::~ButtonObject()
{

}

const sf::FloatRect& ButtonObject::getGlobalBounds() const
{
	return m_frame.getGlobalBounds();
}

bool ButtonObject::checkIfObjectContainsPoint(sf::Vector2f& point)
{
	return  (getGlobalBounds().contains(point.x,point.y));
}

void ButtonObject::render(sf::RenderTarget* target)
{
	target->draw(this->m_frame);
	target->draw(this->m_text);
}

int ButtonObject::updateClickables(sf::Vector2f& mousePosition)
{
	runEvent();
	return 1;
}

const sf::Color* ButtonObject::getColorBorder() const
{

	return &(m_frame.getOutlineColor());
}

const sf::Color* ButtonObject::getColorFill() const
{
	return &(m_frame.getFillColor());
}

const sf::Color* ButtonObject::getColorText() const
{
	return &(m_text.getFillColor());
}

std::string ButtonObject::getLabel()
{
	
	return m_text.getString().toAnsiString();
}

sf::Text* ButtonObject::getText()
{
	return &m_text;
}

void ButtonObject::setColorBorder(int r, int g, int b, int a)
{
	m_frame.setOutlineColor(sf::Color(r,g,b,a));
}

void ButtonObject::setColorFill(int r, int g, int b, int a)
{

	m_frame.setFillColor(sf::Color(r, g, b, a));
}

void ButtonObject::setColorText(int r, int g, int b, int a)
{

	m_text.setFillColor(sf::Color(r, g, b, a));
}

int ButtonObject::getBorderThickness()
{
	return m_frame.getOutlineThickness();
}

void ButtonObject::setBorderThickness(int v)
{
	m_frame.setOutlineThickness((float)v);
}




/// <summary>
/// Funkcja ustawia pozycjê obiektu na inn¹
/// </summary>
/// <param name="position"></param>
void ButtonObject::setPosition(const sf::Vector2i& position)
{
	setPosition(position.x, position.y);
}

void ButtonObject::setPosition(int x, int y)
{
	float thick = m_frame.getOutlineThickness();
	m_frame.setPosition(x+thick,y+thick);
	centerText();
}

/// <summary>
/// Funkcja przesuwa obiekt 
/// </summary>
/// <param name="offset"></param>
void ButtonObject::move(const sf::Vector2f& offset)
{
	m_frame.move(offset);
	m_text.move(offset);

}

void ButtonObject::centerText()
{
	sf::Vector2f center(m_text.getGlobalBounds().width / 2.f, m_text.getGlobalBounds().height / 2.f);
	sf::Vector2f localBounds(trunc(center.x + m_text.getLocalBounds().left), trunc(center.y + m_text.getLocalBounds().top));

	m_text.setOrigin(localBounds);

	m_text.setPosition(sf::Vector2f(m_frame.getSize().x / 2,
		m_frame.getSize().y / 2));

	m_text.setPosition(sf::Vector2f(
		trunc(m_frame.getOrigin().x + m_frame.getGlobalBounds().left + m_frame.getGlobalBounds().width / 2),
		trunc(m_frame.getOrigin().y + m_frame.getGlobalBounds().top + m_frame.getGlobalBounds().height / 2)));
}

/// <summary>
/// Funkcja inicjalizuje tekst na przycisku tj. ustwia mu stringa i zmienia czcionkê . Dodatkowo Wyœrodkowuje napis wzglêdem przycisku
/// </summary>
/// <param name="font"></param>
/// <param name="label"></param>
void ButtonObject::initText(sf::Font& font, const std::string& label)
{
	m_text.setFont(font);
	initText(label);

}

void ButtonObject::initText(const std::string& label)
{
	
	m_text.setString(label);
	centerText();

}


