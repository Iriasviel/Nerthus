#pragma once

#include "Event.h"

#include <sstream>

namespace Nerthus
{
	class NERTHUS_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y)
		{

		}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	private:
		float m_MouseX, m_MouseY;
	};

	class NERTHUS_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset)
		{

		}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolledEvent);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	private:
		float m_XOffset, m_YOffset;
	};

	class NERTHUS_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
	protected:
		MouseButtonEvent(int button)
			: m_Button(button)
		{

		}

		int m_Button;
	};

	class NERTHUS_API MousePressedEvent : public MouseButtonEvent
	{
	public:
		MousePressedEvent(int button)
			: MouseButtonEvent(button)
		{

		}

		inline int GetMouseButton() const { return m_Button; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonEvent);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	private:
		int m_Button;
	};
}