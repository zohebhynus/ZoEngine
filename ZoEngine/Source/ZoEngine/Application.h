#pragma once
#include "Core.h"

#include "Events/Event.h"
#include"Events/ApplicationEvent.h"
#include "Window.h"

#include "ZoEngine/Layer.h"
#include "ZoEngine/LayerStack.h"

namespace ZoEngine{

	class ZOENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		void PushOverlay(Layer* layer);
		void PopOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowClosesEvent& event);

		std::unique_ptr<Window> m_Window;
		
		LayerStack m_LayerStack;

		bool m_IsRunning = true;

		static Application* s_Instance;

		
	};
	// defined in client
	Application* CreateApplication();
}

