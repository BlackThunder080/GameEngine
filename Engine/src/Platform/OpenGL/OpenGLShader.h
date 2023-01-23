#pragma once
#include "Rendering/Shader.h"

namespace Engine {

	class OpenGLShaderProgram : public ShaderProgram
	{
	public:
		OpenGLShaderProgram();
		virtual void Bind() override;
		virtual void Compile() override;
	private:
		unsigned int m_Id;
	};


}