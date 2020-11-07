#pragma once

#ifdef SKY_PLATFORM_WINDOWS
	extern Sky::Application* Sky::CreateApplication();
	int main(int argc, char** argv)
	{
		printf("Running a Sky application");
		auto app = Sky::CreateApplication();
		app->Run();
		delete app;
	}
#endif