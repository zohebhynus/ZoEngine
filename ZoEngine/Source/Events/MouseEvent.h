#pragma once

#include "Event.h"

#include <sstream>

namespace ZoEngine
{
	//MouseMovedEvent class
	class ZOENGINE_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y)
		{
		}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Move Event : " << m_MouseX << ", " << m_MouseY;
			ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

	private:
		float m_MouseX;
		float m_MouseY;
	};

	//MouseScrolledEvent class
	class ZOENGINE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset)
		{
		}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Scrolled Event : " << m_XOffset << ", " << m_YOffset;
			ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

	private:
		float m_XOffset;
		float m_YOffset;
	};

	//MouseButtonEvent class
	class ZOENGINE_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

	protected:
		MouseButtonEvent(int button) : m_Button(button)
		{
		}

		int m_Button;
	};

	//MouseButtonPressedEvent class
	class ZOENGINE_API MouseButtonPresseddEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPresseddEvent(int button) : MouseButtonEvent(button)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Buttom Pressed : " << m_Button;
			ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	//MouseButtonReleasedEvent class
	class ZOENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Buttom Released : " << m_Button;
			ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}