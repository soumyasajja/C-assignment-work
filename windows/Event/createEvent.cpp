#include <Windows.h>
#include <stdio.h>
int main()
{
	HANDLE g_hEvent = CreateEvent(NULL, FALSE, FALSE, TEXT("namedevent"));
	getchar();
	return 1;
}