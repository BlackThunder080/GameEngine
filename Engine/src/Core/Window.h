#pragma once
#include <vector>
#include <functional>
#include "Rendering/Renderer.h"
#include "Events/Event.h"

struct GLFWwindow;

namespace Engine {

	class Window
	{
	public:
		virtual void Update() = 0;
		virtual void Draw() = 0;
		std::function<void(Engine::Event*)> EventCallback = nullptr;
		bool shouldClose = false;
	protected:
		std::unique_ptr<Renderer> m_Renderer;
	};

}