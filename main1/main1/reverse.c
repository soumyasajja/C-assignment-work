#include <stdio.h>
int main()
{ int num,original_num,revnum=0,rem;
   printf("enter the number");
   scanf("%d",&num);
   original_num=num;

    while(original_num!=0)
    { rem=original_num%10;
       revnum=revnum*10+rem;
       original_num/=10;
     }
    printf("the reverse of %d is %d",num,revnum);
    return 0;
}