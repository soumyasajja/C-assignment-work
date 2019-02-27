#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <stdlib.h>
#define BUFFSIZE 100
int _tmain(int argc, LPSTR argv[])
{
	HANDLE hFile;
	TCHAR buffer[]=TEXT("Hello from Windows Programming via C/C++");
	if (argc != 2)
	{
		_tprintf(_T("Usage fileopen.exe\n"));
		return FALSE;
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
		return FALSE;
	}
	_tprintf(_T("File opened successfully\n"), argv[1]);
	DWORD dwNbw;
	BOOL ret = WriteFile(hFile, buffer, sizeof(buffer), &dwNbw, NULL);
	if (ret == 0)
	{
		_tprintf(_T("Can't write file. Error(%d)"), GetLastError());
		getchar();
		return FALSE;
	}
	CloseHandle(hFile);
	getchar();
	return TRUE;
}