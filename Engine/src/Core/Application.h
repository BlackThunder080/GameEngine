#pragma once
#include <memory>
#include "Window.h"
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
		std::unique_ptr<Window> m_Window;
	private:
		static void EventCallback(Event* e);
	};

}
