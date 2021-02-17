#include "ntpch.h"
#include <Nerthus.h>

class Sandbox : public Nerthus::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Nerthus::Application* Nerthus::CreateApplication()
{
	return new Sandbox();
}