#include <stdio.h>
int main()
{
     char *colour[6]={"red","green","blue","white","black","yellow"};
     printf("the base address of array is pointed by colour=%d\n",colour);
     printf("the third element address is given by (colour+2)=%d\n",(colour+2));
     printf("the first element is given by *(colour)=%s\n",*(colour));
     printf("the third element is given by *(colour+2)=%s\n",*(colour+2));
     printf("colour[5]=%s and*(colour+5)= %s are same\n",colour[5],*(colour+5));
     return 0;
}