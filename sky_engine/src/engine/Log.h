#pragma once

#include "skypch.h"
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Sky 
{
	class SKY_API Log
	{
		public:
			static void Init();
			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
			inline static std::shared_ptr<spdlog::logger>& GetAppLogger() { return s_AppLogger; }

		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_AppLogger;
	};
}

// Core log macros
#define SKY_CORE_TRACE(...) ::Sky::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SKY_CORE_INFO(...)  ::Sky::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SKY_CORE_WARN(...)  ::Sky::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SKY_CORE_ERROR(...) ::Sky::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SKY_CORE_FATAL(...) ::Sky::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// App log macros
#define SKY_APP_TRACE(...) ::Sky::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SKY_APP_INFO(...)  ::Sky::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SKY_APP_WARN(...)  ::Sky::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SKY_APP_ERROR(...) ::Sky::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SKY_APP_FATAL(...) ::Sky::Log::GetCoreLogger()->fatal(__VA_ARGS__)