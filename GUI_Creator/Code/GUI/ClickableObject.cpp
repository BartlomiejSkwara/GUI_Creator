#include "ClickableObject.h"

ClickableObject::ClickableObject()
	:m_Event([](){})
{
}

ClickableObject::ClickableObject(const std::function<void()>& func)
	:m_Event(func)
{
}

ClickableObject::~ClickableObject()
{
}

void ClickableObject::setEvent(const std::function<void()>& func)
{
	m_Event = func;
}

void ClickableObject::runEvent()
{
	m_Event();
}


