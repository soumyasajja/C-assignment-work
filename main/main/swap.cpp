#include <iostream>
using namespace std;
void swap_value(int i, int j)
{
	i = i + j;
	j = i - j;
	i = i - j;
	cout << i <<' '<< j << endl;
}
void swap_reference(int &i, int &j)
{
	i = i + j;
	j = i - j;
	i = i - j;
	cout << i <<' '<< j << endl;
}
int main()
{
	int a, b,c;
	cout << "enter a and b values" << endl;
	cin >> a >> b;
	cout << "enter option:1)call by val 2)call by ref" << endl;
	cin >> c;
	switch (c)
	{
	case 1:
		swap(a, b);
		cout << a << b << endl;
		break;
	case 2:
		swap(a, b);
		cout << a << b << endl;
		break;
	}
}