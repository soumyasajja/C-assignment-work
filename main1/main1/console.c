#include <stdio.h>
#include <stdlib.h>
int main()
{
     FILE *fp;
     char ch;
     fp=fopen("contents.txt","r");
     if(fp==NULL)
      {
           printf("cannot open file\n");
           return;
       }
       while(!feof(fp))
        {
             ch=fgetc(fp);
             printf("%c",ch);
        }
        return 0;
}