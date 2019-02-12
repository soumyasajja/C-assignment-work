#include <stdio.h>
#include <string.h>
int validtime(int hr,int min, int sec);
int main()
{
   struct time
   {
       char str[100];
       int ret,hr,min,sec;
    };
    struct  time t1,t2,t3;
   printf("enter the time in HH:MM:SS format\n");
   gets(t1.str);
   scanf(t1.str,"%d:%d:%d",&t1.hr,&t1.min,&t1.sec);
   t1.ret=validtime(t1.hr,t1.min,t1.sec);
   if(t1.ret)
   {
     printf("invalid time\n");
   }
   else
  {
    printf("the time is: %d:%d:%d\n",t1.hr,t1.min,t1.sec);
   }
   return 0;
}
int validtime(int hr,int min,int sec)
{
    int ret=0;
    if(hr>24) ret=1;
    if(min>60) ret=1;
    if(sec>60) ret=1;
    return ret;
} 