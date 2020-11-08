#include "Application.h"

#include "events/ApplicationEvent.h"
#include "Log.h"

namespace Sky 
{
	Application::Application() 
	{}

	Application::~Application()
	{}

	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);
		SKY_APP_TRACE(e);
		while (true);
	}
}