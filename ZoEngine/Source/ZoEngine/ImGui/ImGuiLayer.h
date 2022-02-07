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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:

		float m_Time = 0.0f;
	};


}