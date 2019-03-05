#include<windows.h>
#include<stdio.h>
#include<stdlib.h>


#define THREADCOUNT 10
HANDLE ghMutex;
DWORD WINAPI WriteToDatabase(LPVOID);

int main(void) {
	HANDLE aThread[THREADCOUNT];
	DWORD ThreadID;
	int i;

	ghMutex = CreateMutex(NULL, FALSE, NULL);

	if (ghMutex == NULL) {
		printf("CreateMutex error:%d\n", GetLastError());
		return 1;
	}


	for (i = 0; i < THREADCOUNT; i++) {
		aThread[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)WriteToDatabase, NULL, 0, &ThreadID);

		if (aThread[i] == NULL) {
			printf("CreateThread error %d\n", GetLastError());
			return 1;
		}
	}
	WaitForMultipleObjects(THREADCOUNT, aThread, TRUE, INFINITE);
	for (i = 0; i < THREADCOUNT; i++)
		CloseHandle(aThread[i]);
	CloseHandle(ghMutex);
	getchar();
	return 0;
}

DWORD WINAPI WriteToDatabase(LPVOID lpParam) {
	UNREFERENCED_PARAMETER(lpParam);
	DWORD dwWaitResult;
	BOOL dwCount = 0;

	while (dwCount < 5) {
		dwWaitResult = WaitForSingleObject(ghMutex, INFINITE);
		switch (dwWaitResult) {
		case WAIT_OBJECT_0:
			printf("Thread %d writing to database....\n", GetCurrentThreadId());
			dwCount++;
			if (!ReleaseMutex(ghMutex))
			{
				return FALSE;
			}
			break;
		case WAIT_ABANDONED:
			return FALSE;
		}
	}
	return TRUE;

}