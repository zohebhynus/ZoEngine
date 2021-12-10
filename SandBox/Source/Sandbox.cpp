#include <ZoEngine.h>

class Sandbox : public ZoEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

ZoEngine::Application* ZoEngine::CreateApplication()
{
	return new Sandbox();
}