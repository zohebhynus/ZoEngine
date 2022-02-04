#pragma once
#include "Layer.h"

namespace ZoEngine
{
	class ZOENGINE_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void PopLayer(Layer* layer);
		void PopOverlay(Layer* layer);

		std::vector<Layer*>::iterator begin() { return m_Layer.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layer.end(); }

	private:
		std::vector<Layer*> m_Layer;
		std::vector<Layer*>::iterator m_LayerInsert;

	};

}