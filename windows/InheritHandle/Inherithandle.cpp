#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#include <stdlib.h>
#define BUFFSIZE 100
void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO si1, si2;
	PROCESS_INFORMATION pi1, pi2;
	SECURITY_ATTRIBUTES sa;
	HANDLE hFile;
	TCHAR buffer[] = TEXT("Hello from Windows Programming via C/C++");
	ZeroMemory(&si1, sizeof(si1));
	ZeroMemory(&si2, sizeof(si2));
	si1.cb = sizeof(si1);
	si2.cb = sizeof(si2);
	ZeroMemory(&pi1, sizeof(pi1));
	ZeroMemory(&pi2, sizeof(pi2));
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	if (argc != 3)
	{
		printf("Usage\n");
		getchar();
		return;
	}
	hFile = CreateFile(
		argv[1],
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File doesn't exist. Error(%d)\n"), GetLastError());
		getchar();
		return;
	}
	_tprintf(_T("File opened successfully\n"), argv[1]);
	DWORD dwNbw;
	BOOL ret = WriteFile(hFile, buffer, sizeof(buffer), &dwNbw, NULL);
	if (ret == 0)
	{
		_tprintf(_T("Can't write file. Error(%d)"), GetLastError());
		getchar();
		return;
	}
	if (!CreateProcess(NULL, argv[2], NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1))
	{
		printf("Create Process error (%d)\n", GetLastError());
		getchar();
		return;
	}
	printf("Handle of the process:%d\n", pi1.hProcess);
	printf("Process ID of proces:%d\n", pi1.dwProcessId);
	printf("Process thread of process:%d", pi1.dwThreadId);
	printf("process id of first process is %ld\n", GetProcessId(pi1.hProcess));
	printf("thread id of first process is %ld\n", GetThreadId(pi1.hThread));
	printf("Handle of first process is %ld \n", pi1.hProcess);
	CloseHandle(hFile);
	CloseHandle(pi1.hThread);
	CloseHandle(pi1.hProcess);
}