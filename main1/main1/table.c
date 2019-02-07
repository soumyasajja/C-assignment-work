#include <stdio.h>
int main()
{
     float table[2][3]={{1.1,1.2,1.3},{2.1,2.2,2.3}};
     printf("the base address of the table is stored in table=%d\n",table);
     printf("the first row is pointed by (table+1)=%d\n",(table+1));
     printf("the first column of the first row is pointed by *(table+1)=%d\n",*(table+1));
     printf("the first element of the first coumn and first row is *(*(table+1)+1)=%f\n",*(*(table+1)+1));
     printf("the second element address of zeroth row is pointed by (*(table)+1)=%d\n", (*(table)+1));
     printf("the second element address of first row is pointed by (*(table+1)+1)=%d\n", (*(table+1)+1));
     printf("the second element of the first row is pointed by *(*(table+1)+1)=%f\n",*(*(table+1)+1));
     printf("the second element of the zeroth row is pointed by *(*(table)+1)=%f\n", *(*(table)+1));
     printf("the first element of the first row is given by *(*(table+1))=%f\n", *(*(table+1)));
     printf("the third element of the zeroth row is pointed by *(*(table)+1+1)=%f\n",*(*(table)+1+1));
     return 0;
}