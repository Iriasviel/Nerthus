#pragma once

#include "Core.h"
#include "Window.h"
#include "Nerthus/LayerStack.h"
#include "Nerthus/Events/Event.h"
#include "Nerthus/Events/ApplicationEvent.h"

#include "Window.h"

namespace Nerthus
{
	class NERTHUS_API Application
	{ 
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in client
	Application* CreateApplication();
}