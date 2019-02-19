#include <stdio.h>
#include <string.h>
#include "countchar.c"
#include "removecomm.c"
#include "rotatematch.c"
#include "replacetabs.c"
int main()
{
        int option;
        printf("menu based code to execute the following tasks:\n");
        printf("1) counting characters, 2) remove comments 3) rotate matching word 4) replace tabs\n");
        printf("enter the option:\n");
        scanf("%d",&option);
        // switch case for menu options
        switch(option)
        {
               case 0:
                           countchar();
                           break;
                case 1:
                            removecomm();
                            break;
                case 2:
                            rotatematch();
                            break;
                case 3:
                            replacetabs();
                            break;
         }
         return 0;
}