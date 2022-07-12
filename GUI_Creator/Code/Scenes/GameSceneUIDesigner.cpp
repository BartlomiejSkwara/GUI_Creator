#include "GameSceneUIDesigner.h"



void GameSceneUIDesigner::toolbarAddButton()
{

    PWW_Button* button = new PWW_Button(IdentifiableObject::generateID(), *m_font, "NULL", floor(m_window->getSize().x / 2 - 50), floor(m_window->getSize().y / 2 - 15));
    button->setEvent([&,button]() {
        button->initVariables();
        selectManager->changeFocus(button,button);
        });

    m_editableObjects->addButtonObject(button);
}

void GameSceneUIDesigner::toolbarAddDiv()
{   
    PWW_Div* div = new PWW_Div(IdentifiableObject::generateID(), sf::Color(150, 150, 150), floor(m_window->getSize().x / 2 + 100), floor(m_window->getSize().y / 2 - 50), 100, 100);
    div->setEvent([&, div]() {
        div->initVariables();
        selectManager->changeFocus(div,div);
        });
    m_editableObjects->addDivObject(div);
}


    








GameSceneUIDesigner::GameSceneUIDesigner(sf::Font* font, MouseInfo* mouseInfo, sf::RenderWindow* window):
GameScene(font,mouseInfo,window), m_objectIsCurentlyDragged(false), 
selectManager(SelectionManager::getSelectionManager())
{
   
    m_editableObjects = new DivObject("main", sf::Color(), 0, 0, window->getSize().x, window->getSize().y);
    m_currentDESIGN_STATE = this->D_MOVE;
    
}


GameSceneUIDesigner::~GameSceneUIDesigner()
{
    PWW_Button::deleteStaticPointers();
    delete selectManager;
    delete m_editableObjects;
    
}


void GameSceneUIDesigner::initGameObjects(sf::Font* font)
{
    
    
}

void GameSceneUIDesigner::initManagers()
{

    
}



void GameSceneUIDesigner::pollEvents(sf::Event * ev)
{
    switch (ev->type)
    {

    case sf::Event::KeyPressed:
        switch (ev->key.code)
        {
        case sf::Keyboard::F11:
            break;
        case sf::Keyboard::Tab:
            std::string id = "TBAR";

            if (m_gameScene->searchForObject(id, ContainerObject::O_RENDERABLE)!=-1)
            {
                m_gameScene->removeObject(id);
            
            }
            
            
            //std::string name = ""
            //std::cout << "Thou shalt presht da button\n" << " and receive " << (m_gameScene->deepSearchByID("Bruh"));
            break;
        }
        if (ev->key.code == sf::Keyboard::F11) {

        }
        break;



    case sf::Event::Closed:
        this->m_window->close();
        break;

    case sf::Event::MouseButtonPressed:

        break;
    }
}

void GameSceneUIDesigner::updateClickables()
{
    
   

    if (m_mouseInfo->mouseClicked && m_gameScene->checkIfObjectContainsPoint(m_mouseInfo->mousePositionView))
    {

           
        
        if (m_gameScene->updateClickables(m_mouseInfo->mousePositionView)>1)
        {
            
        }
        else if(m_editableObjects->updateClickables(m_mouseInfo->mousePositionView) == 1)
        { 
                
                if (selectManager->isObjectFocused()) //Obiekt odznaczany przez klikniêcie poza nim
                {
                    
                    //loseFocus();

                }
                else //Cos klikniete ale nic nie zostaje zaznaczone ani nic wczesniej nie bylo zaznaczone
                {
                
                }
                    
        }
        else { //Obiekt zaznaczony 
        }
        
        
    }
}

void GameSceneUIDesigner::render()
{
    m_editableObjects->render(m_window);
    m_gameScene->render(m_window);
    if (selectManager->isObjectFocused())
    {
        selectManager->renderFocusSignifier(m_window);
    }

}

void GameSceneUIDesigner::updateMouseRelated()
{
    updateClickables();
    updateDragging();
}

void GameSceneUIDesigner::updateDragging()
{
    
 
    if (m_mouseInfo->mouseHeld)
    {
        switch (m_currentDESIGN_STATE)
        {
        case D_MOVE:
            if (selectManager->isObjectFocused())
            {   
                if (m_objectIsCurentlyDragged) 
                {
                    sf::Vector2f moveDistance = m_mouseInfo->mousePositionView - m_mouseInfo->mousePositionViewLastKnown;
                    selectManager->getFocusedElement()->move(moveDistance);
                    selectManager->getFocusSignifier()->move(moveDistance);
                }
                else if (selectManager->getFocusedElement()->checkIfObjectContainsPoint(m_mouseInfo->mousePositionView))
                {
                    sf::Vector2f moveDistance = m_mouseInfo->mousePositionView - m_mouseInfo->mousePositionViewLastKnown;
                    selectManager->getFocusedElement()->move(moveDistance);
                    selectManager->getFocusSignifier()->move(moveDistance);
                    m_objectIsCurentlyDragged = true;
                }

               
            }
            
            break;
        default:
            break;
        }
    }
    else
    {
        m_objectIsCurentlyDragged = false;
    }
}

void GameSceneUIDesigner::updateDearIMGUI()
{
    if (im_showParamWindow) { updateDearIMGUIParamWindow(); };
    updateDearIMGUIMainMenuBar();
    
      
    //ImGui
    ImGui::ShowDemoWindow(NULL);
    //ImGui::End();
   
}

void GameSceneUIDesigner::updateDearIMGUIMainMenuBar()
{

    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("Generuj"))
        {
            if (ImGui::MenuItem("Eksportuj konsola")) { generator.generateToConsole(); }
            if (ImGui::MenuItem("Eksportuj plik")) { generator.generateToFile(); }
            ImGui::Separator();
            if (ImGui::MenuItem("Zapisz")) { generator.saveToFile(); }
            if (ImGui::MenuItem("Wczytaj")) { generator.loadFromFile(); }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Dodaj"))
        {
            if (ImGui::MenuItem("Przycisk"))
            {
                toolbarAddButton();
            }
            if (ImGui::MenuItem("Kontener"))
            {
                toolbarAddDiv();
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Okna"))
        {
            if (ImGui::MenuItem("Parametry Obiektu", NULL, im_showParamWindow)) { im_showParamWindow = !im_showParamWindow; }
            ImGui::EndMenu();
        }


        if (ImGui::BeginMenu("Zaznaczenie"))
        {
            if (ImGui::MenuItem("Dla Nadelementu", NULL, selectManager->isShowingMainSelection())) { selectManager->setShowMainSelection(!selectManager->isShowingMainSelection()); }
            if (ImGui::MenuItem("Dla Podelementu", NULL, selectManager->isShowingChildSelection())) { selectManager->setShowChildSelection(!selectManager->isShowingChildSelection()); }
            ImGui::Separator();

            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void GameSceneUIDesigner::updateDearIMGUIParamWindow()
{
    ImGui::Begin("Parametry Obiektu: ");
    ImGui::SetWindowSize(sf::Vector2f(200, 400));

    if (selectManager->getSelectedElement() != nullptr) {
        selectManager->getSelectedElement()->updateDearIMGUIParamWindow();
    }
    else {

        ImGui::Text("Nie zaznaczono obiektu !!!");
    }


    ImGui::End();
    
}



void GameSceneUIDesigner::update()
{
    updateMouseRelated(); 
    updateDearIMGUI();
}
