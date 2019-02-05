#include <stdio.h>
int fact(int);
int main()
{int n,factorial;
printf("enter the number");
scanf("%d",&n);
factorial=fact(n);
printf("factorial=%d",factorial);
}
int fact(int num)
{ if(num==0)
return 1;
 else
 return num*fact(num-1);
}