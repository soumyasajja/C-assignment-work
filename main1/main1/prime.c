#include <stdio.h>
int main()
{ int i,n,j;
   printf("enter the range");
   scanf("%d%d",&i,&n);
   for(i;i<n;i++)
   { 
        for(j=2;j<i;j++)
         {
              if(i%j==0)
              break;
               else if(i==j+1)
                 printf("%d\n",i);
            }
     }
  return 0;
}