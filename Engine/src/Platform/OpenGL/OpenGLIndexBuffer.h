#pragma once
#include "Rendering/IndexBuffer.h"

namespace Engine {

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer();
		virtual void SetData(const unsigned int* indices, size_t size) override;
		virtual void Bind() override;
	private:
		unsigned int m_Id;
	};

}