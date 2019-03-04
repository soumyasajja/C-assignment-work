#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#include <stdlib.h>
const int COUNT = 1000;
int g_nSum = 0;
CRITICAL_SECTION g_cs;
DWORD WINAPI FirstThread(LPVOID lparam)
{
	EnterCriticalSection(&g_cs);
	g_nSum = 0;
	for (int i = 1; i <= COUNT; i++)
	{
		g_nSum += i;
		printf("sum=%d\n", g_nSum);
	}
	LeaveCriticalSection(&g_cs);
	return g_nSum;
}
DWORD WINAPI SecondThread(LPVOID lparam)
{
	EnterCriticalSection(&g_cs);
	g_nSum = 0;
	for (int i = 1; i <= COUNT; i++)
	{
		g_nSum += i;
		printf("sum=%d\n", g_nSum);
	}
	LeaveCriticalSection(&g_cs);
	return g_nSum;
}
int main()
{
	DWORD thId1, thId2;
	HANDLE hThread1, hThread2;
	HANDLE arry_hand[2];
	InitializeCriticalSectionAndSpinCount(&g_cs, 4000);
	hThread1 = CreateThread(NULL, 0, FirstThread, NULL, 0, &thId1);
	if (NULL == hThread1)
	{
		printf("Unable to thread. Error %d", GetLastError());
		getchar();
		return FALSE;
	}
	hThread2 = CreateThread(NULL, 0, SecondThread, NULL, 0, &thId2);
	if (NULL == hThread2)
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
	DeleteCriticalSection(&g_cs);
	printf("Waiting for user input before exiting the process");
	getchar();
	return 0;
}