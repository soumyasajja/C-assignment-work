#include <iostream>
using namespace std;
template <class T>
int linear_search(T array[], int size_arr, T element)
{
	int count, flag = 0;
	for (count = 0; count < size_arr; count++)
	{
		if (array[count] == element)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int linear_search(char *array[], int size_arr, char *element)
{
	int count, flag = 0;
	for (count = 0; count < size_arr; count++)
	{
		if (strcpy(array[count], element) == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int main()
{
	int *arr_int, size_IntArr, result;
	char *arr_char;
	char **arr_string;
	cout<<"ente"
}