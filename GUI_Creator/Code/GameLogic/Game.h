#pragma once

#include "Player.h"
#include "Enemy.h"
#include "../../values.h"
#include "../Events and stuff/Input/MouseInput.h"
#include "../Scenes/UIDesigner/GameSceneUIDesigner.h"


/**
* Game wrapper
*/
class Game
{
private:

	

	//Private variables
	sf::RenderWindow* m_window;
	sf::VideoMode videoMode;
	
	
	//All mouse info combined in one object
	MouseInput* m_MouseInput;
	
	//Game Objects
	GameSceneUIDesigner* m_gameScene;

	

	//Event used for pooling
	sf::Event ev;

	//Player related variables
	int  m_hp;
	bool m_pausedGame;

	//Private functions
	void initVariables();

	void initWindow();
	void initGameObjects();
	
public:



	//Used by DearImgui
	sf::Clock deltaClock;

	
	//Constructors and destructors
	Game();
	virtual ~Game();

	//Functions




	void pollEvents();
	
	


	//Calls all of the update functions
	void update();
	//Renders everything from current scene
	void render();

	
	//Gettery
	const bool windowIsOpen() const;
	const bool getEndGame() const;


};

