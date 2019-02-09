#include <stdio.h>
#include <string.h>
int main()
{
	int i, j,n,len;
	char *s[60];
	char name[20],temp[30];
	printf("enter the number of rows\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", &name[i]);
		len = strlen(name[i]);
		s[i] = (char*)malloc(len * sizeof(char));
		if (s[i] == NULL)
		{
			free(s[i]);
		}
		strcpy(*(s + i), name);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j<n-i-1; j++)
		{
			if ((strcmp(s[j], s[j + 1])) > 0)
			{
				strcpy(temp[j], s[j]);
					strcpy(s[j], s[j + 1]);
					strcpy(s[j + 1], temp);
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		
			printf("%s\n", s[i]);
	
	}
}
