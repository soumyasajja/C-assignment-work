#include <stdio.h>
int main()
{
   int basic_sal;
   float gross_sal=0;
   printf("enter the basic salary");
   scanf("%d",&basic_sal);
   if(basic_sal>=1&&basic_sal<=4000)
   { 
     gross_sal=basic_sal+0.1*basic_sal+0.5*basic_sal;
     printf("%f is the gross salary",gross_sal);
   }
   else if(basic_sal>=4001&&basic_sal<=8000)
   {  
     gross_sal=basic_sal+0.2*basic_sal+0.6*basic_sal;
     printf("%f is the gross salary",gross_sal);
   }
   else if(basic_sal>=8001&&basic_sal<=12000) 
   {
     gross_sal=basic_sal+0.25*basic_sal+0.7*basic_sal;
     printf("%f is the gross salary",gross_sal);
   }
   else if(basic_sal>12000)
   { 
     gross_sal=basic_sal+0.3*basic_sal+0.8*basic_sal;
     printf("%f is the gross salary",gross_sal);
   }
    return 0;
}









