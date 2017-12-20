#include "App.h"
#include <crtdbg.h>

class TestApp : public SBR::App
{
public:

private:

};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR pszCmdLine, int nCmdShow)
{
	// Enable run-time memory check for debug builds.
	#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	#endif

	TestApp theApp;
	if (theApp.Initialize() != Result::SUCCESS) return 0;
	return theApp.Run();
}