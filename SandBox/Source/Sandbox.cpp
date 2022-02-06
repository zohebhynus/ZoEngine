#include <ZoEngine.h>

class TestLayer : public ZoEngine::Layer
{
public:
	TestLayer()
	{

	}

	void OnUpdate() override
	{
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
		
		PushOverlay(new ZoEngine::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

ZoEngine::Application* ZoEngine::CreateApplication()
{
	return new Sandbox();
}