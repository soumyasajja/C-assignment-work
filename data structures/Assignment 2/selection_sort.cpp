#include <iostream>
using namespace std;
int main()
{
	int a[10], i, j, loc, temp,n;
	n=sizeof(a)/sizeof(a[0]);
	cout << "enter the array elements\n";
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n - 1; i++)
	{
		loc = i;
		j = i + 1;
		while (j <= n - 1)
		{
			if (a[j] < a[loc])
				loc = j;
			j++;
		}
		temp = a[i];
		a[i] = a[loc];
		a[loc] = temp;
	}
	for (i = 0; i < n; i++)
		cout << a[i];
}