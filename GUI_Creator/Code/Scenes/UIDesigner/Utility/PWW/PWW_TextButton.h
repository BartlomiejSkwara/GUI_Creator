#pragma once
#include "PWW_Text.h"
#include "../GUI_Creator/values.h"


class PWW_TextButton : public PWW_Object
{
private:
    static constexpr size_t MAX_LABEL_LENGTH = 15;
protected:
    TextObject* m_textObject;
    ///Imgui stuff
    char* m_text;
    float m_textColor[4];
    int   m_selectedFont;
    int   m_charSize;
public:
    PWW_TextButton(TextObject* button);
    ~PWW_TextButton();

    // Inherited via ParamWindowWrapper
    virtual void updateDearIMGUIParamWindow() override;

};

