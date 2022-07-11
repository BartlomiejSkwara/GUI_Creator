#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
class Enemy
{
private:
	sf::CircleShape shape;
	void initShape(const sf::RenderTarget* target);
public:
	Enemy(const sf::RenderTarget* target);
	virtual ~Enemy();


	//Update functions
	void update(const sf::RenderTarget* target);


	//Render functions
	void render(sf::RenderTarget* target);
	

	//Gettery
	sf::CircleShape* getShape();
};

