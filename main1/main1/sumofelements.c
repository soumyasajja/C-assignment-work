#include <stdio.h>
int subarr(int [],int,int);
int main()
{
    int arr[50],n,sum,i;
    n=sizeof(arr)/sizeof(arr[0]);
    printf("enter the length of array\n");
    scanf("%d",&n);
    printf("enter the sum to be checked\n");
     scanf("%d",&sum);
    printf("enter the array elements\n");
    for(i=0;i<n;i++)
    {
         scanf("%d",&arr[i]);
     }
     printf("the array elements are\n");
     for(i=0;i<n;i++)
     {   
          printf("%d\t",arr[i]);
     }
       subarr(arr,n,sum);
       return 0;
}
int subarr(int arr[100] ,int n,int sum)
{
     int i,j,arr_sum;
     for(i=0;i<n;i++)
     {
            arr_sum=arr[i];
            for(j=i+1;j<=n;j++)
            {
                  if(arr_sum==sum)
                  {
                        printf("the sub array is found between indices %d and %d",i,j);
                        return 1;
                   }
                   if(arr_sum>sum||j==n)
                     break;
 
                         arr_sum=arr_sum+arr[j];
                     
             }
       
        }
       printf("no sub array found");
        return 0;
}