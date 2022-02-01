#pragma once

#ifdef ZO_PLATFORM_WINDOWS

extern ZoEngine::Application* ZoEngine::CreateApplication();

void main(int argc, char** argv)
{
	ZoEngine::Log::Init();
	ZO_CORE_WARN("Log Initialized");

	auto app = ZoEngine::CreateApplication();
	app->Run();
	delete app;

}

#endif // ZO_PLATFORM_WINDOWS
