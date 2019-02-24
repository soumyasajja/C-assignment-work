#include <iostream>
using namespace std;
void build_heap(int a[],int i, int n)
{
	int temp=a[i];
	int c;
	for (; 2 * i + 1 < c; i = c)
	{
		int c = 2 * i + 1;
		if (c + 1 < n&&a[c + 1] > a[c])
			c++;
		if (a[c] > temp)
			a[i] = a[c];
		else
			break;
	}
	a[i] = temp;
}
void heap_sort(int a[], int n)
{
	int temp,i;
	for (i = n / 2 - 1; i >= 0; i--)
		build_heap(a,i,n);
	for (int j = 1; j <= n - 1; j++)
	{
		temp = a[0];
		a[0] = a[n - j];
		a[n - j] = temp;
		build_heap(a, 0, n - j);
	}
}
int main()
{
	int n, *a;
	cout << "enter the number of elements\n";
	cin >> n;
	a = new int[n];
	cout << "enter the array elements\n";
	for (int i = 0; i < n; i++)
		cin >> a[i];
	heap_sort(a,n - 1);
	cout << "the sorted elements are\n";
	for (int i = 0; i < n; i++)
		cout << a[i];
	delete a;
}