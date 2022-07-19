#pragma once
#include <iostream>
#include <vector>
#include "Clickable.h"
#include "Identifiable.h"
#include "Renderable.h"

class Object :	
	virtual public Clickable,
	virtual public Identifiable,
	virtual public Renderable
{
private:


public:
	
	Object(const std::function<void()>& func = [](){});
	virtual ~Object();	
};

