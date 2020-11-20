#include <Engine.h>

class SandboxApplication : public Sky::Application
{
	public:
		SandboxApplication() 
		{
			PushOverlay(new Sky::ImGuiLayer());
		}

		~SandboxApplication() {}
};		

Sky::Application* Sky::CreateApplication() 
{
	return new SandboxApplication();
}