#include "PWW_Image.h"

PWW_Image::PWW_Image(ImageObject* imageObject) : PWW_Object(imageObject), m_imageObject(imageObject)
{
    auto it = resourceManager->getTexturesIterators();
    for (auto i = it.first; i != it.second; i++)
    {
        if (m_imageObject->getTextureName() == i->first)
        {

            m_selectedTexture = std::distance(it.first, i);

        }
    }

}

void PWW_Image::updateDearIMGUIParamWindow()
{
    ImGui::SetWindowSize(sf::Vector2f(200, 400));
    ImGui::Text("Obiekt typu:");
    ImGui::SameLine();
    ImGui::TextColored(sf::Color(100, 100, 100), "obraz");

    ImGui::Text("Id obiektu: ");
    ImGui::SameLine();
    ImGui::TextColored(sf::Color(100, 100, 100), m_imageObject->getID().c_str());


    ///
    ImGui::Separator();
    ///

    ImGui::Text("Skala:");
    if (ImGui::DragFloat("##pwwImageSca", &m_scale[0], DRAG_SPEED,0)) {
        m_imageObject->setScale(m_scale[0], m_scale[0]);
        m_size[0] = m_imageObject->getGlobalBounds().width;
        m_size[1] = m_imageObject->getGlobalBounds().height;
    }

    ImGui::Text("Ramka:");
    if (ImGui::InputInt2("##pwwImagePos", m_position)) {
        m_imageObject->setPosition(m_position[0], m_position[1]);
    }
    ImGui::SameLine();
    ImGui::Text("Pozycja");

    if (ImGui::InputInt2("##pwwImageDim", m_size)) {
        m_size[0] = m_imageObject->getGlobalBounds().width;
        m_size[1] = m_imageObject->getGlobalBounds().height;
    }
    ImGui::SameLine();
    ImGui::Text("Wymiary");

    if (ImGui::InputInt("##pwwImageBorderThick", &m_outline_size)) {
        m_imageObject->setBorderThickness(m_outline_size);
        m_size[0] = (int)(m_imageObject->getGlobalBounds().width);
        m_size[1] = (int)(m_imageObject->getGlobalBounds().height);

    }
    ///
    ImGui::Separator();
    ///
    ImGui::ColorEdit4("##pwwImageFillCol", m_fillColor);
    if (ImGui::IsItemEdited())
    {
        m_imageObject->setColorFill((int)(m_fillColor[0] * 255), (int)(m_fillColor[1] * 255), (int)(m_fillColor[2] * 255), (int)(m_fillColor[3] * 255));
    }
    ImGui::SameLine();
    ImGui::Text("Wypelnienie");

    ImGui::ColorEdit4("##pwwImageBorderCol", m_outlineColor);
    if (ImGui::IsItemEdited())
    {
        m_imageObject->setColorBorder((int)(m_outlineColor[0] * 255), (int)(m_outlineColor[1] * 255), (int)(m_outlineColor[2] * 255), (int)(m_outlineColor[3] * 255));
    }
    ImGui::SameLine();
    ImGui::Text("Ramka");
    ///
    ImGui::Separator();
    ///
    ImGui::Text("Tekstura:");
    if (ImGui::BeginListBox("##textures", ImVec2(-FLT_MIN, 150)))
    {


        auto it = resourceManager->getTexturesIterators();
        for (auto i = it.first; i != it.second; i++) {

            if (ImGui::Selectable(i->first.c_str(),
                (std::distance(it.first, i) == m_selectedTexture) ? true : false
            ))
            {
                m_selectedTexture = std::distance(it.first, i);
                m_imageObject->setTexture(i->first);
                m_imageObject->fitBorderToSprite();                
            }
        }

        ImGui::EndListBox();
    }


}
