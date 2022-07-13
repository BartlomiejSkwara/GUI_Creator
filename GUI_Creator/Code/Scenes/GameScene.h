#pragma once
#include "../GUI/BasicWidgets/DivObject.h"
#include "../MouseInfo.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class GameScene
{

private:

	
	virtual void initGameObjects(sf::Font* font) = 0;

protected:
	MouseInfo* m_mouseInfo;
	sf::Font* m_font;
	sf::RenderWindow* m_window;
	DivObject* m_gameScene;
	
public:
	GameScene(sf::Font* font, MouseInfo * mouseInfo, sf::RenderWindow* window);
	virtual ~GameScene();
	virtual void updateDearIMGUI()=0;
	virtual void pollEvents(sf::Event* ev) = 0;
	virtual void updateClickables() = 0;
	virtual void updateMouseRelated() = 0;
	virtual void updateMode()=0;
	virtual void update() = 0;
	virtual void render() = 0;

};

