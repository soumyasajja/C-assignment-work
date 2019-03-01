#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#include <stdlib.h>
DWORD WINAPI thread_func(LPVOID lparam)
{
	for (int i = 0; i < 1000; i++)
	{
		printf("i=%d\n", i);
		Sleep(1000);
	}
	return 0;
}
void _tmain(int argc, TCHAR *argv[])
{
	DWORD dwThreadId;
	HANDLE hThread;
	hThread = CreateThread(
		NULL, 0, thread_func, 0, CREATE_SUSPENDED, &dwThreadId
	);
	Sleep(5000);
	DWORD res_thread = ResumeThread(hThread);
	WaitForSingleObject(hThread,INFINITE);
	CloseHandle(hThread);
	printf("Waiting for user input before exiting the process");
	getchar();
}