#pragma once

#ifdef ZO_PLATFORM_WINDOWS
	#ifdef ZO_BUILD_DLL
		#define ZOENGINE_API __declspec(dllexport)
	#else
		#define ZOENGINE_API __declspec(dllimport)
	#endif // ZO_BUILD_DLL
#else
	#error ZoEngine only supports Windows right now!
#endif // ZO_PLATFORM_WINDOWS

//For bit field
#define BIT(x) (1 << x)