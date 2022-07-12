#include "Game.h"

//Initialization


void Game::initVariables()
{   
	m_window = nullptr;
    m_mouseInfo.mouseHeld = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    m_pausedGame = false;
    m_hp = 3;

}
void Game::initWindow()
{	
	this->videoMode.width  = WINDOW_WIDTH;
	this->videoMode.height = WINDOW_HEIGHT;

	this->m_window = new sf::RenderWindow(this->videoMode, "S.E.N.A.T", sf::Style::Titlebar | sf::Style::Close);

    this->m_window->setFramerateLimit(60);
}

void Game::initFonts()
{
    if (!(this->font.loadFromFile("Fonts/LiberationSans-Regular.ttf"))) {
        std::cout << "ERROR::GAME::INITFONTS::Failed to load font" << std::endl;
    }
}

void Game::initGameObjects()
{
    m_gameScene = new GameSceneUIDesigner(&font, &m_mouseInfo, m_window);
}



Game::Game()
{
    
    this->initVariables();
    this->initFonts();
    this->initWindow();
    ImGui::SFML::Init(*m_window);
    this->initGameObjects();
    
}

Game::~Game()
{
    delete m_gameScene;
	delete this->m_window;
    ImGui::SFML::Shutdown();
}



// Update Functions
void Game::updateMouseStatus()
{
 
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        if (m_mouseInfo.mouseHeld == false)
        {
            //std::cout<<"Sone pressed the mouse\n";
            m_mouseInfo.mouseClicked = true;
            m_mouseInfo.mouseHeld = true;
        }
        else 
        {
            //std::cout << "Mouse is being held\n";
            m_mouseInfo.mouseClicked = false;
        }
        
    }
    else
    {
        //std::cout << "Sone released the mouse\n";
        m_mouseInfo.mouseHeld = false;
    }
}

void Game::update()
{

    //Mouse Related
    updateMousePositions();
    updateMouseStatus();

    //Scenes Related
    pollEvents();
    if(this->m_pausedGame==false)
    {      
        ImGui::SFML::Update(*m_window, deltaClock.restart());
        m_gameScene->update();
        //player.update(this->m_window);
    }
    
   



}



//Render Functions

void Game::render()
{
    m_window->clear();

    
    //this->player.render(this->m_window);
    
    m_gameScene->render();  
    
    ImGui::SFML::Render(*m_window);
    m_window->display();
    
}




const bool Game::windowIsOpen() const
{
	return this->m_window->isOpen();
}





void Game::pollEvents()
{
    while (m_window->pollEvent(ev))
    {
        m_gameScene->pollEvents(&ev);
        ImGui::SFML::ProcessEvent(ev);
    }
    
}




void Game::updateMousePositions() {
    
    m_mouseInfo.mousePositionWindow= sf::Mouse::getPosition(*this->m_window);
    m_mouseInfo.mousePositionViewLastKnown = m_mouseInfo.mousePositionView;
    m_mouseInfo.mousePositionView  = this->m_window->mapPixelToCoords(this->m_mouseInfo.mousePositionWindow);
    
}

void Game::updateClickables()
{
    ImGui::SFML::Update(*m_window, deltaClock.restart());
    m_gameScene->update();
}

