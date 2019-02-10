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
     static int pos;
     static char *s;
     int i=0,j,start=pos;
     if(str!=NULL)
     s=str;
     i=0;
     j=0;
     while(s[pos]!='\0')
      {
               j=0;
               while(delim[j]!='\0')
                  {
                      if(s[pos]==delim[j])
                       {
                           s[pos]='\0';
                           pos=pos+1;
                           if(s[start]!='\0')
                                return(&s[start]);
                              else
                               {
                                     start=pos;
                                     pos--;
                                     break;
                                }
                         }
                         j++;
                     }
                    pos++;
            }
            s[pos]='\0';
            if(s[start]=='\0')
                return NULL;
             else
                 return &s[start];
}
     
        