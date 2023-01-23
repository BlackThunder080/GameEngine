#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Rendering/Renderer.h"
#include "OpenGLRenderer.h"
#include "OpenGLVertexBuffer.h"
#include "OpenGLIndexBuffer.h"

namespace Engine {

	OpenGLRenderer::OpenGLRenderer()
	{
		glEnable(GL_MULTISAMPLE);

		float vertices[] = {
			-0.5f, -0.5f, 0.0f,    1.0f, 0.0f, 0.0f, 1.0f,
			 0.5f, -0.5f, 0.0f,	   0.0f, 1.0f, 0.0f, 1.0f,
			 0.0f,  0.5f, 0.0f,	   0.0f, 0.0f, 1.0f, 1.0f,
		};
		unsigned int indices[] = { 0, 1, 2 };
	
		m_VertexBuffer->SetData(vertices, sizeof(vertices));
		m_VertexBuffer->SetLayout({
			{ DataType::Float3, "a_Position" },
			{ DataType::Float4, "a_Colour" },
		});
		m_VertexArray->AddVertexBuffer(m_VertexBuffer);

		m_IndexBuffer->SetData(indices, sizeof(indices));
		m_VertexArray->SetIndexBuffer(m_IndexBuffer);
	
		m_ShaderProgram->AddProgram({
			R"(
				#version 330 core

				layout (location = 0) in vec3 a_Position;
				layout (location = 1) in vec4 a_Colour;

				out vec4 v_Colour;

				void main()
				{
					v_Colour = a_Colour;
					gl_Position = vec4(a_Position, 1.0);
				}
			)",
			ShaderType::Vertex
		});

		m_ShaderProgram->AddProgram({
			R"(
				#version 330 core

				layout (location = 0) out vec4 o_Color;

				in vec4 v_Colour;
				
				void main()
				{
					o_Color = v_Colour;
				}
			)",
			ShaderType::Fragment
			});
		m_ShaderProgram->Compile();
	}

	void OpenGLRenderer::Render()
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	
		m_ShaderProgram->Bind();
		m_VertexArray->Bind();
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
	}

}
