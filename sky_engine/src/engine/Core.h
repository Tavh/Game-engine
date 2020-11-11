#pragma once

#ifdef SKY_PLATFORM_WINDOWS
	#ifdef SKY_BUILD_DLL
		#define SKY_API __declspec(dllexport)
	#else
		#define SKY_API __declspec(dllimport)
	#endif	
#else 
	#error Sky only supports windows right now
#endif

#ifdef SKY_ENABLE_ASSERTS
	#define SKY_ASSERT(x, ...) { if(!(x) { SKY_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SKY_CORE_ASSERT(x, ... { if!(x)) { SKY_CORE_ERROR("Assertion failed {0}", __VA_ARGS__); __debugbreak(); }
#else
	#define SKY_ASSERT(x, ...)
	#define SKY_CORE_ASSERT(x, ...)
#endif

#define BIT(bits) (1 << bits)