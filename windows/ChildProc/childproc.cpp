#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <stdlib.h>
void _tmain(int argc, TCHAR *argv[], TCHAR *env)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	SECURITY_ATTRIBUTES sa;
	HANDLE hproc;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	if (argc != 2)
	{
		printf("Usage: %s [cmdline]\n", argv[0]);
		return;
	}
	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		printf("Create Process error (%d\n)", GetLastError());
		getchar();
		return;
	}
	printf("Process Id = %d\n", GetProcessId(pi.hProcess));
	printf("Current Process Id = %d\n", GetCurrentProcessId());
	printf("Current Thread = %d\n", GetCurrentThread());
	printf("Current Thread Id = %d\n", GetCurrentThreadId());
	printf("Thread Id = %d\n", GetThreadId(pi.hThread));
	printf("Process Id of Thread = %d\n", GetProcessIdOfThread(pi.hThread));
	WaitForSingleObject(pi.hProcess, INFINITE); 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}