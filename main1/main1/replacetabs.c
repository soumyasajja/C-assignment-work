#include<stdio.h>

void replace_tabs()
{

	FILE *fp1,*fp2;
	char ch1,ch2;

	
	fp1=fopen("hello4.txt","r");
	fp2=fopen("hello4out.txt","w");
	
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

		if(ch1=='\t')
		{
			ch2='\\';
			fputc(ch2,fp2);
			ch2='t';
			fputc(ch2,fp2);
			ch1=fgetc(fp1);
			
		}
		fputc(ch1,fp2);

	}

	printf("Replaced tabs with tab character\n");
	fclose(fp1);
	fclose(fp2);
	
	return;

}