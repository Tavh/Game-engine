#pragma once

#ifdef SKY_PLATFORM_WINDOWS
extern Sky::Application* Sky::CreateApplication();
int main(int argc, char** argv)
{
	Sky::Log::Init();
	SKY_CORE_INFO("Initialized core logger");
	SKY_APP_INFO("Initialized app logger");
	auto app = Sky::CreateApplication();
	app->Run();
	delete app;
}
#endif