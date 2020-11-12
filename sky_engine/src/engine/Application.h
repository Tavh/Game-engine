#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "events/ApplicationEvent.h"
#include "Window.h"

namespace Sky 
{
	class SKY_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();

			void OnEvent(Event& event);
		private:
			bool OnWindowClose(WindowCloseEvent& event);

			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
	};

	// Implement this function in your Sky application
	Application* CreateApplication();
}

