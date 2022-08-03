#pragma once
#include "PWW_Object.h"
#include "../GUI_Creator/values.h"

class PWW_Text : public PWW_Object
{
private:
    static constexpr size_t MAX_TEXT_LENGTH = 30;
protected:
    TextObject* m_textObject;
    ///Imgui stuff
    char* m_text;
    float m_textColor[4];
    int   m_selectedFont;
    int   m_charSize;

   
public:

    
    

    PWW_Text(TextObject* text);
    ~PWW_Text();

    // Inherited via ParamWindowWrapper
    virtual void updateDearIMGUIParamWindow() override;

};

