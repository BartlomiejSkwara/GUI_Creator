#include "GameScene.h"



GameScene::GameScene(ResourceManager* resourceManager, sf::RenderWindow* window) : m_mouseInfo(MouseInfo::getMouseInf()), m_window(window), m_resourceManager(resourceManager)
{
	m_gameScene = new DivObject(sf::Color(0, 0, 0, 0), 0, 0, window->getSize().x, window->getSize().y);

}


GameScene::~GameScene()
{

	delete m_gameScene;

}


