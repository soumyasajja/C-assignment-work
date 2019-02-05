#include <stdio.h>
#include <math.h>
int BToD(long long n);
long long DToB(int n);
int main()
{  
     int dec;
     long long bin;
     printf("enter a binary number");
     scanf("%lld",&bin);
     printf("enter a decimal number");
     scanf("%d",&dec);
     printf("the value of %lld =%d in decimal",bin,BToD(bin));
     printf("the value of %d=%lld in binary",dec,DToB(dec));
}
int BToD(long long n)
{ int rem,dec=0,i=0;
   while(n!=0)
  { rem=n%10; 
     n/=10;
     dec+=rem*pow(2,i); 
     ++i;
    }
   return dec;
}
long long DToB(int n)
{ int rem,i=1;
   long long bin=0;
   while(n!=0)
   {rem=n%2;
      n/=2;
      bin+=rem*i;
      i*=10;
     }
    return bin;
}