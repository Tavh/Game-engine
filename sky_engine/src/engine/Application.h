#pragma once

#include "Core.h"

namespace Sky {
	class SKY_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	// Define this function in your Sky application
	Application* CreateApplication();
}

