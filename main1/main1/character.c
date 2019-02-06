#include <stdio.h>
int main()
{ 
     char text[80];
     int alpha=0,tabs=0,blanks=0,num=0,i=80;
     printf("enter the string\n");
     for(i=0;i<=79;i++)
     { 
        scanf("%c",&text[i]);
      }
     for(i=0;i<=79;i++)
     {
         if(text[i]>=48&&text[i]<=57)
         {
              num=num++;
          }
         else if(text[i]>=65&&text[i]<=90)
         {
             alpha=alpha++;
          }
         else if(text[i]>=97&&text[i]<=122)
         {
             alpha=alpha++;
          }
          else if(text[i]==32)
          { 
              blanks=blanks++;
           }
         else if(text[i]==92)
         {
             tabs=tabs++;
         }
       }
return 0;
}
             