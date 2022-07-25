#include "PWWManager.h"

PWWManager::PWWManager()
{
    selectManager = SelectionManager::getSelectionManager();
}

void PWWManager::updatePWW()
{
    ImGui::Begin("Parametry Obiektu: ");
    ImGui::SetWindowSize(sf::Vector2f(200, 400));
    if (selectManager->getFocusedElement() == nullptr) {
        ImGui::Text("Nie zaznaczono obiektu !!! ");
    }
    else
    {
        object->updateDearIMGUIParamWindow();
    }
        
    ImGui::End();
    
}




void PWWManager::initDIV(DivObject* div)
{
    object = new PWW_Div(div);

    
    selectManager->setShowChildSelection(true);
    selectManager->clearChildren();
    for (Object* child : *(div->getObjectVector())) {
        selectManager->addChildSelectionSignifier(child);
    }



    initObject(div);

  
}

void PWWManager::initText(TextObject* text)
{
    object = new PWW_Text(text);
    selectManager->setShowChildSelection(false);
    initObject(text);
}

void PWWManager::initTextButton(TextObject* button)
{
   object = new PWW_TextButton(button);
   selectManager->setShowChildSelection(false);
   initObject(button);
}

void PWWManager::initObject(Object* obj)
{
    object->m_size[0] = obj->getGlobalBounds().width;
    object->m_size[1] = obj->getGlobalBounds().height;

    object->m_position[0] = obj->getGlobalBounds().left;
    object->m_position[1] = obj->getGlobalBounds().top;

    object->m_outline_size = obj->getBorderThickness();

    object->m_outlineColor[0] = (float)obj->getColorBorder()->r / 255;
    object->m_outlineColor[1] = (float)obj->getColorBorder()->g / 255;
    object->m_outlineColor[2] = (float)obj->getColorBorder()->b / 255;
    object->m_outlineColor[3] = (float)obj->getColorBorder()->a / 255;

    object->m_fillColor[0] = (float)obj->getColorFill()->r / 255;
    object->m_fillColor[1] = (float)obj->getColorFill()->g / 255;
    object->m_fillColor[2] = (float)obj->getColorFill()->b / 255;
    object->m_fillColor[3] = (float)obj->getColorFill()->a / 255;

    sf::Color ca = selectManager->getFocusSignifier()->getFillColor();
    object->m_signifierColor[0] = (float)ca.r / 255;
    object->m_signifierColor[1] = (float)ca.g / 255;
    object->m_signifierColor[2] = (float)ca.b / 255;
    object->m_signifierColor[3] = (float)ca.a / 255;

    object->m_selectionIndicatorSize = selectManager->getFocusSignifier()->getRadius() / 5;

}