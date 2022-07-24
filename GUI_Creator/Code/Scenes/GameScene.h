#pragma once
#include "../GUI/BasicWidgets/DivObject.h"
#include "../Input/MouseInfo.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "ObserverStuff/SceneSubject.h"
class GameScene
{

private:

	
	virtual void initGameObjects(sf::Font* font) = 0;

protected:
	MouseInfo* m_mouseInfo;
	sf::Font* m_font;

	//This thingie is the main render target 
	sf::RenderWindow* m_window;
	
	DivObject* m_gameScene;
	
	//Observer base events handling 
	SceneSubject m_subj;
public:
	GameScene(sf::Font* font,sf::RenderWindow* window);
	virtual ~GameScene();
	virtual void updateDearIMGUI()=0;
	virtual void pollEvents(sf::Event* ev) = 0;
	virtual void updateClickables() = 0;
	virtual void updateMouseRelated() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

};

