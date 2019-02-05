#include <stdio.h>
int main()
{
int i,j,k,l;
 	for(i=1;i<=5;i++)
	 {
		for(j=5;j>1;j--)
  		{
                                   printf(" ");
	                  }
	for(int l=i;l>=1;l--)
	{
		printf("%d",l);
	}
	for(int k=2;k<=i;k++)
 	{
		printf("%d",k);
	}
  printf("\n");
}
return 0;
}