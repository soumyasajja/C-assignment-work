#include<stdio.h>
void checkOnes(int);
void reversebyte(int);
void rotate(int);
int main()
{ int val=0xCAFE;
  checkOnes(val);
  reversebyte(val);
  rotate(val);
  return 0;
  }
  void checkOnes(int value)
  {
  
  	int and1;
 	 and1=(0x000F)&value;
 	 if(and1 == 0x7 || and1 == 0xB || and1 == 0xD || and1 == 0xE || and1 == 0xF)
      printf("atleast three bits are on\n");
	  else
	  	 printf("atleast three bits are off\n");  	
   	 
  }
 void reversebyte(int value)
  {
  		
		int rev1,rev2,rev;
		rev1=value&0x00FE;
        rev2=value&0xCA00;
        rev1=rev1<<8;
		rev2=rev2>>8;
		rev=rev1|rev2;
		printf("%x\n",rev);
  }
  void rotate(int value)
  { int value1,value2;
  value1=value&0x000F;
 value1=value1<<16;
 value1=value1>>4;
  value2=value>>4;
  value2=value1|value2;
  printf("%x\n",value2);
  }
