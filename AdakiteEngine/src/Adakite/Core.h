#pragma once

#ifdef ADK_PLATFORM_WINDOWS
	#ifdef ADK_BUILD_DLL
		#define ADAKITE_API __declspec(dllexport)
	#else
		#define ADAKITE_API __declspec(dllimport)
	#endif // ADK_BUILD_DLL
#else
#error Adakite only supports Windows
#endif // ADK_PLATFORM_WINDOWS
