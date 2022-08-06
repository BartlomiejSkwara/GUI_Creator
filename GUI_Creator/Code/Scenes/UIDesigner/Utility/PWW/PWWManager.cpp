#include "PWWManager.h"

PWWManager::PWWManager(FocusManager* focusManager): m_focusManager(focusManager) {

    m_resourceManager = ResourceManager::getResourceManager();
}

void PWWManager::updatePWW()
{
    ImGui::Begin("Parametry Obiektu: ");
    ImGui::SetWindowSize(sf::Vector2f(220, 400));
    if (m_focusManager->isShowingMainSelection() == false) {
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

    
    m_focusManager->setShowChildSelection(true);
    m_focusManager->clearChildren();
    for (Object* child : *(div->getObjectVector())) {
        m_focusManager->addChildSelectionSignifier(child);
    }
}

void PWWManager::initImage(ImageObject* image)
{
    delete object;
    object = new PWW_Image(image);
    m_focusManager->setShowChildSelection(false);
}

void PWWManager::initText(TextObject* text)
{

    delete object;
    object = new PWW_Text(text);
    m_focusManager->setShowChildSelection(false);
}

void PWWManager::initTextButton(TextObject* button)
{
    delete object;
    object = new PWW_TextButton(button);
    m_focusManager->setShowChildSelection(false);
}

