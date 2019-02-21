#include <iostream>
using namespace std;
int main()
{
	int a[10], n, i, j, temp;
	n = sizeof(a) / sizeof(a[0]);
	cout << "enter the array elements\n";
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
	{
		j = i;
		temp = a[j];
		while ((j - 1) != 0 && a[j - 1] > temp)
		{
			a[j] = a[j - 1];
			j--;
		}
		for (i = 0; i <= n - 1; i++)
		{
			j = i - 1;
			temp = a[i];
			while (j >= 0 && a[j] > temp)
			{
				a[j + 1] = a[j];
				j--;
				a[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
		cout << a[i];
}