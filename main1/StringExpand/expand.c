#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_SHORT_HAND 20
#define MAX_EXPANDED 100
void expand(char s1[], char s2[]);
int valid_range(char, char);
int main()
{
	char *str1, *str2;
	str1 = NULL;
	str1 = (char*)malloc(MAX_SHORT_HAND * sizeof(char));
	str2 = NULL;
	str2 = (char*)malloc(MAX_EXPANDED * sizeof(char));
	printf("enter the shorthand string:\n");
	gets(str1);
	printf("the entered string is:\n");
	puts(str1);
	expand(str1, str2);
	printf("%s\n", str2);
	system("pause");
	getchar();
	free(str1);
	free(str2);
	return EXIT_SUCCESS;
}
int valid_range(char ch1, char ch2)
{
	if (('a' <= ch1 && ch1 <= 'z') && (ch1 <= ch2 && ch2 <= 'z'))
		return 1;
	else if (('A' <= ch1 && ch1 <= 'Z') && (ch1 <= ch2 && ch2 <= 'Z'))
		return 1;
	else if (('0' <= ch1 && ch1 <= '9') && (ch1 <= ch2 && ch2 <= '9'))
		return 1;
	return 0;
}
void expand(char s1[], char s2[])
{
	int out_loop=0, in_loop = 0;
	char ch;
	while ((ch = s1[out_loop++]) != '\0')
	{ 
		if (s1[out_loop] == '-')
		{
			if (s1[out_loop + 1] == '-')
			{
				printf("not a valid user input\n");
				break;
			}
			else if(s1[out_loop + 1] >= ch)
			{
				if (valid_range(s1[out_loop-1],s1[out_loop+1]))
				{ 
			        out_loop++;
			        while (ch < s1[out_loop])
				    s2[in_loop++] = ch++;
				}
				else
				{
					printf("not a valid range\n");
					break;
				}
			}
		}
		else
			s2[in_loop++] = ch;
	}
	s2[in_loop] = '\0';
}