#include <stdio.h>
int main()
{
  int a,x0,x1,x2,x3;
  printf("enter the number");
  scanf("%d",&a);
  if(a<0||a>32)
  printf("out of range\n");
  else
  printf("in range");
  x0=a%2;
 a=a/2;
 if(a!=0)
 {x1=a%2;
  a=a/2;}
 else
 printf("binary eq=%d",x0);
 if(a!=0)
 { x2=a%2;
 a=a/2;}
 else
 printf("binary eq=%d%d",x1,x0);
 if(a!=0)
 {x3=a%2;
 a=a/2;}
else
 printf("binary eq=%d%d%d",x2,x1,x0);
printf("%d%d%d%d",x3,x2,x1,x0);
}