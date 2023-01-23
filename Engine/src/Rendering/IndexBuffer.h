#pragma once

namespace Engine {

	class IndexBuffer
	{
	public:
		virtual void SetData(const unsigned int* indices, size_t size) = 0;
		virtual void Bind() = 0;
	private:
	};

}