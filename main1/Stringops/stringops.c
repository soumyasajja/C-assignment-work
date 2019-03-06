#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH_STRING 30
char *strcopy(char *str1, const char *str2)
{
	char *dst = str1;
	const char *src = str2;
	while ((*dst++ = *src++) != '\0')
		;
	return dst;
}
char *strconcat(char *str1, const char *str2)
{
	char *st = str1;
	while (*st != '\0')
		st++;
	strcopy(st, str2);
	return str1;
}
int strlength(const char *str)
{
	const char *pstr = str;
	while (*pstr != '\0')
		pstr++;
	return (pstr - str);
}
int strcomp(const char *str1, const char *str2)
{
	unsigned char uc1, uc2;
	while (*str1 != '\0' && *str1 == *str2) {
		str1++;
		str2++;
	}
	uc1 = (*(unsigned char *)str1);
	uc2 = (*(unsigned char *)str2);
	return ((uc1 < uc2) ? -1 : (uc1 > uc2));
}
char *strrevv(char *str)
{
	char *pstr1, *pstr2, temp;
	for (pstr1 = str, pstr2 = str + strlen(str) - 1; pstr2 > pstr1; ++pstr1, --pstr2)
	{
		temp = *pstr1;
		*pstr1 = *pstr2;
		*pstr2 = temp;
	}
	return str;
}

int main()
{
	char *str1, *str2;
	char storage[50] = "";
	int num = 0;
	str1 = NULL;
	str1 = (char*)malloc(MAX_LENGTH_STRING * sizeof(char));
	str2 = NULL;
	str2 = (char*)malloc(MAX_LENGTH_STRING * sizeof(char));
	printf("enter the strings:\n");
	gets(str1);
	gets(str2);
	printf("the entered strings are\n");
	puts(str1);
	puts(str2);

	while (num <= 5)
	{
		printf("1.Length\n2.Copy\n3.Concatenate\n4.Comparison\n5.Reversal\n");
		scanf_s("%d", &num);
		char temp[30];
		int res;
		switch (num)
		{
		case 1:
			printf("length of first string is %d\n", strlength(str1));
			printf("length of second string is %d\n", strlength(str2));
			break;
		case 2:
			strcopy(temp, str2);
			printf("The string is copied  %s,%s\n", temp, str2);
			break;
		case 3:
			strconcat(str1, str2);
			printf("the concatenated string is = %s\n", str1);
			break;
		case 4:
			res = strcomp(str1, str2);
			if (res <= -1)
			{
				printf("first string is lexographically less than the second\n");
			}
			else if (res >= 1)
			{
				printf("second string is lexographically less than the first\n");
			}
			else if (res == 0)
			{
				printf("equal\n");
			}

			break;
		case 5:
			printf("reversal of first string is %s\n", strrevv(str1));
			break;

		}
		getchar();
	}
	free(str1);
	free(str2);
}