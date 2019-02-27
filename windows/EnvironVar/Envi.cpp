#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <stdlib.h>
void DumpEnvStrings(PTSTR pEnvBlock[]);
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	DumpEnvStrings(env);
	TCHAR envString0[] = TEXT("%SystemRoot%");
	TCHAR envString1[] = TEXT("%windir%");
	TCHAR envString2[] = TEXT("%user%");
	TCHAR buffer[MAX_PATH];
	DWORD ret;
	ret = ExpandEnvironmentStrings(envString0, buffer, MAX_PATH);
	if (!ret)
	{
		printf("%d\n", GetLastError());
		getchar();
		return 0;
	}
	else
		printf("%hS\n", buffer);
	ret = ExpandEnvironmentStrings(envString1, buffer, MAX_PATH);
	if (!ret)
	{
		printf("%d\n", GetLastError());
		getchar();
		return 0;
	}
	else
		printf("%hS\n", buffer);
	ret = ExpandEnvironmentStrings(envString2, buffer, MAX_PATH);
	if (!ret)
	{
		printf("%d\n", GetLastError());
		getchar();
		return 0;
	}
	else
		printf("%hS\n", buffer);
}
void DumpEnvStrings(PTSTR pEnvBlock[])
{
	int curr = 0;
	PTSTR *pele = (PTSTR *)pEnvBlock;
	PTSTR pCurrent = NULL;
	while (pele != NULL)
	{
		pCurrent = (PTSTR)(*pele);
		if (pCurrent == NULL)
		{
			pele = NULL;
		}
		else
		{
			_tprintf(TEXT("[%u]%s\r\n"), curr, pCurrent);
			curr++;
			pele++;
		}
	}
}