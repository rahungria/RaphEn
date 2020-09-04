#pragma once

#include "RaphEn/Core.h"
#include "RaphEn/Events/EventCore.h"

namespace raphen::events 
{
	//Base class for every system event
	class RE_API Event
	{
		//friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual const char* GetName() const = 0;
		virtual const char* ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_handled = false;
	};
}