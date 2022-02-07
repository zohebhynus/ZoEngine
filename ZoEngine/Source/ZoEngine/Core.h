#pragma once

#ifdef ZO_PLATFORM_WINDOWS
#if ZO_DYNAMIC_LINK
	#ifdef ZO_BUILD_DLL
		#define ZOENGINE_API __declspec(dllexport)
	#else
		#define ZOENGINE_API __declspec(dllimport)
	#endif // ZO_BUILD_DLL
#else
	#define ZOENGINE_API
#endif //ZO_DYNAMIC_LINK
#else
	#error ZoEngine only supports Windows right now!
#endif // ZO_PLATFORM_WINDOWS

#ifdef ZO_DEBUG
	#define ZO_ENABLE_ASSERT
#endif // ZO_DEBUG


#ifdef ZO_ENABLE_ASSERT
	#define ZO_CORE_ASSERT(x, ...)       {if(!x){ZO_CORE_ERROR("Error : {0}",__VA_ARGS__); __debugbreak();} }
	#define ZO_ASSERT(x, ...)            {if(!x){ZO_ERROR("Error : {0}",__VA_ARGS__); __debugbreak();} }
#else
	#define ZO_CORE_ASSERT(x, ...)       
	#define ZO_ASSERT(x, ...)
#endif //ZO_DEBUG_ASSERT

//For bit field
#define BIT(x) (1 << x)

//Binding function
#define BIND_EVENT_FUNC(functionName)			std::bind(&functionName, this, std::placeholders::_1)