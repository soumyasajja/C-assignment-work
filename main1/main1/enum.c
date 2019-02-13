#include <stdio.h>
void add(float r1,float i1,float r2,float i2);
void sub(float r1,float i1,float r2,float i2);
void mul(float r1,float i1,float r2,float i2);
void div(float r1,float i1,float r2,float i2);
enum menu{addn,
          subn,
          muln,
          divn};
int main()
{
     enum menu op;
     float r1,i1,r2,i2;
     printf("enter the real and imaginary val of 1st num\n");
     scanf("%f%f",&r1,&i1);
     printf("enter the real and imaginary val of 2nd num\n");
     scanf("%f%f",&r2,&i2);
     printf("enter options 0)addn 1)subt 2)mult 3)divn\n");
     scanf("%d",op);
     switch(op)
     {
        case addn:
		{add(r1, i1, r2, i2);
		break; }
        case subn:
		{sub(r1, i1, r2, i2);
		break; }
        case muln:
		{mul(r1, i1, r2, i2);
		break; }
        case divn:
		{div(r1, i1, r2, i2);
		break; }
      }
      return 0;
}
void add(float r1,float i1,float r2,float i2)
{
     float real,img;
     real=r1+r2;
     img=i1+i2;
     printf("%f+%fi",real,img);
}
void sub(float r1,float i1,float r2,float i2)
{
     float real,img;
     real=r1-r2;
     img=i1-i2;
     printf("%f+%fi",real,img);   
}
void mul(float r1,float i1,float r2,float i2)
{ 
      double real,img;
      real=r1*r2-i1*i2;
      img=r1*i2+r2*i1;
      printf("%lf+%lfi",real,img);
}
void div(float r1,float i1,float r2,float i2)
{     float x,y,z;
      if(r2==0&&i2==0)
       printf("division of 0+i0 is not allowed\n");
      else 
      {
              x=r1*r2+i1*i2;
              y=i1*r2-r1*i2;
              z=r2*r2+i2*i2;
              printf("%f+%fi",x/z,y/z);
      }
}