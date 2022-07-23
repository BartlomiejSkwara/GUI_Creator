#pragma once
///**/typedef short int EventType;
//constexpr EventType EVENT_CLICKED_OBJECT = 0;
//constexpr EventType EVENT_LPM_HELD = 1;
#include "../GUI_Creator/Code/GUI/Parents/Clickable.h"
#include "../DesignerStuff/SelectionManager.h"
enum class EventType
{
	EVENT_CLICKED_OBJECT,
	EVENT_CLICKED_BACKGROUND,
	EVENT_MOVED_OBJECT

};
class ObserverScene
{
private:
	
public:
	virtual void onNotify(EventType event, Object* caller) = 0;
};

