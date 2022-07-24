#include "PWW_Div.h"

PWW_Div::PWW_Div(DivObject* div, int width, int height): m_divObject(div)
{
    m_size[0] = width;
    m_size[1] = height;
}

void PWW_Div::updateDearIMGUIParamWindow()
{
    ImGui::SetWindowSize(sf::Vector2f(200, 400));
    ImGui::Text("Obiekt typu:");
    ImGui::SameLine();
    ImGui::TextColored(sf::Color(100, 100, 100), "kontener");

    ImGui::Text("Id obiektu: ");
    ImGui::SameLine();
    ImGui::TextColored(sf::Color(100, 100, 100), (m_divObject->getID()).c_str());



    ///
    ImGui::Separator();
    ///

    ImGui::Text("Pozycja i Wypelnienie: ");
    if (ImGui::InputInt2("X/Y", m_position)) {
        m_divObject->setPosition(m_position[0], m_position[1]);
        selectManager->changeFocus(m_divObject);
    }


    ImGui::ColorEdit4("Kolor", m_fillColor);
    if (ImGui::IsItemEdited())
    {
        m_divObject->setColorFill((int)(m_fillColor[0] * 255), (int)(m_fillColor[1] * 255), (int)(m_fillColor[2] * 255), (int)(m_fillColor[3] * 255));
    }


    ///
    ImGui::Separator();
    ///

    ImGui::Text("Wymiary: ");

    if (ImGui::InputInt("X", &m_size[0])) {
        m_divObject->setSize(m_size[0], m_size[1]);
        selectManager->changeFocus(m_divObject);

    }

    if (ImGui::InputInt("Y", &m_size[1])) {
        m_divObject->setSize(m_size[0], m_size[1]);
        selectManager->changeFocus(m_divObject);
    }




    ///
    ImGui::Separator();
    ///

    ImGui::Text("Ramka:");

    ImGui::ColorEdit4("Ramka", m_outlineColor);
    if (ImGui::IsItemEdited())
    {
        m_divObject->setColorBorder((int)(m_outlineColor[0] * 255), (int)(m_outlineColor[1] * 255), (int)(m_outlineColor[2] * 255), (int)(m_outlineColor[3] * 255));
    }

    if (ImGui::InputInt("Grubosc", &m_outline_size)) {
        m_divObject->setBorderThickness(m_outline_size);

    }

    ///
    ImGui::Separator();
    ///
    ImGui::Text("Zaznaczenie");
    if (ImGui::SliderFloat("Promien", &m_selectionIndicatorSize, 0.f, 10.f)) {
        selectManager->getFocusSignifier()->setRadius(5 * m_selectionIndicatorSize);
        selectManager->changeFocus(m_divObject);

    }

    if (ImGui::SliderFloat("Alfa", &m_signifierColor[3], 0.f, 1.f)) {
        selectManager->getFocusSignifier()->setFillColor(sf::Color((int)(m_signifierColor[0] * 255), (int)(m_signifierColor[1] * 255), (int)(m_signifierColor[2] * 255), (int)(m_signifierColor[3] * 255)));
    }

    ///
    ImGui::Separator();
    ///
    ImGui::Text("Podobiekty:");
    if (ImGui::Button("Dodaj")) {

    }


}

