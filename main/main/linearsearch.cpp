#include <iostream>
using namespace std;
template <class T>
int linear_search(T a[], int n, T ele)
{
	int i, flag = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == ele)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int linear_search(char* a[], int n, char* ele)
{
	int i, flag = 0;
	for (i = 0; i < n; i++)
	{
		if (string(a[i], ele) == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int main()
{

}