#pragma once
#include "PWW_Object.h"
#include "../../GUI_Creator/GUI_Creator/Code/GUI/BasicWidgets/ImageObject.h"
class PWW_Image :
    public PWW_Object
{
private:
    ImageObject* m_imageObject;
    int   m_selectedTexture;
public:
    PWW_Image(ImageObject* imageObject);

    // Inherited via PWW_Object
    virtual void updateDearIMGUIParamWindow() override;
};

