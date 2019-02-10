#include <stdio.h>
#include <string.h>
void expand( char *,char *);
int main()
{
      char s1[20],s2[60];
      printf("enter the shorthand string:\n");
      gets(s1);
      printf("the entered string is:\n");
      puts(s1);
      expand(s1,s2);
      
      return 0;
}
void expand(char *s1,char *s2)
{
       int i=0,j=0,c;
       while((c=s1[i++])!='\0')
        if(s1[i]=='-'&&s1[i+1]>=c)
           {
                   i++;
                   while(c<s1[i])
                    s2[j++]=c++;
             }
            else 
                 s2[j++]=c;
                s2[j]='\0';
  printf("the expanded string=%s",s2);      
}