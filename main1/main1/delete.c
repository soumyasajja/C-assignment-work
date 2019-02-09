#include <stdio.h>
#include <string.h>
void delete(char *,char);
int main()
{
   char s[30],ch;
   printf("enter the string\n");
   gets(s);
   printf("enter the character to delete\n");
   scanf("%c",&ch);
   delete(s,ch);
}
void delete(char *s,char c)
{
    int i,j=0,size;
    char s1[30],ch;
    size=strlen(s);
    for(i=0;i<size;i++)
    {
         if(s[i]!=c)
         {
             ch=s[i];
             s1[j]=ch;
             j++;
          }
          }
            s1[j]='\0';
    
      printf("the new string=%s",s1);
}