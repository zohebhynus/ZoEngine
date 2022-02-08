#include "pch.h"
#include "OpenGLContext.h"

#include"GLFW/glfw3.h"
#include "glad/glad.h"

ZoEngine::OpenGLContext::OpenGLContext(GLFWwindow* window)
	:m_Window(window)
{
	ZO_CORE_ASSERT(window, "Window varaible is null.");
}

ZoEngine::OpenGLContext::~OpenGLContext()
{
}

void ZoEngine::OpenGLContext::Init()
{
	glfwMakeContextCurrent(m_Window);
	int result = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	ZO_CORE_ASSERT(result, "Glad Failed to Initialize.")
}

void ZoEngine::OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_Window);
}
