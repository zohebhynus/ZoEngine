#pragma once

#include "ZoEngine/Events/Event.h"

namespace ZoEngine
{
	class ZOENGINE_API Layer
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& event) {};
	};
}