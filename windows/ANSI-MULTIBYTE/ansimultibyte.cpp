#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <tchar.h>
void main()
{
	char ca1 = 'A';
	CHAR cA2 = 'P';
	wchar_t wca3 = L'P';
	WCHAR wca4 = L'L';
	TCHAR tc = TEXT('E');
	CHAR ArrANSI[] = "Soumya";
	WCHAR ArrWIDE[] = L"Sajja";
	printf("char: %c\n CHAR: %c\n wchar_t: %C\n WCHAR: %C\n TCHAR:%c\n ArrayANSI: %s\n ArrayWIDE : %S\n", ca1, cA2, wca3, wca4, tc, ArrANSI, ArrWIDE);
	BOOL ret = IsTextUnicode(
		ArrANSI, strlen(ArrANSI), NULL
	);
	if (1 == ret)
		printf("ArrANSI is a Unicode\n");
	else
		printf("ArrANSI is not a Unicode\n");
	BOOL ret1 = IsTextUnicode(
		ArrWIDE, wcslen(ArrWIDE), NULL
	);
	if (1 == ret1)
		printf("ArrWIDE is a Unicode\n");
	else
		printf("ArrWIDE is not a Unicode\n");
	int len1 = MultiByteToWideChar(CP_UTF8, 0, ArrANSI, -1, NULL, 0);
	if (len1 == 0)
		printf("Error has been occured i.e., %d\n", GetLastError());
	else
		printf("Length of ArrayANSI is: %d\n", len1);

	WCHAR *ANSITOWIDE = new WCHAR[len1];
	int len2 = MultiByteToWideChar(CP_UTF8, 0, ArrANSI, -1, ANSITOWIDE, len1);
	if (len2 == 0)
		printf("Error has been occured i.e., %d\n", GetLastError());
	else
		printf("Length of ArrayANSI is: %S\n", ANSITOWIDE);

	int len3 = WideCharToMultiByte(CP_UTF8, 0, ArrWIDE, -1, NULL, 0, NULL, NULL);
	if (len3 == 0)
		printf("Error has been occured i.e., %d\n", GetLastError());
	else
		printf("Length of ArrayWIDE is: %d\n", len3);

	CHAR *WIDETOANSI = new CHAR[len3];
	int len4 = WideCharToMultiByte(CP_UTF8, 0, ArrWIDE, -1, WIDETOANSI, len3, NULL, NULL);
	if (len4 == 0)
		printf("Error has been occured i.e., %d\n", GetLastError());
	else
		printf("Length of ArrayANSI is: %s\n", WIDETOANSI);

	delete(ANSITOWIDE);
	delete(WIDETOANSI);

	getchar();
}