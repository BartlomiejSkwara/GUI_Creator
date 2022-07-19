#pragma once
#include "../BasicWidgets/ButtonObject.h"
#include "../ImGuiWrappers/ParamWindowWrapper.h"
#include "../GUI_Creator/values.h"
#include "../GUI_Creator/Code/Scenes/DesignerStuff/SelectionManager.h"

#define MAX_LABEL_LENGTH 15
class PWW_Button :
    public ButtonObject, public ParamWindowWrapper
{
private:

    ///Imgui stuff
   
    static char *s_buttonLabel;
    static float s_textColor[4];

public:

    
    

    PWW_Button(sf::Font& font, std::string label, float positionX, float positionY, const std::function<void()>& func = []() {}, float sizeX = 100, float sizeY = 30, int charSize = 20, float scale = 1.f);
    ~PWW_Button();

    virtual void initVariables() override;

    // Inherited via ParamWindowWrapper
    virtual void updateDearIMGUIParamWindow() override;

   static void deleteStaticPointers();
};

