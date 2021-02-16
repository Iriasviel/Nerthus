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