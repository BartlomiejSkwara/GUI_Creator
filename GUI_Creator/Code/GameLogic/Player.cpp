#include "Player.h"



Player::Player(float x, float y)
{	
	this->initShapes();
	this->initVariables();
	this->shape.setPosition(x, y);
}

Player::~Player()
{
}

void Player::initShapes() 
{
	this->shape.setFillColor(sf::Color::Blue);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

void Player::initVariables()
{
	this->movementSpeed = 5.f;
}

void Player::update(const sf::RenderTarget* target)
{
	//this->updateWindowsBoundsCollision();
	this->updateInput(target);

	
}


bool Player::checkWindowsBoundsCollision(int direction, const sf::RenderTarget* target)
{
	
	sf::FloatRect playerBounds = this->shape.getGlobalBounds();
	switch (direction)
	{
	case moveLeft:
		if (playerBounds.left - 5 < 0)
			return false;
		break;
	case moveRight:
		if (playerBounds.left + playerBounds.width + 5 > target->getSize().x) {
			return false;
		}
		break;
		
	case moveTop:
		if (playerBounds.top - 5 < 0)
			return false;
		break;
	case moveBottom:
		if (playerBounds.top + playerBounds.height + 5 > target->getSize().y)
			return false;
		break;

	}

	return true;
}

void Player::updateInput(const sf::RenderTarget* target)
{
	///Movement
	//Vertical
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->checkWindowsBoundsCollision(moveRight, target))
	{
		this->shape.move(this->movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->checkWindowsBoundsCollision(moveLeft, target))
	{
		this->shape.move(-(this->movementSpeed), 0.f);
	}
	//Horizontal
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->checkWindowsBoundsCollision(moveTop, target))
	{
		this->shape.move(0.f, -(this->movementSpeed));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->checkWindowsBoundsCollision(moveBottom, target))
	{
		this->shape.move(0.f, this->movementSpeed);
	}
}

void Player::render(sf::RenderTarget*target)
{
	target->draw(this->shape);
}