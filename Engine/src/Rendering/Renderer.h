#pragma once

namespace Engine {

	class Renderer
	{
	public:
		virtual void Init() = 0;
		virtual void Render() = 0;
	};

}