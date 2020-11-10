#include "skypch.h"
#include "Application.h"
#include "events/ApplicationEvent.h"
#include "Log.h"

namespace Sky 
{
	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{}

	void Application::Run() 
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}