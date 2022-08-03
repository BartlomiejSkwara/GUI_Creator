#include "GameSceneUIDesigner.h"



void GameSceneUIDesigner::modeMOVE()
{
    
}

void GameSceneUIDesigner::modePICK()
{
    if (m_mouseInfo->mouseClicked)
    {
        std::cout << "Doing some stuff\n";
    }

}

void GameSceneUIDesigner::toolbarAddButton()
{

    TextObject* button = new TextObject("LiberationSans-Regular.ttf" ,"NULL", floor(m_window->getSize().x / 2 - 50), floor(m_window->getSize().y / 2 - 15),[](){},100,30,20,1);
    button->setEvent([&,button]() {
        selectManager->changeFocus(button);
        pwwManager.initTextButton(button);
        
        });
    button->centerText();

    m_editableObjects->addObject(button);
    
}

void GameSceneUIDesigner::toolbarAddDiv()
{   
    DivObject* div = new DivObject(sf::Color(150, 150, 150), floor(m_window->getSize().x / 2 + 100), floor(m_window->getSize().y / 2 - 50), 100, 100);
    div->setEvent([&, div]() {
        selectManager->changeFocus(div);
        pwwManager.initDIV(div);
        
        });
   
    m_editableObjects->addObject(div);
}

void GameSceneUIDesigner::toolbarAddText()
{
    TextObject* text = new TextObject("LiberationSans-Regular.ttf" ,"Tekst", floor(m_window->getSize().x / 2), floor(m_window->getSize().y / 2 ), [](){},100,100);
    
    text->setEvent([&, text]() {
        selectManager->changeFocus(text);
        pwwManager.initText(text);
        
        });
    text->fitBorderToText();
    text->centerText();
    text->setColorFill(0, 0, 0, 0);
    text->setColorBorder(255, 0, 0, 100);

    m_editableObjects->addObject(text);
}

void GameSceneUIDesigner::toolbarAddImage()
{
    ImageObject* image = new ImageObject("7hv5bfjviq061.png",floor(m_window->getSize().x / 2), floor(m_window->getSize().y / 2), []() {},0.25);
    image->setEvent([&, image]() {
        selectManager->changeFocus(image);
        pwwManager.initImage(image);

        });

    m_editableObjects->addObject(image);
}


    








GameSceneUIDesigner::GameSceneUIDesigner(sf::RenderWindow* window):
GameScene(window), m_objectIsCurrentlyDragged(false), m_objectIsCurrentlyPicked(false),
selectManager(SelectionManager::getSelectionManager())
{
    
    m_editableObjects = new DivObject(sf::Color(), 0, 0, window->getSize().x, window->getSize().y);
    m_subj.addObserver(new ObserverUID());
    m_gameScene->addDiv(m_editableObjects);
    initIndicatorSettings();
    
}


GameSceneUIDesigner::~GameSceneUIDesigner()
{

    delete selectManager;
    delete m_editableObjects;
    
}


void GameSceneUIDesigner::initIndicatorSettings()
{
    sf::Color ca = selectManager->getFocusSignifier()->getFillColor();
    m_signifierColor[0] = (float)ca.r / 255;
    m_signifierColor[1] = (float)ca.g / 255;
    m_signifierColor[2] = (float)ca.b / 255;
    m_signifierColor[3] = (float)ca.a / 255;

    m_selectionIndicatorSize = selectManager->getFocusSignifier()->getRadius() / 5;
}

void GameSceneUIDesigner::updateIndicatorSettings()
{
    ImGui::Begin("Ustawienia Zaznaczenia: ");
    ImGui::SetWindowSize(sf::Vector2f(200, 100));
    ImGui::Text("Zaznaczenie");
    if (ImGui::SliderFloat("Promien", &m_selectionIndicatorSize, 0.f, 10.f)) {
        selectManager->getFocusSignifier()->setRadius(5 * m_selectionIndicatorSize);
        selectManager->changeFocus(selectManager->getFocusedElement());

    }

    if (ImGui::SliderFloat("Alfa", &m_signifierColor[3], 0.f, 1.f)) {
        SelectionManager::getSelectionManager()->getFocusSignifier()->setFillColor(sf::Color((int)(m_signifierColor[0] * 255), (int)(m_signifierColor[1] * 255), (int)(m_signifierColor[2] * 255), (int)(m_signifierColor[3] * 255)));
    }
    ImGui::End();
}

void GameSceneUIDesigner::initGameObjects(sf::Font* font)
{
    
    
}

void GameSceneUIDesigner::initManagers()
{

    
}



void GameSceneUIDesigner::pollEvents(sf::Event * ev)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
        if (ev->type == sf::Event::KeyPressed) {

            switch (ev->key.code)
            {
            case sf::Keyboard::Num1:
                toolbarAddDiv();
                break;
            case sf::Keyboard::Num2:
                toolbarAddButton();
                break;
            case sf::Keyboard::Num3:
                toolbarAddImage();
                break;
            case sf::Keyboard::Num4:
                toolbarAddText();
                break;

            }
        }

    }


    switch (ev->type)
    {
    
    case sf::Event::KeyPressed:
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
}



void GameSceneUIDesigner::updateDearIMGUI()
{
    if (im_showParamWindow) { pwwManager.updatePWW(); };
    if (im_showIndicatorParamWindow) { updateIndicatorSettings(); }
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
            if (ImGui::MenuItem("Kontener", "shift+1"))
            {
                toolbarAddDiv();
            }
            if (ImGui::MenuItem("Przycisk", "shift+2"))
            {
                toolbarAddButton();
            }
            if (ImGui::MenuItem("Obraz", "shift+3"))
            {
                toolbarAddImage();
            }
            if (ImGui::MenuItem("Tekst",    "shift+4"))
            {
                toolbarAddText();
            }     
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Okna"))
        {
            if (ImGui::MenuItem("Parametry Obiektu", NULL, im_showParamWindow)) { im_showParamWindow = !im_showParamWindow; }
            if (ImGui::MenuItem("Ustawienia Zaznaczenia", NULL, im_showIndicatorParamWindow)) { im_showIndicatorParamWindow = !im_showIndicatorParamWindow; }
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





void GameSceneUIDesigner::update()
{
    updateMouseRelated(); 
    updateDearIMGUI();
}
