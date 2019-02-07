#include <stdio.h>
int binToHex(long long);
//long long hexToBin(int);
int main()
{
	long long bin;
	int hex;
	printf("enter the binary value\n");
	scanf("%lld", &bin);
	printf("enter the hexadecimal value\n");
	scanf("%x", &hex);
	printf("the value of %lld in hexadecimal is %x\n", bin, binToHex(bin));
	//printf("the value of %x in hexadecimal is %lld\n", hex, hexToBin(hex));
}
int binToHex(long long binary)
{
	int rem, i = 0, count = 0,res=0,dec=0;
	while (binary != 0)
	{
		rem = binary % 2;
		binary /= 2;
		res += rem * pow(2, i);
		++i;
		++count;
		if (count == 4)
			res = res << count;
			continue;
	}

	dec = dec | res;
	return dec;
}