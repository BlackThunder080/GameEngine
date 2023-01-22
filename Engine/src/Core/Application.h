#pragma once
#include <memory>
#include "Window.h"
#include "Logger.h"
#include "Events/Event.h"

struct GLFWwindow;

namespace Engine {

	class Application
	{
	public:
		Application();
		void Run();
		virtual void OnStart()  {};
		virtual void OnUpdate() {};
		virtual ~Application();
	protected:
	private:
		std::unique_ptr<Window> m_Window;
		static void EventCallback(Event* e);
	};

}
