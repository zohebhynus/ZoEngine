#pragma once
#include "ZoEngine/Window.h"
#include "ZoEngine/Graphics/GraphicsContext.h"

#include "GLFW/glfw3.h"

namespace ZoEngine
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return m_WindowData.Width; }
		unsigned int GetHeight() const override { return m_WindowData.Height; }
		float GetHighDPIScalingFactor() const override { return m_HighDPIScaleFactor; }

		inline void SetEventCallback(const EventCallbackFunction& callback) override { m_WindowData.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSyncActive() const override;

		inline virtual void* GetNativeWindow() const { return m_Window; }

	protected:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;
		float m_HighDPIScaleFactor = 1.0;

		struct WindowData
		{
			std::string Title;

			unsigned int Width;
			unsigned int Height;

			bool VSync;

			EventCallbackFunction EventCallback;
		};

		WindowData m_WindowData;
	};
}

