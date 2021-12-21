#pragma once


#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace ZoEngine {


	class ZOENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;


	};
}

// Core Logger Macros
#define ZO_CORE_TRACE(...)		::ZoEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ZO_CORE_INFO(...)		::ZoEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZO_CORE_WARN(...)		::ZoEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZO_CORE_ERROR(...)		::ZoEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ZO_CORE_CRITICAL(...)	::ZoEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Logger Macros
#define ZO_TRACE(...)			::ZoEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ZO_INFO(...)			::ZoEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define ZO_WARN(...)			::ZoEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ZO_ERROR(...)			::ZoEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define ZO_CRITICAL(...)		::ZoEngine::Log::GetClientLogger()->critical(__VA_ARGS__)


