#include <stdio.h>
#include <string.h>
void rotateString(char *str,int len);
int main()
{
     char str[30];
     int len;
     printf("enter the string\n");
     gets(str);
     len=strlen(str);
     rotateString(str,len);
     return 0;
}   
void rotateString(char *str,int len)
{
     int i,j,k;
     char temp[20];
     for(i=0;i<len;i++)
     {
            j=i;
            k=0;
            while(str[j]!='\0')
             {
                 temp[k]=str[j];
                 k++;
                 j++;
              }
             j=0;
             while(j<i)
             {
                  temp[k]=str[j];
                  j++;
                  k++;
              }
             printf("%s\n",temp);
          }
}