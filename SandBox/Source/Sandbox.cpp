#include <ZoEngine.h>

#include "ImGui/imgui.h"

class TestLayer : public ZoEngine::Layer
{
public:
	TestLayer()
	{

	}

	void OnUpdate() override
	{
	}

	void OnImGuiRender()
	{
		ImGui::Begin("Test");
		ImGui::Text("Test Window");
		ImGui::End();
	}

	void OnEvent(ZoEngine::Event& event) override
	{
		if (event.GetEventType() == ZoEngine::EventType::KeyPressed)
		{
			ZoEngine::KeyPressedEvent& e = (ZoEngine::KeyPressedEvent&) event;
			ZO_TRACE("Key Pressed : {0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public ZoEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new TestLayer());
	}

	~Sandbox()
	{

	}

};

ZoEngine::Application* ZoEngine::CreateApplication()
{
	return new Sandbox();
}