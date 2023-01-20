#include "Application.h"
#include <GLFW/glfw3.h>
#include <iostream>

namespace Engine {

	Application::Application()
	{
		m_Window->EventCallback = &Application::OnEvent;
	}

	void Application::Run()
	{
		OnStart();
		while (!m_Window->shouldClose)
		{
			OnUpdate();
			m_Window->Update();
			m_Window->Render();
		}
	}

	void Application::OnEvent(Event* e)
	{
		std::cout << "Event" << std::endl;
	}

	Application::~Application()
	{
		glfwTerminate();
	}

}