#pragma once

namespace Engine {

	class OpenGLRenderer : public Renderer
	{
	public:
		virtual void Init() override;
		virtual void Render() override;
	private:
		unsigned int m_VertexArray;
		unsigned int m_VertexBuffer;
		unsigned int m_IndexBuffer;
	};

}