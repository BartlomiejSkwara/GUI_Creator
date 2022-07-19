#include "Object.h"

Object::Object(const std::function<void()>& func) :Clickable(func), Identifiable(), Bordered()
{
}

Object::~Object()
{
}
