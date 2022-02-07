workspace "ZoEngine"
	architecture "x64"
	startproject "Sandbox"
	
	configurations
	{
		"Debug",
		"Release",
		"FinalRelease"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Includes relative to root
IncludeDir = {}
IncludeDir["GLFW"] = "ZoEngine/Vendor/GLFW/include"
IncludeDir["Glad"] = "ZoEngine/Vendor/Glad/include"
IncludeDir["ImGui"] = "ZoEngine/Vendor/ImGui"
IncludeDir["glm"] = "ZoEngine/Vendor/glm"

group "Dependencies"
	include "ZoEngine/Vendor/GLFW"
	include "ZoEngine/Vendor/Glad"
	include "ZoEngine/Vendor/ImGui"
group ""

project "ZoEngine"
	location "ZoEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "ZoEngine/Source/pch.cpp"
	
	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp",
		"%{prj.name}/Vendor/glm/glm/**.hpp",
		"%{prj.name}/Vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}
	
	includedirs
	{
		"%{prj.name}/Source",
		"%{prj.name}/Vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}
	
	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"ZO_PLATFORM_WINDOWS",
			"ZO_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
	
	filter "configurations:Debug"
		defines "ZO_DEBUG"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		defines "ZO_RELEASE"
		runtime "Release"
		optimize "on"
		
	filter "configurations:FinalRelease"
		defines "ZO_FINALRELEASE"
		runtime "Release"
		optimize "on"




project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}
	
	includedirs
	{
		"ZoEngine/Vendor/spdlog/include",
		"ZoEngine/Source",
		"ZoEngine/Vendor",
		"%{IncludeDir.glm}"
	}
	
	links
	{
		"ZoEngine"
	}
	
	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"ZO_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "ZO_DEBUG"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		defines "ZO_RELEASE"
		runtime "Release"
		optimize "on"
		
	filter "configurations:FinalRelease"
		defines "ZO_FINALRELEASE"
		runtime "Release"
		optimize "on"
	
	