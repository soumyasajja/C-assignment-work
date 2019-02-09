#include <stdio.h>
#include <string.h>
char *strcat1(char *dest,const char *source);
int main()
{
     char s1[60],s2[20];
     printf("enter the strings\n");
     gets(s1);
     gets(s2);
     printf("the strings are:\n");
     puts(s1);
     puts(s2);
     strcat1(s1,s2);
     printf("the concatenated string is %s",s1);
     return 0;
}
char *strcat1(char *dest,const char *source)
{
     while(*dest!='\0')
      {
             dest++;
           while((*dest=*source)!='\0')
            {
                     dest++;
                      source++;
             }
         }
       return dest;
}
     
            
          