#pragma once
typedef short int EventType;
constexpr EventType EVENT_CLICK = 0;
class ObserverScene
{
private:
	
public:
	virtual void onNotify(EventType event) = 0;
};

