#pragma once

#ifdef NT_PLATFORM_WINDOWS
	#ifdef NT_BUILD_DLL
		#define NERTHUS_API __declspec(dllexport)
	#else
		#define NERTHUS_API __declspec(dllimport)
	#endif
#else
	#error Nerthus supports only Windows!
#endif

#ifdef NT_ENABLE_ASSERTS
	#define NT_ASSERT(x, ...) { if(!(x)) { NT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreal(); } }
	#define NT_CORE_ASSERT(x, ...) { if(!(x)) { NT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreal(); } }
#else
	#define NT_ASSERT(x, ...)
	#define NT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)