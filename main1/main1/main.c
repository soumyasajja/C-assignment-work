#include <stdio.h>
int add(int,int);
int sub(int,int);
long int mul(int,int);
int div(int,int);
int res=-1;
int main()
{int a=10,b=20;
res=add(a,b);
printf("addition=%d",res);
res=sub(a,b);
printf("subtraction=%d",res);
res=mul(a,b);
printf("multiplication=%d",res);
res=div(a,b);
printf("division=%d",res);
return 0;
}