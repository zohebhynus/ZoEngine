#pragma once
#include "pch.h"

#include "Core.h"
#include "Events/Event.h"

namespace ZoEngine
{
	//window properties struct
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "ZoEngine", unsigned int width = 2560, unsigned int height = 1440) :
			Title(title), Width(width), Height(height)
		{

		}

	};

	//Base Window class 
	class ZOENGINE_API Window
	{
	public:
		using EventCallbackFunction = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual float GetHighDPIScalingFactor() const = 0;

		virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSyncActive() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}