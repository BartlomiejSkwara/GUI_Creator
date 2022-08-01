#include "PWW_Text.h"

PWW_Text::PWW_Text(TextObject* text): PWW_Object(text), m_textObject(text)
{
    //TODO Correct it so that the char* won't be filled twice
    m_text = new char[MAX_TEXT_LENGTH];
    for (int i = 0; i < MAX_TEXT_LENGTH; i++) {
        *(m_text + i) = '\0';
    }

    std::string temp = text->getText()->getString().toAnsiString();
    for (int i = 0;
        i < (MAX_TEXT_LENGTH > temp.size() ? MAX_TEXT_LENGTH : temp.size());
        i++) {
        if (temp[i] != '\0') {
            m_text[i] = temp.at(i);
        }
        else {
            break;
        }
    }


    m_textColor[0] = (float)text->getColorText()->r / 255;
    m_textColor[1] = (float)text->getColorText()->g / 255;
    m_textColor[2] = (float)text->getColorText()->b / 255;
    m_textColor[3] = (float)text->getColorText()->a / 255;


    auto it = resourceManager->getFontsIterators();
    for (auto i = it.first; i != it.second; i++) 
    {
        if (m_textObject->getFontName() == i->first)
        {
            
            m_selectedFont = std::distance(it.first,i);
            
        }
    }

    m_charSize = m_textObject->getCharacterSize();
}

PWW_Text::~PWW_Text()
{
    delete m_text;
}

void PWW_Text::updateDearIMGUIParamWindow()
{
    ImGui::SetWindowSize(sf::Vector2f(200, 400));
    ImGui::Text("Obiekt typu:");
    ImGui::SameLine();
    ImGui::TextColored(sf::Color(100, 100, 100), "tekst");

    ImGui::Text("Id obiektu: ");
    ImGui::SameLine();
    ImGui::TextColored(sf::Color(100, 100, 100), m_textObject->getID().c_str());
 

    ///
    ImGui::Separator();
    ///
    
    ImGui::Text("Skala:");
    if (ImGui::DragFloat("##pwwTextSca", &m_scale[0], DRAG_SPEED,0)) {
        m_textObject->setScale(m_scale[0], m_scale[0]);
        m_textObject->fitBorderToText();
        m_textObject->centerText();
        SelectionManager::getSelectionManager()->changeFocus(m_textObject);
        m_size[0] = m_textObject->getGlobalBounds().width;
        m_size[1] = m_textObject->getGlobalBounds().height;
    }


    ImGui::Text("Ramka:");
    if (ImGui::InputInt2("##pwwTextPos", m_position)) {
        m_textObject->setPosition(m_position[0], m_position[1]);
        m_textObject->centerText();
        SelectionManager::getSelectionManager()->changeFocus(m_textObject);
    }
    ImGui::SameLine();
    ImGui::Text("Pozycja");

    if (ImGui::InputInt2("##pwwTextDim", m_size)) {
        m_size[0] = m_textObject->getGlobalBounds().width;
        m_size[1] = m_textObject->getGlobalBounds().height;
    }
    ImGui::SameLine();
    ImGui::Text("Wymiary");

    if (ImGui::InputInt("##pwwTextBorderThick", &m_outline_size)) {
        m_textObject->setBorderThickness(m_outline_size);
        m_size[0] = m_textObject->getGlobalBounds().width;
        m_size[1] = m_textObject->getGlobalBounds().height;

    }
    ///
    ImGui::Separator();
    ///
    ImGui::ColorEdit4("##pwwTextFillCol", m_fillColor);
    if (ImGui::IsItemEdited())
    {
        m_textObject->setColorFill((int)(m_fillColor[0] * 255), (int)(m_fillColor[1] * 255), (int)(m_fillColor[2] * 255), (int)(m_fillColor[3] * 255));
    }
    ImGui::SameLine();
    ImGui::Text("Wypelnienie");

    ImGui::ColorEdit4("##pwwTextBorderCol", m_outlineColor);
    if (ImGui::IsItemEdited())
    {
        m_textObject->setColorBorder((int)(m_outlineColor[0] * 255), (int)(m_outlineColor[1] * 255), (int)(m_outlineColor[2] * 255), (int)(m_outlineColor[3] * 255));
    }
    ImGui::SameLine();
    ImGui::Text("Ramka");
    ///
    ImGui::Separator();
    ///



    ImGui::Text("Napis:");


    if (ImGui::InputText("##pwwText", m_text, MAX_TEXT_LENGTH))
    {
        m_textObject->initText(std::string(m_text));

        m_textObject->fitBorderToText();
        m_textObject->centerText();
        selectManager->changeFocus(m_textObject);
        m_size[0] = m_textObject->getGlobalBounds().width;
        m_size[1] = m_textObject->getGlobalBounds().height;
    }


    ImGui::Text("Czcionka:");
    if (ImGui::BeginListBox("##fonts", ImVec2(-FLT_MIN, 50)))
    {


        auto it = resourceManager->getFontsIterators();
        for (auto i = it.first; i != it.second; i++) {

            if (ImGui::Selectable(i->first.c_str(),
                (std::distance(it.first, i) == m_selectedFont) ? true : false
            ))
            {
                m_selectedFont = std::distance(it.first, i);
                m_textObject->setFont(i->first);
                SelectionManager::getSelectionManager()->changeFocus(m_textObject);
                m_textObject->fitBorderToText();
                m_textObject->centerText();
                selectManager->changeFocus(m_textObject);
            }
        }

        ImGui::EndListBox();
    }

    if (ImGui::InputInt("##pwwTextCharSize", &m_charSize))
    {
        m_textObject->setCharacterSize(m_charSize);
        m_textObject->fitBorderToText();
        m_textObject->centerText();
        selectManager->changeFocus(m_textObject);
    }
    ImGui::SameLine();
    ImGui::Text("Rozmiar");

    ImGui::ColorEdit4("##pwwTextColor", m_textColor);
    if (ImGui::IsItemEdited())
    {
        m_textObject->setColorText((int)(m_textColor[0] * 255), (int)(m_textColor[1] * 255), (int)(m_textColor[2] * 255), (int)(m_textColor[3] * 255));
    }
    ImGui::SameLine();
    ImGui::Text("Kolor");

   




}




