#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include "../GameScene.h"
#include "Utility/SelectionManager.h"
#include "Utility/PWW/PWWManager.h"
#include "Utility/Generator.h"
#include "../ObserverStuff/ObserverUID.h"
#include "../../ResourceManaging/ResourceManager.h"
class GameSceneUIDesigner : public GameScene
{
private:




    ///Managers and/or singletons
    SelectionManager* selectManager;
    PWWManager pwwManager;

    //Used to save and generate created UI's code
    Generator generator;


    //Imgui menu
    bool im_showParamWindow = false;
    

    
    



    virtual void initGameObjects(sf::Font* font) override;
    void initManagers();
    //TODO zmiany to ma byæ dodane do m_scene a inicjalizacja m_scene wraca do klasy GameScene czy jakoœ tak
    DivObject* m_editableObjects;


    //Mode related
    bool m_objectIsCurrentlyDragged;
    bool m_objectIsCurrentlyPicked;

    void modeMOVE();
    void modePICK();


    //Toolbar related
    void toolbarAddButton();
    void toolbarAddDiv();
    void toolbarAddText();
 

    


public:
      
    GameSceneUIDesigner(ResourceManager* rm, sf::RenderWindow* window);
    virtual ~GameSceneUIDesigner();
    virtual void pollEvents(sf::Event* ev) override;

    // Inherited via GameScene
    //main update
    virtual void update() override;
    //minor updates :>
    virtual void updateClickables() override;
    
    virtual void render() override;

   
    virtual void updateMouseRelated() override;




    // ImGui related
    virtual void updateDearIMGUI() override;

    void updateDearIMGUIMainMenuBar();


   
};

