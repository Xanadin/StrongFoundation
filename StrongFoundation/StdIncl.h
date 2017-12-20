#pragma once

#ifndef UNICODE
#define UNICODE
#endif // !UNICODE

#ifndef _UNICODE
#define _UNICODE
#endif // !_UNICODE

#include <tchar.h>
#include <windows.h>
#include <VersionHelpers.h>

#define SafeDelete(x) { delete x; x = 0; }
#define ReleaseCOM(x) {if(x){ x->Release(); x=0;}}
#define DEBUG_BREAK() __debugbreak()

// Error checking TODO cambiare return false con qualcosa di più significativo

#if defined(DEBUG) || defined(_DEBUG)

	#ifndef HR
	#define HR(x) {HRESULT hr=(x); if(FAILED(hr)){return false;}}
	#endif

	#ifndef FSB_ASSERT
	#define FSB_ASSERT( expr ) (void)( !( expr ) && ( SBR::Report( _CRT_WIDE( #expr ), _CRT_WIDE( __FUNCTION__ ), _CRT_WIDE( __FILE__ ), __LINE__ ) )  && ( DEBUG_BREAK(), 1 ) )
	#endif

#else

	#ifndef HR
	#define HR(x) (x)
	#endif

	#ifndef FSB_ASSERT
	#define FSB_ASSERT( expr ) (void)sizeof(expr) 
	#endif

#endif

enum class Result
{
	SUCCESS,
	FAILURE
};

constexpr int MAXNAMELEN = 256;
constexpr int MAXSTRINGLEN = 512;