#include <stdio.h>
#define print(s)  printf("token"#s"=%d",token##s)
#define Book(name,author) #name"is written by"#author
int main()
{
    int token9=100;
    #ifdef Book(name,author)
    printf("%s",Book(ANSI C,Swamy));
    print(9);
     printf("\n"); 
  #elif
    printf("bye\n");
   #endif
}