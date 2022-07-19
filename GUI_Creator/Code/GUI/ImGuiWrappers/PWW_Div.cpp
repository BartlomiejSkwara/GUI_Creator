#include "PWW_Div.h"
int PWW_Div::s_size[] = { 0,0 };
SelectionManager* PWW_Div::s_selectManager = SelectionManager::getSelectionManager();

PWW_Div::PWW_Div(sf::Color color, float posX, float posY, float sizeX, float sizeY, const std::function<void()>& func)
	:DivObject(color,  posX,  posY,  sizeX,  sizeY, func)
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
        s_selectManager->changeFocus(this, this);
    }


    ImGui::ColorEdit4("Kolor", s_fillColor);
    if (ImGui::IsItemEdited())
    {
        setColorFill((int)(s_fillColor[0] * 255), (int)(s_fillColor[1] * 255), (int)(s_fillColor[2] * 255), (int)(s_fillColor[3] * 255));
    }


    ///
    ImGui::Separator();
    ///

    ImGui::Text("Wymiary: ");

    if (ImGui::InputInt("X", &s_size[0])) {
        this->setSize(s_size[0], s_size[1]);
        s_selectManager->changeFocus(this, this);

    }

    if (ImGui::InputInt("Y", &s_size[1])) {
        this->setSize(s_size[0], s_size[1]);
        s_selectManager->changeFocus(this, this);
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
        s_selectManager->getFocusSignifier()->setRadius(5 * s_selectionIndicatorSize);
        s_selectManager->changeFocus(this, this);

    }

    if (ImGui::SliderFloat("Alfa", &s_signifierColor[3], 0.f, 1.f)) {
        s_selectManager->getFocusSignifier()->setFillColor(sf::Color((int)(s_signifierColor[0] * 255), (int)(s_signifierColor[1] * 255), (int)(s_signifierColor[2] * 255), (int)(s_signifierColor[3] * 255)));
    }

    ///
    ImGui::Separator();
    ///
    ImGui::Text("Podobiekty:");
    if (ImGui::Button("Dodaj")) {

    }


}

void PWW_Div::initVariables()
{
    s_selectManager->setShowChildSelection(true);
    for (Object* child : m_DIVs) {
        s_selectManager->addChildSelectionSignifier(child);
    }

    s_size[0] = this->getGlobalBounds().width;
    s_size[1] = this->getGlobalBounds().height;

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



    sf::Color ca = s_selectManager->getFocusSignifier()->getFillColor();
    s_signifierColor[0] = (float)ca.r / 255;
    s_signifierColor[1] = (float)ca.g / 255;
    s_signifierColor[2] = (float)ca.b / 255;
    s_signifierColor[3] = (float)ca.a / 255;

    s_selectionIndicatorSize = s_selectManager->getFocusSignifier()->getRadius() / 5;
}
