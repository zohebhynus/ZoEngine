#pragma once
#include "Core.h"

#include "Events/Event.h"

namespace ZoEngine{

	class ZOENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		
	};
	// defined in client
	Application* CreateApplication();
}

