#include <stdio.h>
#include <string.h>
void reverseString(char *,int,int);
int main()
{ char s[20];
   printf("enter the string\n");
   scanf("%[^\n]s",s);
   reverseString(s,0,strlen(s)-1);
}
void reverseString(char *arr,int begin,int end)
{
    char temp;
    if(begin>=end)
    {  
          printf("the reversed string is %s",arr);
          return;
     }
    else 
    { 
        temp=arr[begin];
        arr[begin]=arr[end];
        arr[end]=temp;
        reverseString(arr,++begin,--end);
     }
}

               