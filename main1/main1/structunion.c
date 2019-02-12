#include <stdio.h>
int main()
{
    struct book{
                int x;
                char y;
                      }b1;
    union book1{
                int z;
                char w;
                         }u1;
     int len1,len2;
     len1=sizeof(b1);
     len2=sizeof(u1);
     printf("the structure size is =%d\n",len1);
     printf("the union size is=%d\n",len2);
     return 0;
}