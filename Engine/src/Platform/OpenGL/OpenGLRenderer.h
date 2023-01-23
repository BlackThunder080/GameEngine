#pragma once
#include "OpenGLVertexArray.h"
#include "OpenGLVertexBuffer.h"
#include "OpenGLIndexBuffer.h"
#include "OpenGLShader.h"

namespace Engine {

	class OpenGLRenderer : public Renderer
	{
	public:
		OpenGLRenderer();
		virtual void Render() override;
	private:
		std::shared_ptr<OpenGLVertexArray>   m_VertexArray   = std::make_shared<OpenGLVertexArray>();
		std::shared_ptr<OpenGLVertexBuffer>  m_VertexBuffer  = std::make_shared<OpenGLVertexBuffer>();
		std::shared_ptr<OpenGLIndexBuffer>   m_IndexBuffer   = std::make_shared<OpenGLIndexBuffer>();
		std::shared_ptr<OpenGLShaderProgram> m_ShaderProgram = std::make_shared<OpenGLShaderProgram>();
	};

}