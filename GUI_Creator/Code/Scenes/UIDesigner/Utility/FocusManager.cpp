#include "FocusManager.h"



float FocusManager::getIndicatorSize()
{
    return m_focusSignifier.getRadius();
}




sf::CircleShape* FocusManager::getFocusSignifier()
{
    return &m_focusSignifier;
}

bool FocusManager::isShowingMainSelection()
{
    return im_showMainSelection;
}

bool FocusManager::isShowingChildSelection()
{
    return im_showChildSelection;
}

void FocusManager::setIndicatorSize(float size)
{
    std::cout << "TODO: set indic size\n";
}

void FocusManager::setShowMainSelection(bool val)
{
    im_showMainSelection = val;
}

void FocusManager::setShowChildSelection(bool val)
{
    im_showChildSelection = val;
}

void FocusManager::clearChildren()
{
    m_childPositions.clear();
}

FocusManager::FocusManager(): im_showMainSelection(false), m_focusSignifier(10)
{
    m_focusSignifier.setFillColor(sf::Color(255, 0, 0,255));
}


//TODO: In future it has to support multiple signifiers
void FocusManager::addChildSelectionSignifier(Object* focalElement)
{

    m_childPositions.push_back(sf::Vector2f(floor(focalElement->getGlobalBounds().left + focalElement->getGlobalBounds().width / 2 - getIndicatorSize()),
        floor(focalElement->getGlobalBounds().top + focalElement->getGlobalBounds().height / 2 - getIndicatorSize())));
}



void FocusManager::renderFocusSignifiers(sf::RenderTarget* target)
{
    if (im_showMainSelection) {
        target->draw(m_focusSignifier);
        if (im_showChildSelection) {
            for (sf::Vector2f v : m_childPositions) {
                m_childFocusSignifier.setPosition(v);
                target->draw(m_childFocusSignifier);
            }
        }
    }   
}

void FocusManager::changeFocus(Object* newFocus)
{

   
    im_showChildSelection = false;
    if (newFocus) {

        im_showMainSelection = true;
        m_focusSignifier.setPosition(sf::Vector2f(floor(newFocus->getGlobalBounds().left + newFocus->getGlobalBounds().width / 2 - getIndicatorSize()),
            floor(newFocus->getGlobalBounds().top + newFocus->getGlobalBounds().height / 2 - getIndicatorSize())));
        
    }
    else
    {
        
        im_showMainSelection = false;
    }
   


}


