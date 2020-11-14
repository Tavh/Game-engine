#include <Engine.h>

class ExampleLayer : public Sky::Layer
{
	public:
		ExampleLayer() : Layer("Example") {}

		void OnUpdate() override
		{
			SKY_APP_INFO("ExampleLayer::Update");
		}

		void OnEvent(Sky::Event& event) override
		{
			SKY_APP_TRACE("{0}", event);
		}

};
class SandboxApplication : public Sky::Application
{
	public:
		SandboxApplication() 
		{
			PushLayer(new ExampleLayer());
		}

		~SandboxApplication() {}
};		

Sky::Application* Sky::CreateApplication() 
{
	return new SandboxApplication();
}