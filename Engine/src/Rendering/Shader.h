#pragma once
#include <string>
#include <unordered_map>
#include "Core/DataType.h"

namespace Engine {

	enum ShaderType : uint8_t
	{
		Vertex,
		Fragment,
	};

	struct Shader
	{
		std::string Source;
		ShaderType Type;
	};

	class ShaderProgram
	{
	public:
		virtual void Compile() = 0;
		virtual void Bind() = 0;
		void AddProgram(Shader program) { m_Programs.push_back(program); };
	protected:
		std::vector<Shader> m_Programs;
	};

}