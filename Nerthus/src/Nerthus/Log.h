#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Nerthus
{
	class NERTHUS_API Log
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

// Core log macros
#define NT_CORE_ERROR(...)		::Nerthus::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NT_CORE_WARN(...)		::Nerthus::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NT_CORE_INFO(...)		::Nerthus::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NT_CORE_TRACE(...)		::Nerthus::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NT_CORE_FATAL(...)		::Nerthus::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define NT_ERROR(...)			::Nerthus::Log::GetClientLogger()->error(__VA_ARGS__)
#define NT_WARN(...)			::Nerthus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NT_INFO(...)			::Nerthus::Log::GetClientLogger()->info(__VA_ARGS__)
#define NT_TRACE(...)			::Nerthus::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NT_FATAL(...)			::Nerthus::Log::GetClientLogger()->fatal(__VA_ARGS__)