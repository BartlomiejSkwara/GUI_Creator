 #include "Event.h"

Event::Event(EventType type, const std::function<void()>& func, EventScope scope ): m_type(type), m_Event(func), m_scope(scope)
{
}

Event::Event() : m_type(EventType::NONE), m_Event([](){}), m_scope(EventScope::NONE)
{
}

void Event::runEvent()
{
	m_Event();
}

void Event::setEvent(const std::function<void()>& func)
{
	m_Event = func;
}

EventScope Event::getScope()
{
	return m_scope;
}

EventType Event::getType()
{
	return m_type;
}

bool operator==(const Event& e1, const Event& e2)
{
	
	if (&e1.m_Event == &e2.m_Event && e1.m_scope == e2.m_scope && e1.m_type == e2.m_type)
	{
		return true;
	}
	return false;
	
}
