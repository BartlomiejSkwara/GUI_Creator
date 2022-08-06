#include "GameSceneUIDesigner.h"



void GameSceneUIDesigner::modeMOVE()
{
    
}

void GameSceneUIDesigner::modePICK()
{
    if (m_MouseInput->mouseClicked)
    {
        std::cout << "Doing some stuff\n";
    }

}

void GameSceneUIDesigner::toolbarAddButton()
{

    TextObject* button = new TextObject("LiberationSans-Regular.ttf" ,"NULL", floor(m_window->getSize().x / 2 - 50), floor(m_window->getSize().y / 2 - 15),[](){},100,30,20,1);
    button->setEvent(
        Event(EventType::MouseLPMClickObject,
            [&, button]() {
                m_MouseInput->setLastClickedObject(button);
                focusManager.changeFocus(button);
                pwwManager.initText(button);
            }, EventScope::ScopeObject));
    button->centerText();


    m_editableObjects->addObject(button);
    
}

void GameSceneUIDesigner::toolbarAddDiv()
{   
    DivObject* div = new DivObject(sf::Color(150, 150, 150), floor(m_window->getSize().x / 2 + 100), floor(m_window->getSize().y / 2 - 50), 100, 100);
    div->setEvent(
        Event(EventType::MouseLPMClickObject,
        [&, div]() {
            m_MouseInput->setLastClickedObject(div);
            focusManager.changeFocus(div);
            pwwManager.initDIV(div);
        }, EventScope::ScopeObject));
   

    

 

    m_editableObjects->addObject(div);
}

void GameSceneUIDesigner::toolbarAddText()
{
    TextObject* text = new TextObject("LiberationSans-Regular.ttf" ,"Tekst", floor(m_window->getSize().x / 2), floor(m_window->getSize().y / 2 ), [](){},100,100);
    text->setEvent(
        Event(EventType::MouseLPMClickObject,
            [&, text]() {
                m_MouseInput->setLastClickedObject(text);
                focusManager.changeFocus(text);
                pwwManager.initText(text);
            }, EventScope::ScopeObject));

    text->fitBorderToText();
    text->centerText();
    text->setColorFill(0, 0, 0, 0);
    text->setColorBorder(255, 0, 0, 100);


   
    m_editableObjects->addObject(text);
}

void GameSceneUIDesigner::toolbarAddImage()
{
    ImageObject* image = new ImageObject("7hv5bfjviq061.png",floor(m_window->getSize().x / 2), floor(m_window->getSize().y / 2), []() {},0.25);
    image->setEvent(Event(EventType::MouseLPMClickObject, [&, image]() {
        m_MouseInput->setLastClickedObject(image);
        focusManager.changeFocus(image);
        pwwManager.initImage(image);

        },EventScope::ScopeObject));



    m_editableObjects->addObject(image);
}


    








GameSceneUIDesigner::GameSceneUIDesigner(sf::RenderWindow* window):
GameScene(window), m_objectIsCurrentlyDragged(false),pwwManager(&focusManager)
{
    
    m_editableObjects = new DivObject(sf::Color(), 0, 0, window->getSize().x, window->getSize().y);
   


    //m_subj.addObserver(new ObserverUID());
    m_gameScene->addObject(m_editableObjects);
    initIndicatorSettings();

    m_MouseInput->addEvent(EventType::MouseLPMDrag,
        [&]() {
            static sf::Vector2f moveDistance;
            moveDistance = MouseInput::getMouseInf()->mousePositionView - MouseInput::getMouseInf()->mousePositionViewLastKnown;
            if (m_objectIsCurrentlyDragged)
            {
                m_MouseInput->getLastClickedObject()->move(moveDistance.x, moveDistance.y);
                focusManager.getFocusSignifier()->move(moveDistance.x, moveDistance.y);
            }
            else if (m_MouseInput->getLastClickedObject()->checkIfObjectContainsPoint(m_MouseInput->mousePositionView))
            {
                m_MouseInput->getLastClickedObject()->move(moveDistance.x, moveDistance.y);
                focusManager.getFocusSignifier()->move(moveDistance.x, moveDistance.y);
                m_objectIsCurrentlyDragged = true;
            }

        }
    , EventScope::ScopeGlobal);

    
    
}


GameSceneUIDesigner::~GameSceneUIDesigner()
{

    delete m_editableObjects;
    
}


void GameSceneUIDesigner::initIndicatorSettings()
{
    sf::Color ca = focusManager.getFocusSignifier()->getFillColor();
    m_signifierColor[0] = (float)ca.r / 255;
    m_signifierColor[1] = (float)ca.g / 255;
    m_signifierColor[2] = (float)ca.b / 255;
    m_signifierColor[3] = (float)ca.a / 255;

    m_selectionIndicatorSize = focusManager.getFocusSignifier()->getRadius() / 5;
}

