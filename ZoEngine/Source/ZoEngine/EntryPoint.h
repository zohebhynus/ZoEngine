#pragma once

#ifdef ZO_PLATFORM_WINDOWS

extern ZoEngine::Application* ZoEngine::CreateApplication();

void main(int argc, char** argv)
{
	auto app = ZoEngine::CreateApplication();
	app->Run();
	delete app;

}

#endif // ZO_PLATFORM_WINDOWS
