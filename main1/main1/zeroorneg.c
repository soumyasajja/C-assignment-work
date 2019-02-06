#include <stdio.h>
int main()
{ int i,avg,max=0,min=0,count=1,sum=0;
   int *n;
   n=(int*)calloc(count,sizeof(int));
   for(i=1;i<=count;i++)
   {  
       scanf("%d",&n[i]);
       if(n[i]<=0)
         break;
       else
       count++;
}
for(i=1;i<=count-1;i++)
{
    printf("%d",n[i]);
    if(n[i]>max)
      max=n[i];
    if(n[i]<min)
      min=n[i];
    sum=sum+n[i];
    avg=sum/(count-1);
}
printf("max value is%d\t min val %d\t avg is %d\t",max,min,avg);
return 0;
}