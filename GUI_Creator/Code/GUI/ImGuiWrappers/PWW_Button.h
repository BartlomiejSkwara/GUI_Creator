#pragma once
#include "../BasicWidgets/ButtonObject.h"
#include "../ImGuiWrappers/ParamWindowWrapper.h"
#include "../GUI_Creator/Code/Scenes/DesignerStuff/SelectionManager.h"
#include "../GUI_Creator/values.h"

#define MAX_LABEL_LENGTH 15
class PWW_Button :
    public ButtonObject, public ParamWindowWrapper
{
private:

   
    ///Imgui stuff
    static float s_selectionIndicatorSize;
    char *s_buttonLabel;
    static float s_outlineColor[4];
    static float s_fillColor[4];
    static float s_textColor[4];
    static float s_signifierColor[4];
    int m_position[2];

public:

    
    

    PWW_Button(std::string ID, sf::Font& font, std::string label, float positionX, float positionY, const std::function<void()>& func = []() {}, float sizeX = 100, float sizeY = 30, int charSize = 20, float scale = 1.f);
    ~PWW_Button();
    void initColors();

    // Inherited via ParamWindowWrapper
    virtual void updateDearIMGUIParamWindow() override;
};

