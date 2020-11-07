#include <Sky.h>

class SandboxApplication : public Sky::Application
{
	public: 
		SandboxApplication() {}
		~SandboxApplication() {}
};		

Sky::Application* Sky::CreateApplication() 
{
	return new SandboxApplication();
}