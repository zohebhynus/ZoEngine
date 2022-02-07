#include "pch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"
#include "ZoEngine/Application.h"

//Temp
#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace ZoEngine
{
	ImGuiLayer::ImGuiLayer()
	{
	}
	ImGuiLayer::~ImGuiLayer()
	{
	}
	void ImGuiLayer::OnAttach()
	{
		//Implementation from ..\ZoEngine\Vendor\ImGui\examples\example_glfw_opengl3\main.cpp
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
		//io.ConfigViewportsNoAutoMerge = true;
		//io.ConfigViewportsNoTaskBarIcon = true;

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsClassic();

		// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		

		Application& app = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

		//set high dpi scaling for ImGui
		style.ScaleAllSizes(app.GetWindow().GetHighDPIScalingFactor());
		io.FontGlobalScale = 2;//app.GetWindow().GetHighDPIScalingFactor();

		// Setup Platform/Renderer backends
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");

	}
	void ImGuiLayer::OnDetach()
	{
		//Implementation from ..\ZoEngine\Vendor\ImGui\examples\example_glfw_opengl3\main.cpp
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}
	void ImGuiLayer::OnImGuiRender()
	{
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}
	void ImGuiLayer::Begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}
	void ImGuiLayer::End()
	{
		Application& app = Application::Get();
		ImGuiIO& io = ImGui::GetIO();

		io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		//viewport flag check
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backUpContext = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backUpContext);
		}
	}
}