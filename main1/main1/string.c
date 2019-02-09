#include <stdio.h>
#include <string.h>
int main()
{
     int i,j,r,c;
     printf("enter the number of rows and cols ");
     scanf("%d%d",&r,&c);
     char **s=NULL;
     **s=(char **)malloc(r*sizeof(char*));
     for(i=0;i<r;i++)
     {
           s=(char*)malloc(c*sizeof(char));
       }
      for(i=0;i<r;i++)
      {
           for(j=0;j<c;j++)
           {
                 gets(s);
            }
       }
       for(i=0;i<r;i++)
       {
           for(j=0;j<c;j++)
           {
                  printf("%s\n",s[i][j]);
             }
        }
}    
     