void GameSceneUIDesigner::updateIndicatorSettings()
{
    ImGui::Begin("Ustawienia Zaznaczenia: ");
    ImGui::SetWindowSize(sf::Vector2f(200, 100));
    ImGui::Text("Zaznaczenie");
    if (ImGui::SliderFloat("Promien", &m_selectionIndicatorSize, 0.f, 10.f)) {
        focusManager.getFocusSignifier()->setRadius(5 * m_selectionIndicatorSize);
        focusManager.changeFocus(m_MouseInput->getLastClickedObject());

    }

    if (ImGui::SliderFloat("Alfa", &m_signifierColor[3], 0.f, 1.f)) {
        focusManager.getFocusSignifier()->setFillColor(sf::Color((int)(m_signifierColor[0] * 255), (int)(m_signifierColor[1] * 255), (int)(m_signifierColor[2] * 255), (int)(m_signifierColor[3] * 255)));
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
            case sf::Keyboard::Add:
                if (m_MouseInput->getLastClickedObject())
                {
                    m_editableObjects->find(m_MouseInput->getLastClickedObject(), FindMode::FIND_AND_MOVE_UP);
                }
                
                break;
            case sf::Keyboard::Subtract:
                if (m_MouseInput->getLastClickedObject())
                {
                    m_editableObjects->find(m_MouseInput->getLastClickedObject(), FindMode::FIND_AND_MOVE_DOWN);
                }

                break;

            }
        }

    }


    switch (ev->type)
    {
    
    case sf::Event::KeyPressed:
        switch (ev->key.code)
        {
        case sf::Keyboard::Delete:
            delete (m_editableObjects->find(m_MouseInput->getLastClickedObject(), FindMode::FIND_AND_REMOVE));
            m_MouseInput->setLastClickedObject(nullptr);
            focusManager.changeFocus(nullptr);
           
            break;
        }
        break;
        
        



    case sf::Event::Closed:
        this->m_window->close();
        break;

    case sf::Event::MouseButtonPressed:

        break;
    }
}



void GameSceneUIDesigner::render()
{

    m_gameScene->render(m_window);
    focusManager.renderFocusSignifiers(m_window);
}




void GameSceneUIDesigner::updateDearIMGUI()
{
    if (im_showParamWindow) { 
        pwwManager.updatePWW(); 
    };
    
    
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
        if (ImGui::BeginMenu("Edycja"))
        {
            if (ImGui::MenuItem("Usun", "delete"))
            {
                delete (m_editableObjects->find(m_MouseInput->getLastClickedObject(), FindMode::FIND_AND_REMOVE));
                m_MouseInput->setLastClickedObject(nullptr);
                focusManager.changeFocus(nullptr);
            }
            if (ImGui::MenuItem("Przesun tyl", "shift+'-'"))
            { 
                if (m_MouseInput->getLastClickedObject())
                {
                    m_editableObjects->find(m_MouseInput->getLastClickedObject(), FindMode::FIND_AND_MOVE_DOWN);
                }
            }
            if (ImGui::MenuItem("Przesun przod", "shift+'+'"))
            {
                if (m_MouseInput->getLastClickedObject())
                {
                    m_editableObjects->find(m_MouseInput->getLastClickedObject(), FindMode::FIND_AND_MOVE_UP);
                }
            }
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
            if (ImGui::MenuItem("Dla Nadelementu", NULL, focusManager.isShowingMainSelection())) { focusManager.setShowMainSelection(!focusManager.isShowingMainSelection()); }
            if (ImGui::MenuItem("Dla Podelementu", NULL, focusManager.isShowingChildSelection())) { focusManager.setShowChildSelection(!focusManager.isShowingChildSelection()); }
            ImGui::Separator();

            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void GameSceneUIDesigner::onNotify(Event ev)
{
    /// Dragging selecting etc ///
    static bool objectIsCurrentlyDragged = false;
    

    if (!(ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow)))
    {
        
        ///////////////MouseLPMClickObject//////////////
        ///                                          ///
        switch (ev.getType())
        {
        case EventType::MouseLPMClickObject:
            if (!m_editableObjects->handleEventChildrenOnly(ev))
            {
                m_MouseInput->setLastClickedObject(nullptr);
                focusManager.changeFocus(nullptr);
            }
            break;
        
        ///                                         ///
        ///////////////////////////////////////////////




        /////////////////MouseLPMDrag///////////////////
        ///                                          ///
        case EventType::MouseLPMDrag: {
           
            if (m_MouseInput->getLastClickedObject())
            {
                ev.runEvent();
            }               
        }
                break;
        ///                                          ///
        ////////////////////////////////////////////////



        ////////////     MouseLPMRelease    /////////// 
        ///                                         ///
        case EventType::MouseLPMRelease: {
            objectIsCurrentlyDragged = false;
            }
            break;
        ///                                         ///
        ///////////////////////////////////////////////


        ///////////////MouseLPMClickDiv/////////////////
        ///                                          ///
        case EventType::MouseLPMClickDiv:
            m_editableObjects->handleEvent(ev);
            break;
        ///                                          ///
        ////////////////////////////////////////////////
        default:
            break;
        }
    }

    ///     ///     ///
    
}



void GameSceneUIDesigner::update()
{
    updateDearIMGUI();
}
