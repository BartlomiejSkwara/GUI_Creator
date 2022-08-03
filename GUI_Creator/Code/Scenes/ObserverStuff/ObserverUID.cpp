#include "ObserverUID.h"

///TODO make staic vars in basic observer class for mouseinfo and selection manager singletons to reduce callin g those functions
//TODO Sort this out and divide in different functions
void ObserverUID::onNotify(EventType event, Object* caller)
{
	switch (event)
	{
	case EventType::EVENT_CLICKED_OBJECT:
		caller->runEvent();
		break;

	case EventType::EVENT_CLICKED_BACKGROUND:
		if (SelectionManager::getSelectionManager()->isObjectFocused())
		{
			if (!(ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow)))
			{
				SelectionManager::getSelectionManager()->loseFocus();
			}
		}
		break;

	case EventType::EVENT_MOVED_OBJECT:
		{
			sf::Vector2f moveDistance = MouseInfo::getMouseInf()->mousePositionView - MouseInfo::getMouseInf()->mousePositionViewLastKnown;
			SelectionManager::getSelectionManager()->getFocusedElement()->move(moveDistance.x, moveDistance.y);
			SelectionManager::getSelectionManager()->getFocusSignifier()->move(moveDistance.x, moveDistance.y);
		}
		break;


	default:
		break;
	}
}
