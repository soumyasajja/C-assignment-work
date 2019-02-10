#include <stdio.h>
int invertponwards(n,p,b);
int main()
{
      int num,position,bits,invert;
      printf("enter the number:\n");
      scanf("%d",&num);
      printf("enter the position to start inversion of bits:\n");
      scanf("%d",&position);
      printf("enter the number of bits to invert:\n");
      scanf("%d",&bits);
      invert=invertponwards(num,position,bits);
      printf("the inversion result=%d\n",invert);
      return 0;
}
int invertponwards(int n,int p,int b)
{
      int m;
      m=1<<p;
      m=m|b;
      printf("%d\n",m);
      n=n^m;
      return n;
} 