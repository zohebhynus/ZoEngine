#pragma once
#include "ZoEngine/Graphics/GraphicsContext.h"

struct GLFWwindow;

namespace ZoEngine
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* window);
		~OpenGLContext();

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_Window;
	};
}
