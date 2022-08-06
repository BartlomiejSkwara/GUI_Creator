#include "GameScene.h"



GameScene::GameScene(sf::RenderWindow* window) : m_MouseInput(MouseInput::getMouseInf()), m_window(window)
{
	m_gameScene = new DivObject(sf::Color(0, 0, 0, 0), 0, 0, window->getSize().x, window->getSize().y);

}


GameScene::~GameScene()
{

	delete m_gameScene;

}


