#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "GLFWWindow.h"
#include "Events/KeyEvent.h"
#include "Platform/OpenGL/OpenGLRenderer.h"

namespace Engine {

	GLFWWindow::GLFWWindow()
	{
		glfwInit();
		m_GlfwWindow = glfwCreateWindow(1600, 900, "Window", nullptr, nullptr);
		glfwMakeContextCurrent(m_GlfwWindow);

		glfwSetWindowUserPointer(m_GlfwWindow, this);
		glfwSetKeyCallback(m_GlfwWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			Window* EngineWindow = (Window*)glfwGetWindowUserPointer(window);

			if (EngineWindow->EventCallback == nullptr)
				return;

			switch (action)
			{
			case GLFW_PRESS:
				EngineWindow->EventCallback((Event*) new KeyPressedEvent(scancode, false));
				break;
			case GLFW_RELEASE:
				EngineWindow->EventCallback((Event*) new KeyReleasedEvent(scancode));
			case GLFW_REPEAT:
				EngineWindow->EventCallback((Event*) new KeyPressedEvent(scancode, true));
			}
		});

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cerr << "Couldn't Initialize GLAD" << std::endl;
			exit(1);
		}

		m_Renderer = std::make_unique<OpenGLRenderer>();
		m_Renderer->Init();
	}

	GLFWWindow::~GLFWWindow()
	{
		glfwTerminate();
	}

	void GLFWWindow::Update()
	{
		glfwPollEvents();
		shouldClose = glfwWindowShouldClose(m_GlfwWindow);
	}

	void GLFWWindow::Draw()
	{
		m_Renderer->Render();
	
		glfwSwapBuffers(m_GlfwWindow);
	}

}