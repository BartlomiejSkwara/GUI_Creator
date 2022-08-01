#pragma once
#include "../GUI_Creator/imgui/imgui.h"
#include "../GUI_Creator/imgui/imgui-SFML.h"
#include "../../../../GUI/BasicWidgets/DivObject.h"
#include "../SelectionManager.h"
#include "../GUI_Creator/Code/ResourceManaging/ResourceManager.h"
#include "PWW_Div.h"
#include "PWW_TextButton.h"
#include "PWW_Text.h"
#include "PWW_Image.h"
class PWWManager
{
private:

	PWW_Object* object;

	std::string temp;

	SelectionManager* m_selectManager;
	ResourceManager* m_resourceManager;

public:
	PWWManager();

	void updatePWW();

	void initDIV(DivObject* div);
	void initImage(ImageObject* image);
	void initText(TextObject* text);
	void initTextButton(TextObject* button);
	void initImageButton();
};

