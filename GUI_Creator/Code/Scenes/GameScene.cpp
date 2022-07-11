#include "GameScene.h"



GameScene::GameScene(sf::Font* font, MouseInfo* mouseInfo, sf::RenderWindow* window) : m_font(font), m_mouseInfo(mouseInfo), m_window(window)
{
	m_gameScene = new DivObject("", sf::Color(0,0,0,0), 0, 0, window->getSize().x, window->getSize().y);

	//std::cout << window->getSize().x << " "<< window->getSize().y;
}

GameScene::~GameScene()
{

	delete m_gameScene;
}


