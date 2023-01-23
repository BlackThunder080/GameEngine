#pragma once
#include "Rendering/VertexArray.h"

namespace Engine {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual void AddVertexBuffer(std::shared_ptr<VertexBuffer> vertexbuffer) override;
		virtual void SetIndexBuffer(std::shared_ptr<IndexBuffer> indexbuffer) override;
		virtual void Bind() override;
	private:
		unsigned int m_Id;
	};

}