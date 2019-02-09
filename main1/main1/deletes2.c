#include <stdio.h>
#include <string.h>
void deletes2(char *, char *);
int main()
{
	char s1[30], s2[30];
	printf("enter the strings\n");
	gets(s1);
	gets(s2);
	printf("the entered strings are:\n");
	puts(s1);
	puts(s2);
	deletes2(s1, s2);
                  return 0;
}
void deletes2(char *s1, char *s2)
{
	char str[30],ch;
	int i, j, k=0,n1,n2;
                  n1=strlen(s1);
                  n2=strlen(s2);
	for (j = 0;j<n2; j++)
	{
		for(i=0;i<n1;i++)
		{	
                                                      if (s2[j] ==  s1[i])
			{
				s1[i]=' ';
			}
	                   }
                }
	
	printf("the new string is %s", s1);
}