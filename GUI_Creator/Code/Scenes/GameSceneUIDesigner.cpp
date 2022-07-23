#include "GameSceneUIDesigner.h"



void GameSceneUIDesigner::modeMOVE()
{
    
}

void GameSceneUIDesigner::modePICK()
{

    m_currentDESIGN_STATE = D_MOVE;
    if (m_mouseInfo->mouseClicked)
    {
        std::cout << "Doing some stuff\n";
    }

}

void GameSceneUIDesigner::toolbarAddButton()
{

    PWW_Button* button = new PWW_Button(*m_font, "NULL", floor(m_window->getSize().x / 2 - 50), floor(m_window->getSize().y / 2 - 15));
    button->setEvent([&,button]() {
        button->initVariables();
        selectManager->changeFocus(button,button);
        });

    m_editableObjects->addObject(button);
}

void GameSceneUIDesigner::toolbarAddDiv()
{   
    PWW_Div* div = new PWW_Div(sf::Color(150, 150, 150), floor(m_window->getSize().x / 2 + 100), floor(m_window->getSize().y / 2 - 50), 100, 100);
    div->setEvent([&, div]() {
        div->initVariables();
        selectManager->changeFocus(div,div);
        });
    m_editableObjects->addObject(div);
}


    








GameSceneUIDesigner::GameSceneUIDesigner(sf::Font* font, sf::RenderWindow* window):
GameScene(font,window), m_objectIsCurrentlyDragged(false), m_objectIsCurrentlyPicked(false),
selectManager(SelectionManager::getSelectionManager())
{
    
    m_editableObjects = new DivObject(sf::Color(), 0, 0, window->getSize().x, window->getSize().y);
    m_currentDESIGN_STATE = D_MOVE;
    m_subj.addObserver(new ObserverUID());
    m_gameScene->addDiv(m_editableObjects);
    
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
    ///Clickable///

    if (m_mouseInfo->mouseClicked && m_gameScene->checkIfObjectContainsPoint(m_mouseInfo->mousePositionView))
    {

        Object* clickedObj = m_editableObjects->updateClickables(m_mouseInfo->mousePositionView);
        if (clickedObj == static_cast<Clickable*>(m_editableObjects)) {
            m_subj.notify(EventType::EVENT_CLICKED_BACKGROUND, clickedObj);
        }
        else
        {
            m_subj.notify(EventType::EVENT_CLICKED_OBJECT, clickedObj);
        }
        

    }
    else if (m_mouseInfo->mouseClicked)
    {

    }

    ///Movable///
   
    if (m_mouseInfo->mouseHeld)
    {
        if (selectManager->isObjectFocused() && !(ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow)))
        {
            if (m_objectIsCurrentlyDragged)
            {
                m_subj.notify(EventType::EVENT_MOVED_OBJECT, selectManager->getFocusedElement());

            }
            else if (selectManager->getFocusedElement()->checkIfObjectContainsPoint(m_mouseInfo->mousePositionView))
            {
                m_subj.notify(EventType::EVENT_MOVED_OBJECT,selectManager->getFocusedElement());
                m_objectIsCurrentlyDragged = true;
            }

        }
    }
    else
    {
        m_objectIsCurrentlyDragged = false;
    }


}

void GameSceneUIDesigner::render()
{

    m_gameScene->render(m_window);
    if (selectManager->isObjectFocused())
    {
        selectManager->renderFocusSignifiers(m_window);
    }

}

void GameSceneUIDesigner::updateMouseRelated()
{
    updateClickables();
    updateMode();
}

void GameSceneUIDesigner::updateMode()
{
  
    switch (m_currentDESIGN_STATE)
    {
    case D_MOVE:
        modeMOVE();
        break;
    case D_PICK:
        modePICK();
        break;
    default:
        break;
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
