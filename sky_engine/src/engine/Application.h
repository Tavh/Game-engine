#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Sky 
{
	class SKY_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();

		private:
			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
	};

	// Implement this function in your Sky application
	Application* CreateApplication();
}

