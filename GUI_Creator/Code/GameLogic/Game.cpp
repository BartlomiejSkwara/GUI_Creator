#include "Game.h"

//Initialization


void Game::initVariables()
{   
	m_window = nullptr;
    
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
    m_gameScene = new GameSceneUIDesigner(&font, m_window);
}



Game::Game()
{
    
    initVariables();
    initFonts();
    initWindow();
    ImGui::SFML::Init(*m_window);
    initGameObjects();

    m_mouseInfo = MouseInfo::getMouseInf();
    m_mouseInfo->setContext(m_window);
    
}

Game::~Game()
{
    delete m_gameScene;
	delete this->m_window;
    delete m_mouseInfo;
    ImGui::SFML::Shutdown();
}





void Game::update()
{

    //Mouse Related
    m_mouseInfo->updateMouse();

    if (m_mouseInfo->mouseClicked) {
        std::cout << ":<";
    }

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






void Game::updateClickables()
{
    ImGui::SFML::Update(*m_window, deltaClock.restart());
    m_gameScene->update();
}

