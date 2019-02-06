#include <stdio.h>
int main()
{
          int num,ones_comp,mask,shift,mask_ip,shift_n,i,j,shift_ip;
          printf("enter the number");
          scanf("%x",&num);
          printf("Menu:1. ones complement 2.masking operation 3. bit shifting 4.exit\n");
          scanf("%d",&i);
         switch(i)
                     {
                        case 1:
                                     ones_comp=~num;
                                         printf("the one's complement of %x is %x\n",num,ones_comp);
                                         break;
                                     
                       case 2:
                                       printf("enter the type of operation 1. bitwise and 2. bitwise or 3.bitwise xor\n");
                                         scanf("%d",&j);
                                         printf("enter the value to be masked with\n");
                                         scanf("%x",&mask_ip);
                                         switch(j)
                                                     {
                                                             case 1:
                                                                      mask=mask_ip&num;
                                                                        printf("the and masked value is %x\n",mask);
                                                                        break;
                                                                      
                                                            case 2:
                                                                       mask=mask_ip|num;
                                                                         printf("the or masked value is %x\n",mask);
                                                                         break;
                                                                      
                                                           case 3:
                                                                      mask=mask_ip^num;
                                                                        printf("the xor masked value is %x\n",mask); 
                                                                        break;
                                                                     
                                                   };
                                   break;
                    case 3:
                                
                                   printf("enter the type of operation to be performed 1.right shift 2.left shift\n");
                                   scanf("%d",&shift_ip);
                                   printf("enter the no.of bits to shift\n");
                                   scanf("%d",&shift_n);
                                   switch(shift_ip)
                                                         {
                                                                case 1:
                                                                          
                                                                             shift=num>>shift_n;
                                                                             printf("the right shift is %x\n",shift); 
                                                                             break;
                                                                          
                                                                case 2:
                                                                         
                                                                            shift=num<<shift_n;
                                                                            printf("the left shift is %x\n",shift);
                                                                            break;
                                                                            
                                                         };
                               
                   case 4:
                               break;
};
return 0;
} 
   

                          