#include <stdio.h>
#define INT_BITS 32
int rotateByb(int,unsigned int);
int main()
{ 
   int n,res;
   unsigned int d;
   printf("enter the number and the number of positions to shift");
   scanf("%d%u",&n,&d);
   res=rotateByb(n,d);
   printf("%d is th number %d shifted by %d bits",res,n,d);
}
int rotateByb(int n,unsigned int d)
{ 
    return (n >> d)|(n << (INT_BITS - d));
}