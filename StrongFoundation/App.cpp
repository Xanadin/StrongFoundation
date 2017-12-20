#include "App.h"

#pragma region App

SBR::App::App()
{
}

SBR::App::App(const App &)
{
}

SBR::App::~App()
{
}

Result SBR::App::Initialize()
{
	return Result::SUCCESS;
}

int SBR::App::Run()
{
	return static_cast<int>(Result::SUCCESS);
}

#pragma endregion App

bool SBR::Report(LPCTSTR _Expr, LPCTSTR _Function, LPCTSTR _File, unsigned int _Line)
{
	static TCHAR Report[MAXSTRINGLEN];
	static UINT m_Num = 0;
	constexpr UINT LINESTRING = 20;

	_stprintf_s(Report, MAXSTRINGLEN, TEXT("\nFSB Assert n°%u\n"), ++m_Num);
	//_tcscat_s(Report, MAXSTRINGLEN,  GetSystemTime());
	_tcscat_s(Report, MAXSTRINGLEN, _Expr);
	_tcscat_s(Report, MAXSTRINGLEN, TEXT(" generated an exception in function: "));
	_tcscat_s(Report, MAXSTRINGLEN, _Function);
	_tcscat_s(Report, MAXSTRINGLEN, TEXT("\nFile: "));
	_tcscat_s(Report, MAXSTRINGLEN, _File);
	TCHAR buffer[LINESTRING];
	_stprintf_s(buffer, LINESTRING, TEXT(" Line: %u\n"), _Line);
	_tcscat_s(Report, LINESTRING, buffer);
	/*
	if (m_debugFlags & DEBUGGERLOG) PrintOnDebuggerOutput(Report);

	if (m_debugFlags & FILELOG)
	{
	m_file.Append(Report);
	static FILE* LogFile = nullptr;
	LogFile = (LogFile ? fopen(m_LogFileName, "a") : fopen(m_LogFileName, "w"));
	assert(LogFile);
	fwprintf(LogFile, m_Report);
	fclose(LogFile);
	}

	return (m_debugFlags & DEBUGBREAK) ? true : false;*/
	return true;
}