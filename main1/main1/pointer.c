#include <stdio.h>
int main()
{
    int x[8]={10,20,30,40,50,60,70,80};
    int *ptr;
    ptr=x;
    printf("Program to understand pointer notation");
    printf("the base address of array is stored x=%d\n",ptr);
    printf("the address of the second element is stored in (x+2)=%d\n",(ptr+2));
    printf("the first element is given by *x=%d\n",*ptr);
    printf("the first element is appended by 2 using (*x +2)=%d\n",(*ptr+2));
    printf("the third element in he array is given by *(x+2)=%d\n",*(ptr+2));
    return 0;
}