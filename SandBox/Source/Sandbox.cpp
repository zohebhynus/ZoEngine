#include <ZoEngine.h>

class TestLayer : public ZoEngine::Layer
{
public:
	TestLayer()
	{

	}

	void OnUpdate() override
	{
		//ZO_INFO("TestLayer::OnUpdate");
	}

	void OnEvent(ZoEngine::Event& event) override
	{
		ZO_TRACE(event);
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