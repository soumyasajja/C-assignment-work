#include<stdio.h>
int main()
{int num,original_num,result=0,remainder;
printf("enter the number");
scanf("%d",&num);
original_num=num;
while(original_num!=0)
{remainder=original_num%10;
result+=remainder;
original_num/=10;
}
printf("%d is the sum of the digits in the number",result);
return 0;
}