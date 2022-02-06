#include "pch.h"

#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "ZoEngine/Log.h"
#include "glad/glad.h"
#include "ZoEngine/Input.h"
#include "GLFW/glfw3.h"

namespace ZoEngine
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		ZO_CORE_ASSERT(!s_Instance, "Application already exists.");
		s_Instance = this;

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

			//iNPUT CLass test
			//auto [x, y] = Input::GetMousePosition();
			//auto xpos = Input::GetMouseX();
			//auto ypos = Input::GetMouseY();
			//ZO_CORE_TRACE("Mouse Positions : ({0},{1})", x, y);
			//ZO_CORE_TRACE("xPos : {0}", xpos);
			//ZO_CORE_TRACE("yPos : {0}", ypos);

			//if (Input::IsKeyPressed(GLFW_KEY_A))
			//{
				//ZO_CORE_TRACE("A Key was pressed.");
			//}

			//if (Input::IsMouseButtonPressed(GLFW_MOUSE_BUTTON_1))
			//{
			//	ZO_CORE_TRACE("Left Click was Pressed.");
			//}


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
		layer->OnAttach();
	}

	void Application::PopLayer(Layer* layer)
	{
		m_LayerStack.PopLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::PopOverlay(Layer* layer)
	{
		m_LayerStack.PopOverlay(layer);
	}

	bool Application::OnWindowClose(WindowClosesEvent& event)
	{
		m_IsRunning = false;

		return true;
	}
}