#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#include <stdlib.h>
DWORD WINAPI thread_func(LPVOID lparam)
{
	for (int i = 0; i < 10; i++)
	{
		printf("i=%d\n", i);
		Sleep(1000);
	}
	return 0;
}
void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO si1;
	PROCESS_INFORMATION pi1;
	SECURITY_ATTRIBUTES sa;
	HANDLE hThread;
	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	SetPriorityClass(pi1.hProcess, HIGH_PRIORITY_CLASS);
	if (argc != 3)
	{
		printf("Usage\n");
		getchar();
		return;
	}
	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1))
	{
		printf("Create Process error (%d)\n", GetLastError());
		getchar();
		return;
	}
	
}