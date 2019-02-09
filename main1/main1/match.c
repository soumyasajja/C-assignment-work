#include <stdio.h>
#include <string.h>
int match(char *,char *);
int main()
{
   char s1[30];
   char s2[30];
   int index;  
   printf("enter the strings\n");
   gets(s1);
   gets(s2);
   index=match(s1,s2);
   printf("the strings s1 and s2 match at index=%d",index);
}
int match(char *s1,char *s2)
{
   int i,j;
   for(i=0;s1[i]!='\0';i++)
   {
        for(j=0;s2[j]!='\0';j++)
        {
            if(s1[i]==s2[j])
            {
                 return j;
             }
          }
     }
}
  