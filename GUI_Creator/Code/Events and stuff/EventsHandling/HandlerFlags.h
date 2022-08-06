#pragma once

enum class EventType {
	NONE				= 0,
	MouseLPMClickImage  = 1,
	MouseLPMClickText   = 2,
	MouseLPMClickDiv    = 3,
	MouseLPMClickObject = 4,
	MouseLPMDrag	    = 5,
	MouseLPMRelease		= 6
};


//Used as bitmask
enum class EventScope {
	
	ScopeObject = 1,
	ScopeGlobal = 2,
	NONE		= 512
};

enum class HandlingStatus {
	EVENT_HANDLING_DONE = 1,
	EVENT_HANDLING_DIV = 2,
	EVENT_HANDLING_FAILED = 4
};


constexpr inline EventScope operator| (EventScope a, EventScope b) { return static_cast<EventScope>(static_cast<std::underlying_type<EventScope>::type>(a) | static_cast<std::underlying_type<EventScope>::type>(b)); }
constexpr inline EventScope operator& (EventScope a, EventScope b) { return static_cast<EventScope>(static_cast<std::underlying_type<EventScope>::type>(a) & static_cast<std::underlying_type<EventScope>::type>(b)); }



