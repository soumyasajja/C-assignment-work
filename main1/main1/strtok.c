#include <stdio.h>
#include <string.h>
char *strtok1(char *str,const char *delim);
int main()
{
     char str[30];
     char s[2];
     char *token;
     printf("enter the string:\n");
     gets(str);
     printf("enter the delimiter character:\n");
     gets(s);
     token=strtok1(str,s);
     while(token!=NULL)
      {
           printf("%s\n",token);
            token=strtok1(NULL,s);
       }
     return 0;	
}
char *strtok1(char *str,const char *delim)
{
     char *token;
      if(*str!='\0')
        { while(*str!=*delim)
            { *token=*str;
               str++;
               token++;}
           }
}
     
        