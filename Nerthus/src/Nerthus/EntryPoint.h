#pragma once

#ifdef NT_PLATFORM_WINDOWS

extern Nerthus::Application* Nerthus::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Nerthus::CreateApplication();
	app->Run();
	delete app;
}

#endif