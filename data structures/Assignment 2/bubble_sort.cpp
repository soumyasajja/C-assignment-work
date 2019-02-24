#include <iostream>
using namespace std;
int main()
{
	int *a,n,i,j,flag,temp;
	cout << "enter the size of the array\n";
	cin >> n;
	a = new int[n];
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	for (i = 0; i < n; i++)
		cout << a[i];
	delete a[];
}