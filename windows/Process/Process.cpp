#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#define NOOFPROCS 2
void _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO si1, si2;
	PROCESS_INFORMATION pi1, pi2;
	SECURITY_ATTRIBUTES sa;
	HANDLE hproc;
	ZeroMemory(&si1, sizeof(si1));
	ZeroMemory(&si2, sizeof(si2));
}