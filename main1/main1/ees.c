#include <stdio.h>
int main()
{
    int count=0,i,j;
    char *s[]={ 
                        "we will teach you how to",
                         "Move a mountain",
                         "Level a building",
                          "Erase the past",
                           "Make a million",
                      };
    
    for(i=0;i<5;i++)
    {
        char *a=*(s+i);
        for(j=0;a[j]!='\0';j++)
        {
             if(a[j]=='e')
              count++;
           }
      }
      printf("the number of e's =%d",count);
     return 0;
}
    