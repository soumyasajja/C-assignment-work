#include <stdio.h>
#include <string.h>
int strcmp1(const char *str1,const char *str2);
int main()
{
     char str1[30],str2[30];
     int res;
     printf("enter the strings:\n");
     gets(str1);
     gets(str2);
     printf("the strings are:\n");
     puts(str1);
     puts(str2);
     res=strcmp(str1,str2);
     printf("res=%d",res);
}
int strcmp1(const char *str1,const char *str2)
{ 
      while(*str1==*str2)
       {
            if(*str1=='\0')
            return 0;
            str1++;
            str2++;
         }
       return (*str1-*str2);
}