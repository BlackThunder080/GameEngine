#include <glad/glad.h>
#include "OpenGLVertexBuffer.h"

namespace Engine {

	OpenGLVertexBuffer::OpenGLVertexBuffer()
	{
		glCreateBuffers(1, &m_Id);
	}

	void OpenGLVertexBuffer::SetData(const void* vertices, size_t size)
	{
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	void OpenGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_Id);
	}

}