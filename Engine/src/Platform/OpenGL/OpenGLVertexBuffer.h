#pragma once
#include "Rendering/VertexBuffer.h"

namespace Engine {

	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer();
		virtual void Bind() override;
		virtual void SetData(const void* vertices, size_t size) override;
	private:
		unsigned int m_Id;
	};

}