#pragma once
#include "../GUI/BasicWidgets/DivObject.h"
#include "../Events and stuff/Input/MouseInput.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "../ResourceManaging/ResourceManager.h"
class GameScene: public Observer
{

private:

	
	virtual void initGameObjects(sf::Font* font) = 0;

protected:
	MouseInput* m_MouseInput;
	
	//This thingie is the main render target 
	sf::RenderWindow* m_window;
	
	DivObject* m_gameScene;
	

public:
	GameScene(sf::RenderWindow* window);
	virtual ~GameScene();
	virtual void updateDearIMGUI()=0;
	virtual void pollEvents(sf::Event* ev) = 0;
	virtual void update() = 0;
	virtual void render() = 0;

};

