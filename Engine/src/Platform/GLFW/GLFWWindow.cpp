#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "GLFWWindow.h"
#include "Core/Logger.h"
#include "Events/KeyEvent.h"
#include "Platform/OpenGL/OpenGLRenderer.h"

namespace Engine {

	GLFWWindow::GLFWWindow()
	{
		if (!glfwInit())
			Logger::Console()->error("Couldn't Initialize GLFW");
		
		m_GlfwWindow = glfwCreateWindow(1600, 900, "Window", nullptr, nullptr);
		glfwMakeContextCurrent(m_GlfwWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			Logger::Console()->error("Couldn't Initialize GLAD");

		glfwSetWindowUserPointer(m_GlfwWindow, this);
		glfwSetWindowSizeCallback(m_GlfwWindow, [](GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		});
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