#include <stdio.h>
#include <math.h>
int intToBin(int,long long);
int intToHex(int,int);
int main()
{
    int num;
    printf("enter the number");
    scanf("%d",&num);
    printf("the value of %d in binary is %lld ",num,intToBin())