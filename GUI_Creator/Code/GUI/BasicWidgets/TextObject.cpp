#include "TextObject.h"

///Przyda³aby siê tu jakaœ dokumentacja :>
TextObject::TextObject(const std::string& fontName ,std::string label ,float positionX, float positionY, const std::function<void()>& func, float sizeX, float sizeY, int charSize, float scale)
	:Object(func), m_fontName(fontName)
{
		
	m_frame.setSize(sf::Vector2f(sizeX, sizeY));
	m_frame.setOutlineColor(sf::Color::White);
	m_frame.setOutlineThickness(3.f);
	m_frame.setFillColor(sf::Color(120, 120, 120, 255));

	setScale(scale, scale);
	setCharacterSize(charSize);
	initText(fontName, label);
	setPosition(positionX,positionY);
	
}

TextObject::~TextObject()
{

}




void TextObject::render(sf::RenderTarget* target)
{
	target->draw(this->m_frame);
	target->draw(this->m_text);
}

Object* TextObject::updateClickables(sf::Vector2f& mousePosition)
{
	return this;
}



const sf::Color* TextObject::getColorText() const
{
	return &(m_text.getFillColor());
}

std::string TextObject::getLabel()
{
	
	return m_text.getString().toAnsiString();
}

sf::Text* TextObject::getText() 
{
	return &m_text;
}

const std::string& TextObject::getFontName() const
{
	return m_fontName;
}

short int TextObject::getCharacterSize() const
{
	return m_characterSize;
}

void TextObject::setColorText(int r, int g, int b, int a)
{

	m_text.setFillColor(sf::Color(r, g, b, a));
}

void TextObject::setCharacterSize(short int size)
{
	m_characterSize = size;
	m_text.setCharacterSize((unsigned int)(m_characterSize * getScale().first));
}

void TextObject::move(int x, int y)
{
	m_frame.move(x, y);
	m_text.move(x, y);
}










/// <summary>
/// Funkcja ustawia pozycjê obiektu na inn¹
/// </summary>
/// <param name="position"></param>
void TextObject::setPosition(const sf::Vector2i& position)
{
	setPosition(position.x, position.y);
}

void TextObject::setPosition(int x, int y)
{
	float thick = m_frame.getOutlineThickness();
	m_frame.setPosition(x+thick,y+thick);
	m_text.setPosition(x + thick, y + thick);
}

/// <summary>
/// Funkcja przesuwa obiekt 
/// </summary>
/// <param name="offset"></param>
void TextObject::move(const sf::Vector2i& offset)
{
	move(offset.x, offset.y);


}

void TextObject::centerText()
{
	sf::Vector2f center(m_text.getGlobalBounds().width / 2.f, m_text.getGlobalBounds().height / 2.f);
	sf::Vector2f localBounds(trunc(center.x + m_text.getLocalBounds().left), trunc(center.y + m_text.getLocalBounds().top));

	//std::cout << "center:" << center.x << " " << center.y << '\n';
	//std::cout << "localBounds:" << localBounds.x << " " << localBounds.y << '\n';
	//std::cout << std::endl;


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
void TextObject::initText(const std::string& fontName, const std::string label)
{
	
	setFont(fontName);
	initText(label);
	
}

void TextObject::initText(const std::string label)
{
	m_text.setString(label);
}

void TextObject::setFont(const std::string& fontName)
{
	m_text.setFont(*ResourceManager::getResourceManager()->getFont(fontName));
	m_fontName = fontName;
}

void TextObject::setScale(float x, float y)
{
	m_frame.setScale(x, y);
	m_text.setCharacterSize((unsigned int)(m_characterSize * getScale().first));
}

std::pair<float, float> TextObject::getScale()
{
	return { m_frame.getScale().x,m_frame.getScale().y };
}

void TextObject::fitBorderToText()
{
	m_frame.setSize(sf::Vector2f(m_text.getGlobalBounds().width/m_frame.getScale().x, m_text.getGlobalBounds().height/m_frame.getScale().y));
	
}


