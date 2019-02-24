#include <iostream> 
using namespace std;
int search(int arr[], int n, int ele)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == ele)
			return i;
	return -1;
}

int main()
{
	int arr[10],element;
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "enter the element to be searched\n";
	cin >> element;
	int result = search(arr, n, element);
	(result == -1) ? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;
	return 0;
}