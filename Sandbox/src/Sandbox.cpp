#include "ntpch.h"
#include <Nerthus.h>

class ExampleLayer : public Nerthus::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		NT_INFO("ExampleLayer::Update");
	}

	void OnEvent(Nerthus::Event& event) override
	{
		NT_TRACE("{0}", event);
	}
};

class Sandbox : public Nerthus::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Nerthus::Application* Nerthus::CreateApplication()
{
	return new Sandbox();
}