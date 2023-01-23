#include <glad/glad.h>
#include "OpenGLVertexArray.h"

namespace Engine {
	

	static uint32_t DataTypeOpenGLBaseType(DataType datatype)
	{
		switch (datatype)
		{
		case DataType::Float  : return GL_FLOAT;
		case DataType::Float2 : return GL_FLOAT;
		case DataType::Float3 : return GL_FLOAT;
		case DataType::Float4 : return GL_FLOAT;
		}

		Logger::Console()->error("Unknown Data Type");
		return 0;
	}


	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_Id);
	}

	void OpenGLVertexArray::AddVertexBuffer(std::shared_ptr<VertexBuffer> vertexbuffer)
	{
		Bind();
		vertexbuffer->Bind();
		m_VertexBuffers.push_back(vertexbuffer);
		uint32_t index = 0;
		for (auto const& element : vertexbuffer->GetLayout())
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index,
				element.ComponentCount(),
				DataTypeOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				vertexbuffer->GetLayout().Stride(),
				(const void*)(size_t)element.Offset);
			index++;
		}
	}

	void OpenGLVertexArray::SetIndexBuffer(std::shared_ptr<IndexBuffer> indexbuffer)
	{
		Bind();
		indexbuffer->Bind();
		m_IndexBuffer = indexbuffer;
	}

	void OpenGLVertexArray::Bind()
	{
		glBindVertexArray(m_Id);
	}

}