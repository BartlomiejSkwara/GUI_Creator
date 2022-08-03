#include "Object.h"

Object::Object(const std::function<void()>& func) :Identifiable(), Bordered()
{
	setEvent(func);
}

Object::~Object()
{
}

