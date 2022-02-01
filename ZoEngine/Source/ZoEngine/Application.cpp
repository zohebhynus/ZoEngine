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
}