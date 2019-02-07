#include <stdio.h>
#include <string.h>
int main()
{ 
     char s[30];
     int i;
     printf("enter the string\n");
     gets(s);
     for(i=0;i<20;i++)
     {
          if(s[i]>='a'&&s[i]<='z')
          {
                s[i]=s[i]-32;
           }
          else if(s[i]=='A'&&s[i]<='Z')
          {
                s[i]=s[i]+32;
          }
          else if(s[i]==' ')
          {
                s[i]=s[i];
           }
      }
      printf("the modified array is=%s",s);
}