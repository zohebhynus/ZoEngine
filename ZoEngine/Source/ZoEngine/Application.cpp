#include "pch.h"

#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "ZoEngine/Log.h"
#include "GLFW/glfw3.h"

namespace ZoEngine
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		//TODO : Make into Macro
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{

		while (m_IsRunning)
		{
			glClearColor(0.8, 0.3, 0.2, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Window->OnUpdate();
		}
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowClosesEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

		ZO_CORE_TRACE("{0}", e);
	}

	bool Application::OnWindowClose(WindowClosesEvent& event)
	{
		m_IsRunning = false;

		return true;
	}
}