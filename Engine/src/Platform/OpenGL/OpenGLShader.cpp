#include <glad/glad.h>
#include "OpenGLShader.h"
#include "Core/Logger.h"

namespace Engine {

	OpenGLShaderProgram::OpenGLShaderProgram()
	{
		m_Id = glCreateProgram();
	}

	void OpenGLShaderProgram::Compile()
	{
		for (auto const& shader : m_Programs)
		{
			unsigned int shaderId;
			switch (shader.Type)
			{
			case ShaderType::Vertex:
				shaderId = glCreateShader(GL_VERTEX_SHADER);
				break;
			case ShaderType::Fragment:
				shaderId = glCreateShader(GL_FRAGMENT_SHADER);
				break;
			default:
				return;
			}

			const char* source = shader.Source.c_str();
			glShaderSource(shaderId, 1, &source, NULL);
			
			glCompileShader(shaderId);

			int isCompiled;
			glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(shaderId, maxLength, &maxLength, &infoLog[0]);

				glDeleteShader(shaderId);

				Logger::Console()->error("Failed to Compile Shader with error message {0}", (char*)infoLog.data());
				return;
			}
			
			glAttachShader(m_Id, shaderId);
		}

		glLinkProgram(m_Id);
	}

	void OpenGLShaderProgram::Bind()
	{
		glUseProgram(m_Id);
	}

}