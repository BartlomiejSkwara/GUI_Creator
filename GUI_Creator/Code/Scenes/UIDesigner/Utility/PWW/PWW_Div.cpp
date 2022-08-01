#include "PWW_Div.h"

PWW_Div::PWW_Div(DivObject* div): PWW_Object(div), m_divObject(div)
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
    ImGui::TextColored(sf::Color(100, 100, 100), (m_divObject->getID()).c_str());



    ///
    ImGui::Separator();
    ///

    ImGui::Text("Skala:");
    if (ImGui::DragFloat("##pwwContainerSca", &m_scale[0],DRAG_SPEED,0)) {
        m_divObject->setScale(m_scale[0], m_scale[0]);
        
        SelectionManager::getSelectionManager()->changeFocus(m_divObject);
        m_size[0] = m_divObject->getGlobalBounds().width;
        m_size[1] = m_divObject->getGlobalBounds().height;
    }


    ImGui::Text("Ramka:");
    if (ImGui::InputInt2("##pwwContainerPos", m_position)) {
        m_divObject->setPosition(m_position[0], m_position[1]);
        selectManager->changeFocus(m_divObject);
    }
    ImGui::SameLine();
    ImGui::Text("Pozycja");

    if (ImGui::InputInt2("##pwwContainerDim", m_size)) {
        m_divObject->setBorderSize(m_size[0], m_size[1]);
        selectManager->changeFocus(m_divObject);
    }
    ImGui::SameLine();
    ImGui::Text("Wymiary");

    if (ImGui::InputInt("##pwwContainerBorderThick", &m_outline_size)) {
        m_divObject->setBorderThickness(m_outline_size);

    }

    ///
    ImGui::Separator();
    ///

    ImGui::ColorEdit4("##pwwContainerFillCol", m_fillColor);
    if (ImGui::IsItemEdited())
    {
        m_divObject->setColorFill((int)(m_fillColor[0] * 255), (int)(m_fillColor[1] * 255), (int)(m_fillColor[2] * 255), (int)(m_fillColor[3] * 255));
    }
    ImGui::SameLine();
    ImGui::Text("Wypelnienie");

    ImGui::ColorEdit4("##pwwContainerBorderCol", m_outlineColor);
    if (ImGui::IsItemEdited())
    {
        m_divObject->setColorBorder((int)(m_outlineColor[0] * 255), (int)(m_outlineColor[1] * 255), (int)(m_outlineColor[2] * 255), (int)(m_outlineColor[3] * 255));
    }
    ImGui::SameLine();
    ImGui::Text("Ramka");

    ///
    ImGui::Separator();
    ///


    
    ///
    ImGui::Separator();
    ///
    ImGui::Text("Podobiekty:");
    if (ImGui::Button("Dodaj")) {

    }
    ImGui::SameLine();
    if (ImGui::Button("Usun")) {

    }


}

