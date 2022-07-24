#pragma once
#include "../GUI_Creator/imgui/imgui.h"
#include "../GUI_Creator/imgui/imgui-SFML.h"
#include "../../../../GUI/BasicWidgets/DivObject.h"
#include "../SelectionManager.h"
#include "PWW_Div.h"
#include "PWW_Button.h"

class PWWManager
{
private:

	PWW_Object* object;

	std::string temp;
	
	SelectionManager* selectManager;

public:
	PWWManager();

	void updatePWW();

	void initDIV(DivObject* div);
	void initImage();
	void initText();
	void initTextButton(ButtonObject* button);
	void initImageButton();
	void initObject(Object*obj);
};

