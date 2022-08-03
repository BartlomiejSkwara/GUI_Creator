#include "PWWManager.h"

PWWManager::PWWManager() {
    m_selectManager = SelectionManager::getSelectionManager();
    m_resourceManager = ResourceManager::getResourceManager();
}

void PWWManager::updatePWW()
{
    ImGui::Begin("Parametry Obiektu: ");
    ImGui::SetWindowSize(sf::Vector2f(220, 400));
    if (m_selectManager->getFocusedElement() == nullptr) {
        ImGui::SetWindowSize(sf::Vector2f(200, 400));
        ImGui::Text("Obiekt typu:");
        ImGui::SameLine();
        ImGui::TextColored(sf::Color(100, 100, 100), "brak!");

        ImGui::Text("Id obiektu: ");
        ImGui::SameLine();
        ImGui::TextColored(sf::Color(100, 100, 100), "brak!");
    }
    else
    {
        object->updateDearIMGUIParamWindow();
    }
        
    ImGui::End();
    
}




void PWWManager::initDIV(DivObject* div)
{
    delete object;
    object = new PWW_Div(div);

    
    m_selectManager->setShowChildSelection(true);
    m_selectManager->clearChildren();
    for (Object* child : *(div->getObjectVector())) {
        m_selectManager->addChildSelectionSignifier(child);
    }




  
}

void PWWManager::initImage(ImageObject* image)
{
    delete object;
    object = new PWW_Image(image);
    m_selectManager->setShowChildSelection(false);
}

void PWWManager::initText(TextObject* text)
{

    delete object;
    object = new PWW_Text(text);
    m_selectManager->setShowChildSelection(false);
}

void PWWManager::initTextButton(TextObject* button)
{
    delete object;
    object = new PWW_TextButton(button);
    m_selectManager->setShowChildSelection(false);
}

