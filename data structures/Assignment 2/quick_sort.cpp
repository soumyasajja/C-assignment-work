#include <iostream>
using namespace std;
void quick_sort(int a[], int low, int high)
{
	int pivot = a[low];
	int i, j,temp;
	i = low + 1;
	j = high;
	if(low<high)
	{ 
	while(1)
	{
		while (i <= high && a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else
			break;
	}
	temp = a[low];
	a[low] = a[j];
	a[j] = temp;
	quick_sort(a, low, j - 1);
	quick_sort(a, j + 1, high);
	}
}
int main()
{
	int a[20], n;
	cout << "enter the number of elements\n";
	cin >> n;
	cout << "enter the array elements\n";
	for (int i = 0; i < n; i++)
		cin >> a[i];
	quick_sort(a, 0, n - 1);
	cout << "sorted elements are\n";
	for (int i = 0; i < n; i++)
		cout << a[i];
}