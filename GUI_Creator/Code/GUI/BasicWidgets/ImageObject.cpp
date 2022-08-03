#include "ImageObject.h"

///Przyda³aby siê tu jakaœ dokumentacja :>

ImageObject::ImageObject(const std::string& textureName, float positionX, float positionY, const std::function<void()>& func,float scale)
	:Object(func),m_textureName(textureName)
{
	
	
	m_frame.setOutlineColor(sf::Color::White);
	m_frame.setOutlineThickness(3.f);
	m_frame.setFillColor(sf::Color(120, 120, 120, 255));

	setTexture(textureName);
	fitBorderToSprite();
	setPosition(positionX,positionY);
	setScale(scale,scale);
	
}

ImageObject::~ImageObject()
{

}

void ImageObject::fitBorderToSprite()
{
	m_frame.setSize(sf::Vector2f(m_sprite.getTextureRect().width, m_sprite.getTextureRect().height));
}




void ImageObject::render(sf::RenderTarget* target)
{
	target->draw(this->m_frame);
	target->draw(this->m_sprite);
}

Object* ImageObject::updateClickables(sf::Vector2f& mousePosition)
{
	return this;
}


const sf::Sprite* ImageObject::getSprite()
{
	return & m_sprite;
}

const std::string& ImageObject::getTextureName()
{
	return m_textureName;
}

void ImageObject::setScale(float x, float y)
{
	m_frame.setScale(x, y);
	m_sprite.setScale(x, y);
}

std::pair<float, float> ImageObject::getScale()
{
	return { m_frame.getScale().x,m_frame.getScale().y };
}



void ImageObject::move(int x, int y)
{
	m_frame.move(x, y);
	m_sprite.move(x, y);
}










/// <summary>
/// Funkcja ustawia pozycjê obiektu na inn¹
/// </summary>
/// <param name="position"></param>
void ImageObject::setPosition(const sf::Vector2i& position)
{
	setPosition(position.x, position.y);
}

void ImageObject::setPosition(int x, int y)
{
	float thick = m_frame.getOutlineThickness();
	m_frame.setPosition(x+thick,y+thick);
	m_sprite.setPosition(x + thick, y + thick);
}

void ImageObject::setTexture(const std::string& textureName)
{
	m_sprite.setTexture(*ResourceManager::getResourceManager()->getTexture(textureName),true);
	m_textureName = textureName;
	fitBorderToSprite();
}

/// <summary>
/// Funkcja przesuwa obiekt 
/// </summary>
/// <param name="offset"></param>
void ImageObject::move(const sf::Vector2i& offset)
{
	move(offset.x, offset.y);


}





