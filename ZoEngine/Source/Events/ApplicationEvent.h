#pragma once

#include "Event.h"

#include <sstream>

namespace ZoEngine
{

	//WindowResizeEvent class
	class ZOENGINE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height)
		{
		}

		inline unsigned int  GetWidth() const { return m_Width; }
		inline unsigned int  GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window Resize Event : " << m_Width << " x " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Height;
		unsigned int m_Width;
	};

	//WindowClosesEvent class
	class ZOENGINE_API WindowClosesEvent : public Event
	{
	public:
		WindowClosesEvent()
		{
		}

		EVENT_CLASS_TYPE(WindowCloses)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	//AppTickEvent
	class ZOENGINE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent()
		{
		}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	//AppUpdateEvent
	class ZOENGINE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent()
		{
		}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

	//AppRenderEvent
	class ZOENGINE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent()
		{
		}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};
}