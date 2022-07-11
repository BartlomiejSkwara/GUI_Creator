#include "SelectionManager.h"

SelectionManager* SelectionManager::instance = nullptr;

SelectionManager* SelectionManager::getSelectionManager()
{
    
    if (!instance) {
        instance = new SelectionManager();
    }
  
    //= new SelectionManager();
    return instance;
}

float SelectionManager::getIndicatorSize()
{
    return m_focusSignifier.getRadius();
}

bool SelectionManager::isObjectFocused()
{
    return m_objectIsFocused;
}

RenderableObject* SelectionManager::getFocusedElement()
{
    return m_focusedElement;
}

ParamWindowWrapper* SelectionManager::getSelectedElement()
{
    return im_selectedElement;
}



sf::CircleShape* SelectionManager::getFocusSignifier()
{
    return &m_focusSignifier;
}

bool SelectionManager::isShowingMainSelection()
{
    return im_showMainSelection;
}

bool SelectionManager::isShowingChildSelection()
{
    return im_showChildSelection;
}

void SelectionManager::setIndicatorSize(float size)
{
    std::cout << "TODO: set indic size\n";
}

void SelectionManager::setShowMainSelection(bool val)
{
    im_showMainSelection = val;
}

void SelectionManager::setShowChildSelection(bool val)
{
    im_showChildSelection = val;
}

SelectionManager::SelectionManager():
m_focusedElement(nullptr), m_objectIsFocused(false), m_focusSignifier(10)
{
    m_focusSignifier.setFillColor(sf::Color(255, 0, 0));
}


//TODO: In future it has to support multiple signifiers
void SelectionManager::addSelectionSignifier(RenderableObject* focalElement)
{
    m_objectIsFocused = true;
    m_focusSignifier.setPosition(sf::Vector2f(floor(focalElement->getGlobalBounds().left + focalElement->getGlobalBounds().width / 2 - getIndicatorSize()),
        floor(focalElement->getGlobalBounds().top + focalElement->getGlobalBounds().height / 2 - getIndicatorSize())));
}

void SelectionManager::removeSelectionSignifier()
{
    m_objectIsFocused = false;
}

void SelectionManager::renderFocusSignifier(sf::RenderTarget* target)
{
    target->draw(m_focusSignifier);
}

void SelectionManager::changeFocus(RenderableObject* newFocus, ParamWindowWrapper* newIm_selectedElement)
{
    m_focusedElement = newFocus;
    im_selectedElement = newIm_selectedElement;
    addSelectionSignifier(m_focusedElement);
}

void SelectionManager::loseFocus()
{
    m_focusedElement = nullptr;
    im_selectedElement = nullptr;
    removeSelectionSignifier();
}
