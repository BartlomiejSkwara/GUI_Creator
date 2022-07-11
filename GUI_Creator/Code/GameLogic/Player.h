#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

constexpr int moveTop = 0;
constexpr int moveBottom = 1;
constexpr int moveLeft = 2;
constexpr int moveRight = 3;
class Player
{
	
private:
	
	//Player drawable
	sf::RectangleShape shape;
	
	//Player stats
	float movementSpeed;
	
	//Initialization
	void initVariables();
	void initShapes();

public:
	//Constructor and destructor
	Player(float x = 0.0f, float y = 0.0f);
	virtual ~Player();

	//Update functions
	/// <summary>
	/// Function responsible for checking if movement could cause the sprite getting out of the window
	/// </summary>
	/// <param name="direction">Specify the movement direction : Top (0) Bottom (1)  Left(2) Right (3) </param>
	/// <param name="target">Pass the window to check for its bounds</param>
	/// <returns>If the function returns true it means that movement won't make the sprite leave the window</returns>
	bool checkWindowsBoundsCollision(int direction, const sf::RenderTarget* target);
	void updateInput(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);


	//Render functions
	void render(sf::RenderTarget*target);
};

