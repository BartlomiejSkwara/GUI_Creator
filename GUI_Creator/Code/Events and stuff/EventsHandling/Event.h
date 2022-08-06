#pragma once
#include <functional>
#include "HandlerFlags.h"

class Event
{
private:
	std::function<void()> m_Event;
	EventScope m_scope;
	EventType  m_type;
public:



	Event(EventType type, const std::function<void()>& func = []() {}, EventScope scope = EventScope::ScopeObject);
	Event();
	//Run Lambda
	void runEvent();

	void setEvent(const std::function<void()>& func);

	//Getters
	EventScope getScope();
	EventType  getType();

	friend bool operator== (const Event& e1, const Event& e2);

};


