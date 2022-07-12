#pragma once
#include "../BasicWidgets/DivObject.h"
#include "../ImGuiWrappers/ParamWindowWrapper.h"
#include "../GUI_Creator/Code/Scenes/DesignerStuff/SelectionManager.h"

class PWW_Div :
    public DivObject, public ParamWindowWrapper
{
public:
    PWW_Div(std::string ID, sf::Color color, float posX, float posY, float sizeX, float sizeY, const std::function<void()>& func = []() {});

    // Inherited via ParamWindowWrapper
    virtual void updateDearIMGUIParamWindow() override;
   

    // Inherited via ParamWindowWrapper
    virtual void initVariables() override;

};

