#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#define BUFFSIZE 100
int _tmain(int argc, LPSTR argv[])
{
	HANDLE hFile;
	TCHAR buffer[BUFFSIZE];
	if (argc != 2)
	{
		_tprintf(_T("Usage fileopen.exe\n"));
		return FALSE;
	}
	hFile = CreateFile(
		argv[1],
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File doesn't exist. Error(%d)\n"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("File (%s) opened successfully\n"), argv[1]);
	DWORD dwNbr;
	DWORD nBytesRead = BUFFSIZE;
	while (1)
	{
	ZeroMemory(buffer, BUFFSIZE);
	BOOL ret = ReadFile(hFile, buffer, BUFFSIZE, &dwNbr, NULL);
	if (ret == 0)
	{
		_tprintf(_T("Can't read file. error(%d)\n"), GetLastError());
		getchar();
		return FALSE;
	}
	if (ret&&nBytesRead == 0)
	{
		_tprintf(_T("Reached EOF\n"));
		break;
	}
	_tprintf(_T("%hS"), buffer);
	}
	//_tprintf(_T("Text from (%s): %S\n"), argv[1], buffer);
	CloseHandle(hFile);
	getchar();
	return TRUE;
}