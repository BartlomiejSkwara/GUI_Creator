#pragma once
#include "PWW_Object.h"
#include "../GUI_Creator/values.h"


class PWW_TextButton : public PWW_Object
{
private:


    TextObject* m_TextObject;
    ///Imgui stuff
   
    char* m_buttonLabel;
    float m_textColor[4];

public:

    
    

    PWW_TextButton(TextObject* button);
    ~PWW_TextButton();

    // Inherited via ParamWindowWrapper
    virtual void updateDearIMGUIParamWindow() override;

};

