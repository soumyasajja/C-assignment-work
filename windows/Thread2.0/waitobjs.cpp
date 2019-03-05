#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <stdlib.h>
DWORD WINAPI thread_func(LPVOID lparam)
{

	Sleep(2000);
	return 1;
}
int main()
{
		DWORD dwThreadId1;
		DWORD dwMs;
		HANDLE hThread1;
		hThread1 = CreateThread(
			NULL, 0, thread_func, 0, NULL, &dwThreadId1
		);
		if (NULL == hThread1)
		{
			printf("Unable to thread. Error %d", GetLastError());
			getchar();
			return FALSE;
		}
		printf("enter the timeout period\n");
		scanf_s("%ld", &dwMs);
		DWORD dw = WaitForSingleObject(hThread1, dwMs);
		switch (dw)
		{
		case WAIT_OBJECT_0:
			printf("thread is terminated\n");
			break;
		case WAIT_TIMEOUT:
			printf("timeout expired\n");
			break;
		case WAIT_FAILED:
			printf("wait failed\n");
			break;
		}
		CloseHandle(hThread1);
		printf("wiating to enter a character before exit\n");
		getchar();
		return 0;
}