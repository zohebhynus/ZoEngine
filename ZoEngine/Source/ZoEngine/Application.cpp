#include "pch.h"

#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "ZoEngine/Log.h"
#include "glad/glad.h"

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

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
		}
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowClosesEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
		
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
			{
				break;
			}
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PopLayer(Layer* layer)
	{
		m_LayerStack.PopLayer(layer);
	}

	bool Application::OnWindowClose(WindowClosesEvent& event)
	{
		m_IsRunning = false;

		return true;
	}
}