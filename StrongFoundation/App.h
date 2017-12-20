#pragma once

#include "StdIncl.h"

namespace SBR
{


	class App
	{
	public:
		App();
		App(const App&);
		virtual ~App();
	
		Result Initialize();
		int Run();
	private:

	};

	bool Report(LPCTSTR _Expr, LPCTSTR _Function, LPCTSTR _File, unsigned int _Line);
}


