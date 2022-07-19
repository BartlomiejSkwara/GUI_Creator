#pragma once
#include "../BasicWidgets/DivObject.h"
#include "../ImGuiWrappers/ParamWindowWrapper.h"
#include "../GUI_Creator/Code/Scenes/DesignerStuff/SelectionManager.h"

class PWW_Div :
    public DivObject, public ParamWindowWrapper
{
private:
    static int s_size[2];
    static SelectionManager* s_selectManager;

public:
    PWW_Div(sf::Color color, float posX, float posY, float sizeX, float sizeY, const std::function<void()>& func = []() {});

    // Inherited via ParamWindowWrapper
    virtual void updateDearIMGUIParamWindow() override;
   

    // Inherited via ParamWindowWrapper
    virtual void initVariables() override;

};

