#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Adakite {
	class ADAKITE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// core side logs macros
#define ADK_CORE_ERROR(...) ::Adakite::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ADK_CORE_WARN(...)  ::Adakite::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ADK_CORE_INFO(...)  ::Adakite::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ADK_CORE_TRACE(...) ::Adakite::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ADK_CORE_FATAL(...) ::Adakite::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// client side logs macros
#define ADK_ERROR(...) ::Adakite::Log::GetClientLogger()->error(__VA_ARGS__)
#define ADK_WARN(...)  ::Adakite::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ADK_INFO(...)  ::Adakite::Log::GetClientLogger()->info(__VA_ARGS__)
#define ADK_TRACE(...) ::Adakite::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ADK_FATAL(...) ::Adakite::Log::GetClientLogger()->fatal(__VA_ARGS__)
