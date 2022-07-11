#pragma once
#include "GameScene.h"
#include <SFML/Graphics/CircleShape.hpp>
#include "DesignerStuff/Generator.h"
#include "../GUI/ImGuiWrappers/ParamWindowWrapper_Button.h"
#include "../GUI/ImGuiWrappers/ParamWindowWrapper_Div.h"
#include "DesignerStuff/SelectionManager.h"

typedef int DESIGN_STATE;
class GameSceneUIDesigner : public GameScene
{
private:

    ///Managers and other singletons
    SelectionManager * selectManager;


    //Used to save and generate created UI's code
    Generator generator;


    //Imgui menu
    bool im_showParamWindow = false;
    

    
    



    virtual void initGameObjects(sf::Font* font) override;
    void initManagers();

    DivObject* m_editableObjects;

    static const DESIGN_STATE D_NONE = 1;
    static const DESIGN_STATE D_MOVE = 2;
    static const DESIGN_STATE D_SCALE = 4;


    
    //TODO::Usun¹æ design state albo zamieniæ na coœ innego obecnie musi tu byæ D_Move aby nie blokowaæ poruszania obiektami
    DESIGN_STATE m_currentDESIGN_STATE;

    //Drag related
    bool m_objectIsCurentlyDragged;

    //Toolbar related
    void toolbarAddButton();
    void toolbarAddDiv();
    
 

    


public:
      
    GameSceneUIDesigner(sf::Font* font, MouseInfo* mouseinfo, sf::RenderWindow* window);
    virtual ~GameSceneUIDesigner();
    virtual void pollEvents(sf::Event* ev) override;

    // Inherited via GameScene
    //main update
    virtual void update() override;
    //minor updates :>
    virtual void updateClickables() override;
    
    virtual void render() override;

   
    virtual void updateMouseRelated() override;


    // Inherited via GameScene
    virtual void updateDragging() override;


    // ImGui related
    virtual void updateDearIMGUI() override;

    void updateDearIMGUIMainMenuBar();
    void updateDearIMGUIParamWindow();

   
};

