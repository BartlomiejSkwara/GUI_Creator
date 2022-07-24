#pragma once
#include "PWW_Object.h"
#include "../GUI_Creator/values.h"


class PWW_Button : public PWW_Object
{
private:


    ButtonObject* m_buttonObject;
    ///Imgui stuff
   
    char* m_buttonLabel;
    float m_textColor[4];

public:

    
    

    PWW_Button(ButtonObject* button);
    ~PWW_Button();

    // Inherited via ParamWindowWrapper
    virtual void updateDearIMGUIParamWindow() override;

};

