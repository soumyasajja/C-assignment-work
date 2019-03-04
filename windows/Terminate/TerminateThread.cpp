#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <tchar.h>
DWORD WINAPI thread_func(LPVOID lparam)
{
	for (int i = 0; i < 10; i++)
	{
		printf("i=%d\n", i);
		Sleep(1000);
	}
	return 0;
}
void _tmain(int argc, TCHAR *argv[])
{
	DWORD dwThreadId, dwExitCode;
	LPDWORD lp = NULL;
	HANDLE hThread;
	hThread = CreateThread(
		NULL, 0, thread_func, 0, CREATE_SUSPENDED, &dwThreadId
	);
	Sleep(5000);
	DWORD res_thread = ResumeThread(hThread);
	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);
	TerminateThread(hThread, dwExitCode);
	dwExitCode = GetExitCodeThread(hThread, lp);
	printf("%d", dwExitCode);
	//ExitThread(dwExitCode);
	printf("Waiting for user input before exiting the process");
	getchar();
}