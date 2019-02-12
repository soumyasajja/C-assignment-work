#include<stdio.h>
#include<stdlib.h>

void count_contents()
{
	FILE *fp;
	char ch;

	int alphas=0,digits=0,spaces=0,tabline=0,special=0;
	
	fp=fopen("hello1.txt","r");
	if ( fp == NULL )  
	{   
		printf( "Cannot open file\n" ) ;  
		return;
	}
	
	while(1)
	{
		ch=fgetc(fp);
		
		if(ch==EOF)
		break;

		if(ch>='A'&& ch <='Z' || ch>='a' && ch<='z')
			alphas++;
		else
			if(ch>='0' && ch<='9')
				digits++;
			else
				if(ch==' ')
					spaces++;
				else
					if(ch=='\n'||ch=='\t')
						tabline++;
					else
						special++;
		//fp++;
	}

	fclose(fp);

	printf("\nNumber of Aplhabets:%d\n",alphas);
	printf("Number of Digits: %d\n",digits);
	printf("Number of Spaces: %d\n", spaces);
	printf("Number of Tabs or New Lines: %d\n",tabline);
	printf("Number of Special Characters: %d\n",special);
	
	return;
}

// use fopen_s in visual studio. 3 args. first arg if file ptr;