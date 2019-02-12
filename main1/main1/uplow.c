#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
     char str[100];
     int i;
     printf("enter the string\n");
     gets(str);
      FILE *fp;
     fp=fopen("upperlower.txt","w");
     if(fp==NULL)
      {
          printf("cannot open file");
          return;
       }
     for(i=0;i<strlen(str);i++)
     {
         if(str[i]>='A'&&str[i]<='Z')
         {
          str[i]=str[i]+32;
         }
         else if(str[i]>='a'&&str[i]<='z')
          {
           str[i]=str[i]-32;
          }
          fputc(str[i],fp);
       }
       fclose(fp);
       return 0;
   }








       
    
     