#include "Enemy.h"

void Enemy::initShape(const sf::RenderTarget* target)
{
	this->shape.setRadius(20.0f);
	this->shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 255));
	this->shape.setPosition(
		rand() % static_cast<int>(target->getSize().x - this->shape.getGlobalBounds().width),
		0.f
	);
	
}

Enemy::Enemy(const sf::RenderTarget* target)
{
	this->initShape(target);
}

Enemy::~Enemy()
{
}

void Enemy::update(const sf::RenderTarget* target)
{
	this->shape.move(0.f, 4.f);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

sf::CircleShape* Enemy::getShape()
{
	return &this->shape;
	
}
