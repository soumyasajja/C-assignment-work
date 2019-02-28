#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
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
int main()
{
	DWORD dwThreadId1, dwThreadId2;
	HANDLE hThread1, hThread2;
	HANDLE arry_hand[2];
	hThread1 = CreateThread(
		NULL, 0, thread_func, 0, NULL, &dwThreadId1
	);
	if (NULL == hThread1)
	{
		printf("Unable to thread. Error %d", GetLastError());
		getchar();
		return FALSE;
	}
	hThread2 = CreateThread(
		NULL, 0, thread_func, NULL, 0, &dwThreadId2
	);
	if (NULL == hThread1)
	{
		printf("Unable to thread. Error %d", GetLastError());
		getchar();
		return FALSE;
	}
	arry_hand[0] = hThread1;
	arry_hand[1] = hThread2;
	WaitForMultipleObjects(2, arry_hand, TRUE, INFINITE);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	printf("Waiting for user input before exiting the process");
	getchar();
	return 0;
}