#include <stdio.h>
int main()
{   int i,j,temp,input[9];
     printf("enter the array elements");
     for(i=0;i<9;i++)
     {
          scanf("%d",&input[i]);
      }
     for(i=0;i<9;i++)
     {     
           j=i;
            if(input[i]<0)
             {  
                 while(j-1>=0&&input[j-1]>0)  
                  { 
                       temp=input[j];
                       input[j]=input[j-1];
                       input[j-1]=temp;
                       j--;
                   }
              }
       }    
     for(i=0;i<9;i++)
      {
             printf("%d\n",input[i]);
       }
   return 0;
}