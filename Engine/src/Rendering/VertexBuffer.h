#pragma once
#include <string>
#include "Core/DataType.h"

namespace Engine {

	struct VertexBufferLayoutElement
	{
		std::string Name;
		DataType Type;
		uint32_t Size;
		uint32_t Offset;
		bool Normalized;

		VertexBufferLayoutElement(DataType type, std::string name, bool normalized = false)
			: Type(type), Name(name), Size(DataTypeSize(type)), Offset(0), Normalized(normalized) {}
		
		uint32_t ComponentCount() const
		{
			switch (this->Type)
			{
			case DataType::Float: return 1;
			case DataType::Float2: return 2;
			case DataType::Float3: return 3;
			case DataType::Float4: return 4;
			}

			Logger::Console()->error("Unknown Data Type");
			return 0;
		}
	};

	class VertexBufferLayout
	{
	public:
		//VertexBufferLayout()
		//	: m_Elements(std::vector<VertexBufferLayoutElement>()), m_Stride(0) {}
		VertexBufferLayout(std::initializer_list<VertexBufferLayoutElement> elements)
			: m_Elements(elements)
			{
				m_Stride = 0;
				uint32_t offset = 0;
				for (auto& element : m_Elements)
				{
					element.Offset = offset;
					offset += element.Size;
				}
				m_Stride = offset;
			}
		inline const std::vector<VertexBufferLayoutElement>& Elements() { return m_Elements; };
		inline const uint32_t Stride() { return m_Stride; };

		std::vector<VertexBufferLayoutElement>::iterator begin() { return m_Elements.begin(); }
		std::vector<VertexBufferLayoutElement>::iterator end()   { return m_Elements.end(); }
	private:
		std::vector<VertexBufferLayoutElement> m_Elements;
		uint32_t m_Stride;
	};


	class VertexBuffer
	{
	public:
		virtual void Bind() = 0;
		virtual void SetData(const void* vertices, size_t size) = 0;
		void SetLayout(VertexBufferLayout layout) { m_Layout = layout; }
		VertexBufferLayout& GetLayout(void) { return m_Layout; }
	private:
		VertexBufferLayout m_Layout = {};
	};

}