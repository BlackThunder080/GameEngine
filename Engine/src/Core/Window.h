#pragma once
#include <vector>
#include <functional>
#include "Event.h"

struct GLFWwindow;

namespace Engine {

	class Window
	{
	public:
		Window();
		~Window();
		void Update();
		void Render();
		std::function<void(Engine::Event*)> EventCallback;
		bool shouldClose;
	private:
		GLFWwindow* m_GlfwWindow;
	};

}