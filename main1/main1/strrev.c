#include <stdio.h>
#include <string.h>
char *strrev1(char *str);
int main()
{
      char str[30]; 
      printf("enter the string\n");
      gets(str);
      printf("the entered string is:\n");
      puts(str);
      strrev1(str);
      printf("the reversed string is=%s",str);
}
char *strrev1(char *str)
{
      char *p1,*p2,temp;
      for(p1=str,p2=str+strlen(str)-1;p1<p2;p1++,p2--)
      {
            temp=*p1;
            *p1=*p2;
            *p2=temp;
         }
       return p1;
}    