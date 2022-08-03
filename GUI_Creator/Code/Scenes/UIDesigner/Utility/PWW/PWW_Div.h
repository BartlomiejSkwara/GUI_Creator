#pragma once
#include "../../GUI_Creator/GUI_Creator/Code/GUI/BasicWidgets/DivObject.h"
#include "PWW_Object.h"


//#include "../GUI_Creator/Code/Scenes/DesignerStuff/SelectionManager.h"

class PWW_Div : public PWW_Object
{
private:
    
    DivObject* m_divObject;
    //SelectionManager* s_selectManager;

public:
    PWW_Div(DivObject* div);

    // Inherited via ParamWindowWrapper
    virtual void updateDearIMGUIParamWindow() override;
   

};

