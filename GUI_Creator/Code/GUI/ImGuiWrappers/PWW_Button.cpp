#include "PWW_Button.h"


float PWW_Button::s_textColor[] = { 0,0,0,0 };
char* PWW_Button::s_buttonLabel = new char[15];



PWW_Button::PWW_Button(std::string ID, sf::Font& font, std::string label, float positionX, float positionY, const std::function<void()>& func, float sizeX, float sizeY, int charSize, float scale)
    :ButtonObject(ID, font, label, positionX, positionY, func, sizeX, sizeY, charSize, scale)
    
{
    s_buttonLabel = new char[15];
    for (int i = 0; i < MAX_LABEL_LENGTH; i++) {
        *(s_buttonLabel + i) = '\0';
    }
   
}

PWW_Button::~PWW_Button()
{
    
}

void PWW_Button::initVariables()
{
    std::string temp = getText()->getString().toAnsiString();
    for (int i = 0; 
        i < (MAX_LABEL_LENGTH>temp.size()? MAX_LABEL_LENGTH : temp.size()); 
        i++) {
        if (temp[i] != '\0') {
            s_buttonLabel[i] = temp.at(i);
        }
        else {
            break;
        }
    }

    s_outline_size = this->getBorderThickness();

    s_position[0] = this->getGlobalBounds().left;
    s_position[1] = this->getGlobalBounds().top;

    s_outlineColor[0] = (float)getColorBorder()->r/255;
    s_outlineColor[1] = (float)getColorBorder()->g/255;
    s_outlineColor[2] = (float)getColorBorder()->b/255;
    s_outlineColor[3] = (float)getColorBorder()->a/255;

    s_fillColor[0] = (float)getColorFill()->r/255;
    s_fillColor[1] = (float)getColorFill()->g/255;
    s_fillColor[2] = (float)getColorFill()->b/255;
    s_fillColor[3] = (float)getColorFill()->a/255;
    
    s_textColor[0] = (float)getColorText()->r/255;
    s_textColor[1] = (float)getColorText()->g/255;
    s_textColor[2] = (float)getColorText()->b/255;
    s_textColor[3] = (float)getColorText()->a/255;


    sf::Color ca = SelectionManager::getSelectionManager()->getFocusSignifier()->getFillColor();
    s_signifierColor[0] = (float)ca.r / 255;
    s_signifierColor[1] = (float)ca.g / 255;
    s_signifierColor[2] = (float)ca.b / 255;
    s_signifierColor[3] = (float)ca.a / 255;

    s_selectionIndicatorSize = SelectionManager::getSelectionManager()->getFocusSignifier()->getRadius()/5;
}

void PWW_Button::updateDearIMGUIParamWindow()
{

    ImGui::SetWindowSize(sf::Vector2f(200, 400));
    ImGui::Text("Obiekt typu:");
    ImGui::SameLine();
    ImGui::TextColored(sf::Color(100, 100, 100), "przycisk");

    ImGui::Text("Id obiektu: ");
    ImGui::SameLine();
    ImGui::TextColored(sf::Color(100, 100, 100), (this->getID()).c_str());
    

    if (ImGui::SliderFloat("Skala", &s_scale, 0.f, 2.f)) {
        this->setScale(s_scale);
       
        SelectionManager::getSelectionManager()->changeFocus(this,this);
    }
   
    ///
    ImGui::Separator();
    ///

    ImGui::Text("Pozycja i Wypelnienie: ");
    if (ImGui::InputInt2("X/Y", s_position)) {
        setPosition(s_position[0], s_position[1]);
        SelectionManager::getSelectionManager()->changeFocus(this,this);
    }
    
    ImGui::ColorEdit4("Kolor", s_fillColor);
    if (ImGui::IsItemEdited())
    {
        setColorFill((int)(s_fillColor[0] * 255), (int)(s_fillColor[1] * 255), (int)(s_fillColor[2] * 255), (int)(s_fillColor[3] * 255));
    }
    


    ///
    ImGui::Separator();
    ///
    


    ImGui::Text("Napis:");
   

    if (ImGui::InputText("Napis", s_buttonLabel, MAX_LABEL_LENGTH))
    {
        initText(std::string(s_buttonLabel));
    }
    ImGui::ColorEdit4("Tekst",s_textColor);
    if (ImGui::IsItemEdited())
    {
        setColorText((int)(s_textColor[0] * 255), (int)(s_textColor[1] * 255), (int)(s_textColor[2] * 255), (int)(s_textColor[3] * 255));
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
        selMan->changeFocus(this,this);

    }

    if (ImGui::SliderFloat("Alfa", &s_signifierColor[3], 0.f, 1.f)) {
        SelectionManager::getSelectionManager()->getFocusSignifier()->setFillColor(sf::Color((int)(s_signifierColor[0] * 255), (int)(s_signifierColor[1] * 255), (int)(s_signifierColor[2] * 255), (int)(s_signifierColor[3] * 255)));
    }


}

void PWW_Button::deleteStaticPointers()
{
    delete s_buttonLabel;
}

