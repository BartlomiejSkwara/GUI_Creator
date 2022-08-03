#pragma once
#include <SFML/Graphics/RenderTarget.hpp>

class Renderable
{
private:
public:

	Renderable();
	~Renderable();
	
	/// Funkcja renderuje obiekt
	virtual void render(sf::RenderTarget* target) = 0;


};

