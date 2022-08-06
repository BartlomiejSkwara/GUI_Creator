#pragma once
#include "../EventsHandling/Event.h"
class Observer
{
private:
	
public:
	virtual void onNotify(Event event) = 0;
};

