#include "PWW_Div.h"

PWW_Div::PWW_Div(std::string ID, sf::Color color, float posX, float posY, float sizeX, float sizeY, const std::function<void()>& func)
	:DivObject(ID,  color,  posX,  posY,  sizeX,  sizeY, func)
{
}

void PWW_Div::updateDearIMGUIParamWindow()
{
	std::cout << "TODO: ImGui param window for Div\n";
}
