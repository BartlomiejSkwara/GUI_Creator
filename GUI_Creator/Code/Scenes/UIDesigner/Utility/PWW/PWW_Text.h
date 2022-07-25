#pragma once
#include "PWW_Object.h"
#include "../GUI_Creator/values.h"


class PWW_Text : public PWW_Object
{
private:


    TextObject* m_TextObject;
    ///Imgui stuff
   
    char* m_Text;
    float m_textColor[4];

public:

    
    

    PWW_Text(TextObject* text);
    ~PWW_Text();

    // Inherited via ParamWindowWrapper
    virtual void updateDearIMGUIParamWindow() override;

};

