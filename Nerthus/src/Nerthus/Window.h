#pragma once

#include "ntpch.h"

#include "Nerthus/Core.h"
#include "Nerthus/Events/Event.h"

namespace Nerthus
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Nerthus Engine", unsigned int width, unsigned int height)
			: Title(title), Width(width), Height(height)
		{

		}
	};

	// Interface reperesenting a desktop system based Window
	class NERTHUS_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};
}