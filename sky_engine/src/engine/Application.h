#pragma once

#include "Core.h"

#include "Window.h"
#include "engine/LayerStack.h"
#include "Events/Event.h"
#include "events/ApplicationEvent.h"

namespace Sky 
{
	class SKY_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();

			void OnEvent(Event& event);

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* layer);
		private:
			bool OnWindowClose(WindowCloseEvent& event);

			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
			LayerStack m_LayerStack;
	};

	// Implement this function in your Sky application
	Application* CreateApplication();
}

