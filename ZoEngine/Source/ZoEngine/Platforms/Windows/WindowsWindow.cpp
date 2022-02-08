#include "pch.h"
#include "WindowsWindow.h"

#include "ZoEngine/Events/ApplicationEvent.h"
#include "ZoEngine/Events/KeyEvent.h"
#include "ZoEngine/Events/MouseEvent.h"

#include "ZoEngine/Platforms/OpenGL/OpenGLContext.h"


namespace ZoEngine
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int errorCode, const char* description)
	{
		ZO_CORE_ERROR("GLFW Error ({0}): {1} ", errorCode, description);
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_WindowData.Title = props.Title;
		m_WindowData.Width = props.Width;
		m_WindowData.Height = props.Height;

		ZO_CORE_INFO("Initializing Window with Title : {0}  and Resolution : {1} x {2}", m_WindowData.Title, m_WindowData.Width, m_WindowData.Height);

		if (!s_GLFWInitialized)
		{
			int result = glfwInit();
			ZO_CORE_ASSERT(result, "GLFW Failed to Initialize.");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(m_WindowData.Width, m_WindowData.Height, m_WindowData.Title.c_str(), nullptr, nullptr);
		m_Context = new OpenGLContext(m_Window);
		m_Context->Init();

		//Get Monitor DPI scale value
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		float xScale;
		float yScale;
		glfwGetMonitorContentScale(monitor, &xScale, &yScale);
		if (xScale > 0 || yScale > 0)
		{
			m_HighDPIScaleFactor = xScale;
		}

		glfwSetWindowUserPointer(m_Window, &m_WindowData);
		SetVSync(true);

		//GLFW Callback function setup

		//Window Size
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data =  *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		//Window Close
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowClosesEvent event;
				data.EventCallback(event);
			});

		//Key
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}

				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}

				case GLFW_RELEASE:
				{
					//TO DO : Extract re[eat count from glfw. Repeat set to 1 for now
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				}
			});

		//Key Typed
		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				KeyTypedEvent event(keycode);
				data.EventCallback(event);
			});

		//Mouse Button
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPresseddEvent event(button);
						data.EventCallback(event);
						break;
					}

					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent event(button);
						data.EventCallback(event);
						break;
					}
				}
			});

		//Mouse scroll
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		//Mouse Move
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);

			});
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		m_WindowData.VSync = enabled;
	}

	bool WindowsWindow::IsVSyncActive() const
	{
		return m_WindowData.VSync;
	}
}