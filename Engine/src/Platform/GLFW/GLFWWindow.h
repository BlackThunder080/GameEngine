#pragma once
#include "Core/Window.h"

namespace Engine {

	class GLFWWindow : public Window
	{
	public:
		GLFWWindow();
		~GLFWWindow();
		virtual void Update() override;
		virtual void Draw() override;
	private:
		GLFWwindow* m_GlfwWindow;
	};

}