#include "PWW_Div.h"

PWW_Div::PWW_Div(std::string ID, sf::Color color, float posX, float posY, float sizeX, float sizeY, const std::function<void()>& func)
	:DivObject(ID,  color,  posX,  posY,  sizeX,  sizeY, func)
{
}

void PWW_Div::updateDearIMGUIParamWindow()
{
    ImGui::SetWindowSize(sf::Vector2f(200, 400));
    ImGui::Text("Obiekt typu:");
    ImGui::SameLine();
    ImGui::TextColored(sf::Color(100, 100, 100), "kontener");

    ImGui::Text("Id obiektu: ");
    ImGui::SameLine();
    ImGui::TextColored(sf::Color(100, 100, 100), (this->getID()).c_str());




    ///
    ImGui::Separator();
    ///

    ImGui::Text("Pozycja i Wypelnienie: ");
    if (ImGui::InputInt2("X/Y", s_position)) {
        setPosition(s_position[0], s_position[1]);
        SelectionManager::getSelectionManager()->addSelectionSignifier(this);
    }

    ImGui::ColorEdit4("Kolor", s_fillColor);
    if (ImGui::IsItemEdited())
    {
        setColorFill((int)(s_fillColor[0] * 255), (int)(s_fillColor[1] * 255), (int)(s_fillColor[2] * 255), (int)(s_fillColor[3] * 255));
    }


    ///
    ImGui::Separator();
    ///

    ImGui::Text("Ramka:");

    ImGui::ColorEdit4("Ramka", s_outlineColor);
    if (ImGui::IsItemEdited())
    {
        setColorBorder((int)(s_outlineColor[0] * 255), (int)(s_outlineColor[1] * 255), (int)(s_outlineColor[2] * 255), (int)(s_outlineColor[3] * 255));
    }

    if (ImGui::InputInt("Grubosc", &s_outline_size)) {
        setBorderThickness(s_outline_size);

    }

    ///
    ImGui::Separator();
    ///
    ImGui::Text("Zaznaczenie");
    if (ImGui::SliderFloat("Promien", &s_selectionIndicatorSize, 0.f, 10.f)) {
        SelectionManager* selMan = SelectionManager::getSelectionManager();
        selMan->getFocusSignifier()->setRadius(5 * s_selectionIndicatorSize);
        selMan->addSelectionSignifier(this);

    }

    if (ImGui::SliderFloat("Alfa", &s_signifierColor[3], 0.f, 1.f)) {
        SelectionManager::getSelectionManager()->getFocusSignifier()->setFillColor(sf::Color((int)(s_signifierColor[0] * 255), (int)(s_signifierColor[1] * 255), (int)(s_signifierColor[2] * 255), (int)(s_signifierColor[3] * 255)));
    }
}

void PWW_Div::initVariables()
{
 
    s_position[0] = this->getGlobalBounds().left;
    s_position[1] = this->getGlobalBounds().top;

    s_outline_size = this->getBorderThickness();

    s_outlineColor[0] = (float)getColorBorder()->r / 255;
    s_outlineColor[1] = (float)getColorBorder()->g / 255;
    s_outlineColor[2] = (float)getColorBorder()->b / 255;
    s_outlineColor[3] = (float)getColorBorder()->a / 255;

    s_fillColor[0] = (float)getColorFill()->r / 255;
    s_fillColor[1] = (float)getColorFill()->g / 255;
    s_fillColor[2] = (float)getColorFill()->b / 255;
    s_fillColor[3] = (float)getColorFill()->a / 255;



    sf::Color ca = SelectionManager::getSelectionManager()->getFocusSignifier()->getFillColor();
    s_signifierColor[0] = (float)ca.r / 255;
    s_signifierColor[1] = (float)ca.g / 255;
    s_signifierColor[2] = (float)ca.b / 255;
    s_signifierColor[3] = (float)ca.a / 255;

    s_selectionIndicatorSize = SelectionManager::getSelectionManager()->getFocusSignifier()->getRadius() / 5;
}
