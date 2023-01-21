#include <iostream>
#include <GLFW/glfw3.h>
#include "Application.h"
#include "Events/Event.h"
#include "Platform/GLFW/GLFWWindow.h"

namespace Engine {

	Application::Application()
	{
		m_Window = std::make_unique<GLFWWindow>();
		m_Window->EventCallback = &Application::EventCallback;
	}

	void Application::Run()
	{
		OnStart();
		while (!m_Window->shouldClose)
		{
			OnUpdate();
			m_Window->Update();
			m_Window->Draw();
		}
	}

	void Application::EventCallback(Event* e)
	{

	}

	Application::~Application()
	{
		glfwTerminate();
	}

}