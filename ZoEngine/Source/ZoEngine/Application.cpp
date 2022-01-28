#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "ZoEngine/Log.h"

namespace ZoEngine
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);

		if (e.IsInCategory(EventCategoryApplication))
		{
			ZO_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryKeyboard))
		{
			ZO_TRACE(e);
		}

		while (true)
		{

		}
	}
}