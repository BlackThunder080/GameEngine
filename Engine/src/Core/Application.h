#pragma once
#include <memory>
#include "Window.h"
#include "Event.h"

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
		std::unique_ptr<Window> m_Window = std::make_unique<Window>();
	private:
		static void OnEvent(Event* e);
	};

}
