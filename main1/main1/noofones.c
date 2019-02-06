#include <stdio.h>
int main()
{ 
    char x;
    int count=0;
    printf("enter the value of x");
    scanf("%c",&x);
    while(x)
    {
        count+=x&1;
        x=x>>1;
     }
     printf("the number of ones in %c  are %d",x,count);
     return 0;
}