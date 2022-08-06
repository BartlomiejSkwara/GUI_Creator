#include "PWW_TextButton.h"

PWW_TextButton::PWW_TextButton(TextObject* button):PWW_Object(button), m_textObject(button)

    
{
    //TODO Correct it so that the char* won't be filled twice
    m_text = new char[MAX_LABEL_LENGTH];
    for (int i = 0; i < MAX_LABEL_LENGTH; i++) {
        *(m_text + i) = '\0';
    }

    std::string temp = button->getText()->getString().toAnsiString();
    for (int i = 0;
        i < (MAX_LABEL_LENGTH > temp.size() ? MAX_LABEL_LENGTH : temp.size());
        i++) {
        if (temp[i] != '\0') {
            m_text[i] = temp.at(i);
        }
        else {
            break;
        }
    }


    m_textColor[0] = (float)button->getColorText()->r / 255;
    m_textColor[1] = (float)button->getColorText()->g / 255;
    m_textColor[2] = (float)button->getColorText()->b / 255;
    m_textColor[3] = (float)button->getColorText()->a / 255;

    auto it = resourceManager->getFontsIterators();
    for (auto i = it.first; i != it.second; i++)
    {

        if (m_textObject->getFontName() == i->first)
        {

            m_selectedFont = std::distance(it.first, i);

        }
    }

    m_charSize = m_textObject->getCharacterSize();
}

PWW_TextButton::~PWW_TextButton()
{
    delete m_text;
}



void PWW_TextButton::updateDearIMGUIParamWindow()
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
    if (ImGui::DragFloat("##pwwTextButtonSca", &m_scale[0], DRAG_SPEED,0)) {
        m_textObject->setScale(m_scale[0], m_scale[0]);
        m_textObject->centerText();
        m_size[0] = m_textObject->getGlobalBounds().width;
        m_size[1] = m_textObject->getGlobalBounds().height;
    }


    ImGui::Text("Ramka:");
    if (ImGui::InputInt2("##pwwTextButtonPos", m_position)) {
        m_textObject->setPosition(m_position[0], m_position[1]);
        m_textObject->centerText();
        
    }
    ImGui::SameLine();
    ImGui::Text("Pozycja");

    if (ImGui::InputInt2("##pwwTextButtonDim", m_size)) {
        m_size[0] = m_textObject->getGlobalBounds().width;
        m_size[1] = m_textObject->getGlobalBounds().height;
    }
    ImGui::SameLine();
    ImGui::Text("Wymiary");

    if (ImGui::InputInt("##pwwTextButtonBorderThick", &m_outline_size)) {
        m_textObject->setBorderThickness(m_outline_size);
        m_size[0] = m_textObject->getGlobalBounds().width;
        m_size[1] = m_textObject->getGlobalBounds().height;

    }
    ///
    ImGui::Separator();
    ///
    ImGui::ColorEdit4("##pwwTextButtonFillCol", m_fillColor);
    if (ImGui::IsItemEdited())
    {
        m_textObject->setColorFill((int)(m_fillColor[0] * 255), (int)(m_fillColor[1] * 255), (int)(m_fillColor[2] * 255), (int)(m_fillColor[3] * 255));
    }
    ImGui::SameLine();
    ImGui::Text("Wypelnienie");

    ImGui::ColorEdit4("##pwwTextButtonBorderCol", m_outlineColor);
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


    if (ImGui::InputText("##pwwTextButton", m_text, MAX_LABEL_LENGTH))
    {
        m_textObject->initText(std::string(m_text));
        m_textObject->centerText();
        m_size[0] = m_textObject->getGlobalBounds().width;
        m_size[1] = m_textObject->getGlobalBounds().height;
    }


    ImGui::Text("Czcionka:");
    if (ImGui::BeginListBox("##fontsButton", ImVec2(-FLT_MIN, 50)))
    {


        auto it = resourceManager->getFontsIterators();
        for (auto i = it.first; i != it.second; i++) {

            if (ImGui::Selectable(i->first.c_str(),
                (std::distance(it.first, i) == m_selectedFont) ? true : false
            ))
            {
                m_selectedFont = std::distance(it.first, i);
                m_textObject->setFont(i->first);
                m_textObject->centerText();
            }
        }

       
        ImGui::EndListBox();
    }

    if (ImGui::InputInt("##pwwTextButtonCharSize", &m_charSize))
    {
        m_textObject->setCharacterSize(m_charSize);
        m_textObject->centerText();
    }
    ImGui::SameLine();
    ImGui::Text("Rozmiar");

    ImGui::ColorEdit4("##pwwTextButtonColor", m_textColor);
    if (ImGui::IsItemEdited())
    {
        m_textObject->setColorText((int)(m_textColor[0] * 255), (int)(m_textColor[1] * 255), (int)(m_textColor[2] * 255), (int)(m_textColor[3] * 255));
    }
    ImGui::SameLine();
    ImGui::Text("Kolor");

    
}


