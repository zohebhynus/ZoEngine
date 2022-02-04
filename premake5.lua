workspace "ZoEngine"
	architecture "x64"
	
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

include "ZoEngine/Vendor/GLFW"
include "ZoEngine/Vendor/GLAD"

project "ZoEngine"
	location "ZoEngine"
	kind "SharedLib"
	language "C++"
	
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
		"%{IncludeDir.Glad}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
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
		buildoptions "/MDd"
		symbols "On"
		
	filter "configurations:Release"
		defines "ZO_RELEASE"
		buildoptions "/MD"
		optimize "On"
		
	filter "configurations:FinalRelease"
		defines "ZO_FINALRELEASE"
		buildoptions "/MD"
		optimize "On"




project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
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
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"ZO_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "ZO_DEBUG"
		buildoptions "/MDd"
		symbols "On"
		
	filter "configurations:Release"
		defines "ZO_RELEASE"
		buildoptions "/MD"
		optimize "On"
		
	filter "configurations:FinalRelease"
		defines "ZO_FINALRELEASE"
		buildoptions "/MD"
		optimize "On"
	
	