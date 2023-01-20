#include <GLFW/glfw3.h>
#include "Window.h"
#include "Events/KeyPressedEvent.h"
#include "Events/KeyReleasedEvent.h"

namespace Engine {

	Window::Window()
	{
		glfwInit();
		
		m_GlfwWindow = glfwCreateWindow(1600, 900, "Window", nullptr, nullptr);
		glfwSetWindowUserPointer(m_GlfwWindow, this);
		
		EventCallback = nullptr;
		shouldClose = false;
	}

	void Window::Update()
	{
		glfwPollEvents();
		glfwSetKeyCallback(m_GlfwWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			Window* EngineWindow = (Window*)glfwGetWindowUserPointer(window);
			
			if (EngineWindow->EventCallback == nullptr)
				return;
		
			switch (action)
			{
			case GLFW_PRESS:
				EngineWindow->EventCallback(new KeyPressedEvent(scancode, false));
				break;
			case GLFW_RELEASE:
				EngineWindow->EventCallback(new KeyReleasedEvent(scancode));
			case GLFW_REPEAT:
				EngineWindow->EventCallback(new KeyPressedEvent(scancode, true));
			}
		});
		shouldClose = glfwWindowShouldClose(m_GlfwWindow);
	}

	void Window::Render()
	{
		glfwSwapBuffers(m_GlfwWindow);
	}

	Window::~Window()
	{
		glfwTerminate();
	}

}