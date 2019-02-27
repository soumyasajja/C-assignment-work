#include <stdio.h>
#include<Windows.h>
#include<tchar.h>
int _tmain(int argc,TCHAR *argv[])
{
	LPWSTR *szArglst;
	int nArgs=argc;
	szArglst = CommandLineToArgvW(GetCommandLineW(), &nArgs);
	if (NULL == szArglst)
	{
		wprintf(L"Command line is empty");
		return 0;
	}
	else
	{
		for (int i = 0; i < nArgs; i++)
		{
			printf("%d : %hS", i, argv[i]);
			printf("\n");
		}
	}
	getchar();
	return 0;
}