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

Object* SelectionManager::getFocusedElement()
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
m_focusedElement(nullptr), m_objectIsFocused(false), m_focusSignifier(10), im_selectedElement (nullptr)
{
    m_focusSignifier.setFillColor(sf::Color(255, 0, 0));
}


//TODO: In future it has to support multiple signifiers
void SelectionManager::addChildSelectionSignifier(Object* focalElement)
{

    m_childPositions.push_back(sf::Vector2f(floor(focalElement->getGlobalBounds().left + focalElement->getGlobalBounds().width / 2 - getIndicatorSize()),
        floor(focalElement->getGlobalBounds().top + focalElement->getGlobalBounds().height / 2 - getIndicatorSize())));
}



void SelectionManager::renderFocusSignifiers(sf::RenderTarget* target)
{
    target->draw(m_focusSignifier);
    if (im_showChildSelection) {
        for (sf::Vector2f v : m_childPositions) {
            m_childFocusSignifier.setPosition(v);
            target->draw(m_childFocusSignifier);
        }
    }
}

void SelectionManager::changeFocus(Object* newFocus, ParamWindowWrapper* newIm_selectedElement)
{
    loseFocus();
    m_focusedElement = newFocus;
    im_selectedElement = newIm_selectedElement;

    m_objectIsFocused = true;
    m_focusSignifier.setPosition(sf::Vector2f(floor(newFocus->getGlobalBounds().left + newFocus->getGlobalBounds().width / 2 - getIndicatorSize()),
        floor(newFocus->getGlobalBounds().top + newFocus->getGlobalBounds().height / 2 - getIndicatorSize())));

    //addChildSelectionSignifier(m_focusedElement);
}

void SelectionManager::loseFocus()
{
    m_focusedElement = nullptr;
    im_selectedElement = nullptr;
    m_objectIsFocused = false;
    im_showChildSelection = false;
}

