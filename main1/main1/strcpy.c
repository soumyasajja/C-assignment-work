#include <stdio.h>
#include <string.h>
char *strcpy1(char *s2,const char *s1);
int main()
{
      char str1[30],str2[30];
      printf("enter the strings:\n");
      gets(str1);
      gets(str2);
      printf("the entered strings are:\n");
      puts(str1);
      puts(str2);
      strcpy1(str1,str2);
      printf("the new string str1=%s",str1);
}
char *strcpy1(char *s2,const char *s1)
{
      while((*s2=*s1)!='\0')
       {
          s1++;
          s2++;
         }
       return  s2;
}
             