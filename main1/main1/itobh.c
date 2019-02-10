#include <stdio.h>
#include <math.h>
void itob(int,char *);
void itoh(int,char *);
int main()
{
      int num;
      char bin[100],hex[100];
      printf("enter the integer value\n");
      scanf("%d",&num);
      itob(num,bin);
      itoh(num,hex);
      return 0;
}
void itob(int num,char *bin)
{
	int i = 0, j;
	while (num > 0)
	{
		bin[i] = num % 2;
		i++;
		num = num / 2;
	}
	for (j = i - 1; j >= 0; j--)
		printf("%c", bin[j]);
}
void itoh(int num, char *hex)
{
	int i = 0, j,rem;
	while (num != 0)
	{
	    rem = 0;
		rem = num % 16;
		if (rem < 10)
		{
			hex[i] = rem + 48;
			i++;
		}
		else
		{
			hex[i] = rem + 55;
			i++;
		}
		num /= 16;
	}
	for (j = i - 1; j >= 0; j--)
		printf("%c", hex[j]);
}
