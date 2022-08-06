#include "MouseInput.h"
#include <SFML/Window/Mouse.hpp>

MouseInput* MouseInput::mouseInput = nullptr;


void MouseInput::updateMouseStatus()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        
        if (mouseHeld == false)
        {
            //std::cout<<"Sone pressed the mouse\n";
            
            notify(EventType::MouseLPMClickObject);
            notify(EventType::MouseLPMClickDiv);
            mouseClicked = true;
            mouseHeld = true;        
        }
        else
        {
            //std::cout << "Mouse is being held\n";
            notify(EventType::MouseLPMDrag);
            mouseClicked = false;
        }

    }
    else
    {
        //std::cout << "Sone released the mouse\n";
        notify(EventType::MouseLPMRelease);
        mouseHeld = false;
    }
}
void MouseInput::updateMousePosition()
{
    mousePositionWindow = sf::Mouse::getPosition(*context);
    mousePositionViewLastKnown = mousePositionView;
    mousePositionView = context->mapPixelToCoords(mousePositionWindow);
}
MouseInput::MouseInput(): lastClickedObject(nullptr)
{
    mouseHeld = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    


    initBasicEvents();
    
}
void MouseInput::initBasicEvents()
{

    m_eventsMap[EventType::MouseLPMClickObject] = new std::vector<Event>;
    m_eventsMap[EventType::MouseLPMClickDiv] = new std::vector<Event>;
    m_eventsMap[EventType::MouseLPMDrag] = new std::vector<Event>;

    addEvent(EventType::MouseLPMClickObject, []() {}, EventScope::ScopeObject);
    addEvent(EventType::MouseLPMClickDiv, []() {}, EventScope::ScopeObject);
}
void MouseInput::updateMouse()
{
    updateMouseStatus();
    updateMousePosition();
}



void MouseInput::addEvent(EventType type, const std::function<void()>& func, EventScope scope)
{
    m_eventsMap[type]->emplace_back(type,func,scope);
}

void MouseInput::addEvent(Event ev)
{
    m_eventsMap[ev.getType()]->emplace_back(ev);
}

void MouseInput::removeEvent(Event ev)
{

    if (m_eventsMap.find(ev.getType()) != m_eventsMap.end()) {
        auto vec = m_eventsMap[ev.getType()];
        for (auto i = vec->begin(); i != vec->end(); i++)
        {        
            if (*i == ev) {
                vec->erase(i);
                break;
            }
        }
    }
    
}

void MouseInput::clearEventMap()
{
    for (auto i:m_eventsMap)
    {
        m_eventsMap.clear();
    }
}

void MouseInput::setLastClickedObject(Object* obj)
{
    lastClickedObject = obj;
}


Object* MouseInput::getLastClickedObject() {
    return lastClickedObject;
}


void MouseInput::setContext(sf::RenderWindow* contextWindow)
{
    this->context = contextWindow;
}
MouseInput* MouseInput::getMouseInf()
{
	if (!mouseInput)
	{
		mouseInput = new MouseInput();
	}
	return mouseInput;
}

void MouseInput::notify(EventType etype)
{
    if (m_eventsMap.find(etype)!=m_eventsMap.end()) {
        for (auto ev : *m_eventsMap[etype]) {
            m_observer->onNotify(ev);
        }
    }
}

void MouseInput::addObserver(Observer* obs)
{
    m_observer = obs;
}
