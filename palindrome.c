#include<stdio.h>
int main()
{int num,original_num,reverse_num=0,remainder;
printf("enter the number");
scanf("%d",&num);
original_num=num;
while(original_num!=0)
{remainder=original_num%10;
reverse_num=reverse_num*10+remainder;
original_num/=10;
}
if(num==reverse_num)
{printf("%d is a palindrome",num);
}
else
printf("%d is not a palindrome",num);
return 0;
}