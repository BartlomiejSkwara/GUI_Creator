#include "EventHandler.h"

EventHandler::EventHandler()
{

}

EventHandler::~EventHandler()
{
}

void EventHandler::setEvent(Event ev)
{
	m_events[ev.getType()] = ev;
}

void EventHandler::runEvent(Event& event)
{
	if ((event.getScope() & EventScope::ScopeObject) == EventScope::ScopeObject)
	{
		this->m_events[event.getType()].runEvent();
	}
	if ((event.getScope() & EventScope::ScopeGlobal) == EventScope::ScopeGlobal)
	{
		event.runEvent();
	}
}






