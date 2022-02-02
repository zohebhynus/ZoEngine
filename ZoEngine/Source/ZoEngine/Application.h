#pragma once
#include "Core.h"

#include "Events/Event.h"
#include"Events/ApplicationEvent.h"
#include "Window.h"

namespace ZoEngine{

	class ZOENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowClosesEvent& event);

		std::unique_ptr<Window> m_Window;
		bool m_IsRunning = true;

		
	};
	// defined in client
	Application* CreateApplication();
}

