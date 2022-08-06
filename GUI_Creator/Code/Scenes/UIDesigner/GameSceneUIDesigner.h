#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include "../GameScene.h"
#include "Utility/FocusManager.h"
#include "Utility/PWW/PWWManager.h"
#include "Utility/Generator.h"
#include <iostream>

class GameSceneUIDesigner : public GameScene
{
private:




    ///Managers and/or singletons
    FocusManager focusManager;
    PWWManager pwwManager;

    //Used to save and generate created UI's code
    Generator generator;


    //Imgui menu
    
    //PWW
    bool im_showParamWindow = false;
    //Indicator settings
    bool im_showIndicatorParamWindow = false;
    float m_selectionIndicatorSize;
    float m_signifierColor[4];
    void initIndicatorSettings();
    void updateIndicatorSettings();
    
    



    virtual void initGameObjects(sf::Font* font) override;
    void initManagers();
    //TODO zmiany to ma byæ dodane do m_scene a inicjalizacja m_scene wraca do klasy GameScene czy jakoœ tak
    DivObject* m_editableObjects;


    //Editor stuff
    bool m_objectIsCurrentlyDragged;

    void modeMOVE();
    void modePICK();


    //Toolbar related
    void toolbarAddButton();
    void toolbarAddDiv();
    void toolbarAddText();
    void toolbarAddImage();

    


public:
      
    GameSceneUIDesigner(sf::RenderWindow* window);
    virtual ~GameSceneUIDesigner();
    virtual void pollEvents(sf::Event* ev) override;

    // Inherited via GameScene
    //main update
    virtual void update() override;

    virtual void render() override;

   
  

    // ImGui related
    virtual void updateDearIMGUI() override;

    void updateDearIMGUIMainMenuBar();


   

    // Inherited via Observer
    virtual void onNotify(Event ev) override;

};

