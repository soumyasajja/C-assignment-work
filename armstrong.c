
#include<stdio.h>
#include<math.h>
int main()
{int number, original_num,remainder,result=0,n=0;
printf("enter the number\n");
scanf("%d",&number);
original_num=number;
while(original_num!=0)
{original_num/=10;
++n;}
original_num=number;
while(original_num!=0)
{remainder=original_num%10;
result+=pow(remainder,n);
original_num=original_num/10;
}
if(result==number)
{printf("%d is an Armstrong number",number);
}
else
printf("%d is not an armstrong number",number);
return 0;
}