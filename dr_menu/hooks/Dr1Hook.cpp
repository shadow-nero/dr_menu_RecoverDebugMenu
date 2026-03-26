#include "../Hook.hpp"
#include "../drlib/Dr1.h"
#include <iostream>
#include <cstdio>
namespace Hook
{
	DrLib::Dr1::Funcs::Debug::LogFunc* LogFuncOriginal;

	char buffer[256];
	void LogDetour(char* format, ...)
	{
	
		va_list args;
		va_start(args, format);
		vsprintf_s(buffer, format, args);
		std::cout << buffer << "\n";
		va_end(args);
	}


	void HookDR1()
	{
		printf("Hooking Dr1...\n");

		Hook::InitHook("Log", DrLib::Dr1::Funcs::Debug::Log, &LogDetour, &LogFuncOriginal);
	}
}