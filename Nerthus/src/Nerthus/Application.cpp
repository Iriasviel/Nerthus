#include "ntpch.h"
#include "Application.h"

#include "Nerthus/Events/ApplicationEvent.h"
#include "Nerthus/Log.h"

namespace Nerthus
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		NT_TRACE(e);

		while (true);
	}
}