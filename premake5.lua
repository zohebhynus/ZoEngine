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

include "ZoEngine/Vendor/GLFW"
include "ZoEngine/Vendor/Glad"
include "ZoEngine/Vendor/ImGui"

project "ZoEngine"
	location "ZoEngine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "ZoEngine/Source/pch.cpp"
	
	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/Source",
		"%{prj.name}/Vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		
		defines
		{
			"ZO_PLATFORM_WINDOWS",
			"ZO_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "ZO_DEBUG"
		runtime "Debug"
		symbols "On"
		
	filter "configurations:Release"
		defines "ZO_RELEASE"
		runtime "Release"
		optimize "On"
		
	filter "configurations:FinalRelease"
		defines "ZO_FINALRELEASE"
		runtime "Release"
		optimize "On"




project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"
	
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
		"ZoEngine/Source"
	}
	
	links
	{
		"ZoEngine"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		
		defines
		{
			"ZO_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "ZO_DEBUG"
		runtime "Debug"
		symbols "On"
		
	filter "configurations:Release"
		defines "ZO_RELEASE"
		runtime "Release"
		optimize "On"
		
	filter "configurations:FinalRelease"
		defines "ZO_FINALRELEASE"
		runtime "Release"
		optimize "On"
	
	