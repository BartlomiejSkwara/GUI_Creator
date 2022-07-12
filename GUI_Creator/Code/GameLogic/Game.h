#pragma once

#include "Player.h"
#include "Enemy.h"
#include "../Scenes/GameSceneUIDesigner.h"
#include "../../values.h"


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
	MouseInfo m_mouseInfo;
	
	//Game Objects
	Player player;
	GameSceneUIDesigner * m_gameScene;

	//Resources
	sf::Font font;
	sf::Text uiText;

	//Event used for pooling
	sf::Event ev;

	//Player related variables
	int  m_hp;
	bool m_pausedGame;

	//Private functions
	void initVariables();
	void initFonts();
	void initWindow();
	void initGameObjects();
	
public:



	//Used by DearImgui
	sf::Clock deltaClock;

	
	//Constructors and destructors
	Game();
	virtual ~Game();

	//Functions


	//Player Related
	void updatePlayer();


	void pollEvents();
	
	

	//Uses update clickables from current scene
	void updateClickables();
	//Calls all of the update functions
	void update();
	//Renders everything from current scene
	void render();

	//Mouse Positions
	void updateMouseStatus();
	void updateMousePositions();
	
	//Gettery
	const bool windowIsOpen() const;
	const bool getEndGame() const;


};

