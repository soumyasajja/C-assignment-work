#include<stdio.h>
#include<stdlib.h>

int main()
//void remove_comments()
{
	FILE *fp1,*fp2;
	char ch1;

	
	fp1=fopen("hello2.txt","r");
	fp2=fopen("hello2out.txt","w");
	
	if ( fp1 == NULL || fp2 == NULL )  
	{   
		printf( "Cannot open file\n" ) ;  
		return;
	}
	
	while(1)
	{
		ch1=fgetc(fp1);
			
		if(ch1==EOF)
		break;

		if(ch1=='/')
		{
			ch1=fgetc(fp1);
		
			if(ch1=='/')
			{
				while(ch1!='\n')
				{
					ch1=fgetc(fp1);	
										
				}
			}
			
			if(ch1=='*')	
			{
				ch1=fgetc(fp1);
				while(ch1!='*')
				{
					ch1=fgetc(fp1);
					if(ch1=='/')
					{
						ch1=fgetc(fp1);
						break;
					}
					
				}
			}
			
		}
		fputc(ch1,fp2);
	}

	printf("Comments replaced in new file hello2out.txt\n");
	fclose(fp1);
	fclose(fp2);
	return;

}