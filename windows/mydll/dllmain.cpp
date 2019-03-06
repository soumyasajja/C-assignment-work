#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include "Header.h"
BOOL WINAPI DllMain(HANDLE hand, DWORD msg, LPVOID res)
{
	switch (msg)
	{
	case DLL_PROCESS_ATTACH:
		printf("DLL attached\n");
		break;
	case DLL_PROCESS_DETACH:
		printf("DLL detached\n");
		break;
	}
	return TRUE;
}