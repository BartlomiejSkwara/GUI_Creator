#include "PWW_TextButton.h"

PWW_TextButton::PWW_TextButton(TextObject* button): m_TextObject(button)

    
{
    //TODO Correct it so that the char* won't be filled twice
    m_buttonLabel = new char[15];
    for (int i = 0; i < MAX_LABEL_LENGTH; i++) {
        *(m_buttonLabel + i) = '\0';
    }

    std::string temp = button->getText()->getString().toAnsiString();
    for (int i = 0;
        i < (MAX_LABEL_LENGTH > temp.size() ? MAX_LABEL_LENGTH : temp.size());
        i++) {
        if (temp[i] != '\0') {
            m_buttonLabel[i] = temp.at(i);
        }
        else {
            break;
        }
    }


    m_textColor[0] = (float)button->getColorText()->r / 255;
    m_textColor[1] = (float)button->getColorText()->g / 255;
    m_textColor[2] = (float)button->getColorText()->b / 255;
    m_textColor[3] = (float)button->getColorText()->a / 255;

   
}

PWW_TextButton::~PWW_TextButton()
{
    
}



void PWW_TextButton::updateDearIMGUIParamWindow()
{

    ImGui::SetWindowSize(sf::Vector2f(200, 400));
    ImGui::Text("Obiekt typu:");
    ImGui::SameLine();
    ImGui::TextColored(sf::Color(100, 100, 100), "tekst");
    ImGui::Text("Id obiektu: ");
    ImGui::SameLine();
    ImGui::TextColored( sf::Color(100, 100, 100),  m_TextObject->getID().c_str());

   
    ///
    ImGui::Separator();
    ///

    ImGui::Text("Pozycja i Wypelnienie: ");
    if (ImGui::InputInt2("X/Y", m_position)) {
        m_TextObject->setPosition(m_position[0], m_position[1]);
        m_TextObject->centerText();
        SelectionManager::getSelectionManager()->changeFocus(m_TextObject);
        
    }
    
    ImGui::ColorEdit4("Kolor", m_fillColor);
    if (ImGui::IsItemEdited())
    {
        m_TextObject->setColorFill((int)(m_fillColor[0] * 255), (int)(m_fillColor[1] * 255), (int)(m_fillColor[2] * 255), (int)(m_fillColor[3] * 255));
    }
    


    ///
    ImGui::Separator();
    ///
    


    ImGui::Text("Napis:");
   

    if (ImGui::InputText("Napis", m_buttonLabel, MAX_LABEL_LENGTH))
    {
        m_TextObject->initText(std::string(m_buttonLabel));

        //m_TextObject->fitBorderToText();
        m_TextObject->centerText();
        //selectManager->changeFocus(m_TextObject);
    }
    ImGui::ColorEdit4("Tekst",m_textColor);
    if (ImGui::IsItemEdited())
    {
        m_TextObject->setColorText((int)(m_textColor[0] * 255), (int)(m_textColor[1] * 255), (int)(m_textColor[2] * 255), (int)(m_textColor[3] * 255));
    }


    ///
    ImGui::Separator();
    ///



    ImGui::Text("Ramka:");
 
    ImGui::ColorEdit4("Ramka", m_outlineColor);
    if (ImGui::IsItemEdited())
    {
        m_TextObject->setColorBorder((int)(m_outlineColor[0] * 255), (int)(m_outlineColor[1] * 255), (int)(m_outlineColor[2] * 255), (int)(m_outlineColor[3] * 255));
    }

    if (ImGui::InputInt("Grubosc", &m_outline_size)) {
        m_TextObject->setBorderThickness(m_outline_size);

    }

    ///
    ImGui::Separator();
    ///
    ImGui::Text("Zaznaczenie");
    if (ImGui::SliderFloat("Promien", &m_selectionIndicatorSize, 0.f, 10.f)) {
        SelectionManager* selMan = SelectionManager::getSelectionManager();
        selMan->getFocusSignifier()->setRadius(5 * m_selectionIndicatorSize);
        selMan->changeFocus(m_TextObject);

    }

    if (ImGui::SliderFloat("Alfa", &m_signifierColor[3], 0.f, 1.f)) {
        SelectionManager::getSelectionManager()->getFocusSignifier()->setFillColor(sf::Color((int)(m_signifierColor[0] * 255), (int)(m_signifierColor[1] * 255), (int)(m_signifierColor[2] * 255), (int)(m_signifierColor[3] * 255)));
    }


}


