workspace "ZoEngine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"FinalRelease"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ZoEngine"
	location "ZoEngine"
	kind "SharedLib"
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
		"%{prj.name}/Vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"ZO_PLATFORM_WINDOWS",
			"ZO_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "ZO_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "ZO_RELEASE"
		optimize "On"
		
	filter "configurations:FinalRelease"
		defines "ZO_FINALRELEASE"
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
		symbols "On"
		
	filter "configurations:Release"
		defines "ZO_RELEASE"
		optimize "On"
		
	filter "configurations:FinalRelease"
		defines "ZO_FINALRELEASE"
		optimize "On"
	
	