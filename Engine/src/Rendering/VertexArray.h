#pragma once
#include <vector>
#include <memory>
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace Engine {

	class VertexArray
	{
	public:
		virtual void AddVertexBuffer(std::shared_ptr<VertexBuffer> vertexbuffer) = 0;
		virtual void SetIndexBuffer(std::shared_ptr<IndexBuffer> indexbuffer) = 0;
		virtual void Bind() = 0;
	protected:
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
	};

}