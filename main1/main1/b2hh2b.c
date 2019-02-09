#include <stdio.h>
int binToHex(long long);
void hexToBin(char*);
int main()
{
	long long bin;
	char hex[15];
	printf("enter the binary value\n");
	scanf("%lld", &bin);
	printf("enter the hexadecimal value\n");
	scanf("%s", &hex);
	printf("the value of %lld in hexadecimal is %x\n", bin, binToHex(bin));
    hexToBin(hex);
}
int binToHex(long long binary)
{
	int  i = 1, rem, hexa = 0;
	while (binary != 0)
	{
		rem = binary % 10;
		hexa = hexa + rem * i;
		i = i * 2;
		binary /= 10;
	}
	return hexa;
}
void hexToBin(char *hex)
{
	long int i = 0;
	while (hex[i])
	{
		switch (hex[i])
		{
		case '0':
			printf("0000");
			break;
		case '1':
			printf("0001");
			break;
		case '2':
			printf("0010");
			break;
		case '3':
			printf("0011");
			break;
		case '4':
			printf("0100");
			break;
		case '5':
			printf("0101");
			break;
		case '6':
			printf("0110");
			break;
		case '7':
			printf("0111");
			break;
		case '8':
			printf("1000");
			break;
		case '9':
			printf("1001");
			break;
		case 'A':
			printf("1010");
			break;
		case 'B':
			printf("1011");
			break;
		case 'C':
			printf("1100");
			break;
		case 'D':
			printf("1101");
			break;
		case 'E':
			printf("1110");
			break;
		case 'F':
			printf("1111");
			break;

		}
		i++;
		}
  
}