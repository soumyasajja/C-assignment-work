#include <stdio.h>
int replace(char *);
int main()
{
      char *cat="The cat sat";
      int n;
      n=replace(cat);
      printf("the value of n=%d",n);
      return 0;
}
int replace(char *cat)
{
     int i,n=0;
     for(i=0;cat[i]!='\0';i++)
     {
         if(cat[i]==' ')
         {
             n=n+1;
             cat[i]='-';
           }
        }
        
       printf("the new string is=%s\n",cat);
      
       return n;
}