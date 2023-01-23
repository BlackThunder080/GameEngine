#include <glad/glad.h>
#include "OpenGLIndexBuffer.h"

namespace Engine {

	OpenGLIndexBuffer::OpenGLIndexBuffer()
	{
		glCreateBuffers(1, &m_Id);
	}

	void OpenGLIndexBuffer::SetData(const unsigned int* indices, size_t size)
	{
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
	}

	void OpenGLIndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
	}

}