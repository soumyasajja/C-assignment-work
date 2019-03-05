#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <stdlib.h>
DWORD WINAPI thread_func1(LPVOID lparam)
{

	Sleep(4000);
	return 1;
}
DWORD WINAPI thread_func2(LPVOID lparam)
{

	Sleep(3000);
	return 1;
}
int main()
{
	DWORD dwThreadId1,dwThreadId2;
	HANDLE hThread1,hThread2;
	HANDLE arry_hand[2];
	BOOL bwaitall=FALSE;
	DWORD dwMs=INFINITE;
	hThread1 = CreateThread(
		NULL, 0, thread_func1, 0, NULL, &dwThreadId1
	);
	if (NULL == hThread1)
	{
		printf("Unable to thread. Error %d", GetLastError());
		getchar();
		return FALSE;
	}
	hThread2 = CreateThread(
		NULL, 0, thread_func2, 0, NULL, &dwThreadId2
	);
	if (NULL == hThread2)
	{
		printf("Unable to thread. Error %d", GetLastError());
		getchar();
		return FALSE;
	}
	arry_hand[0] = hThread1;
	arry_hand[1] = hThread2;
	/*printf("enter the waiting condition\n");
	scanf_s("%ld", &bwaitall);
	getchar();
	printf("enter the timeout period\n");
	scanf_s("%ld", &dwMs);*/
	DWORD dw = WaitForMultipleObjects(2,arry_hand,bwaitall,dwMs);
	switch (dw)
	{
	case WAIT_OBJECT_0+0:
		printf("thread 1 is terminated\n");
		break;
	case WAIT_OBJECT_0+1:
		printf("thread 2 is terminated\n");
	case WAIT_TIMEOUT:
		printf("timeout expired\n");
		break;
	case WAIT_FAILED:
		printf("wait failed\n");
		break;
	}
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	printf("wiating to enter a character before exit\n");
	getchar();
	return 0;
}