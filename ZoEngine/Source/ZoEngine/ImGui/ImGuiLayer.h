#pragma once
#include "ZoEngine/Layer.h"
#include "ZoEngine/Events/Event.h"
#include "ZoEngine/Events/KeyEvent.h"
#include "ZoEngine/Events/MouseEvent.h"
#include "ZoEngine//Events/ApplicationEvent.h"

namespace ZoEngine
{
	class ZOENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();

		void OnUpdate();
		void OnEvent(Event& event);

	private:

		bool OnKeyPressedEvent(KeyPressedEvent& event);
		bool OnKeyReleasedEvent(KeyReleasedEvent& event);
		bool OnKeyTypedEvent(KeyTypedEvent& event);

		bool OnMouseMoveEvent(MouseMovedEvent& event);
		bool OnMouseScrolledEvent(MouseScrolledEvent& event);
		bool OnMouseButtonPressedEvent(MouseButtonPresseddEvent& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);

		bool OnWindowResizeEvent(WindowResizeEvent& event);

		float m_Time = 0.0f;
	};


}