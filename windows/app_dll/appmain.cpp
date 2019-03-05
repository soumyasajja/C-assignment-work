#include <iostream>
#include <Windows.h>
#include "Header.h"
using namespace std;
int main()
{
	int nLeft, nRight,num;
	cout << "enter the values of nLeft and nRight" << endl;
	cin >> nLeft >> nRight;
	cout << "enter a number to perform the following operations\n";
	cout << "1.addition 2.subtraction 3.multiplication 4.division\n";
	cin >> num;
	switch (num)
	{
	case 1:
		cout << "addn=" << add(nLeft, nRight) <<endl;
		break;
	case 2:
		cout << "subn=" << sub(nLeft, nRight) <<endl;
		break;
	case 3:
		cout << "muln=" << mul(nLeft, nRight) << endl;
		break;
	case 4:
		cout << "divn=" << division(nLeft, nRight)<< endl;
		break;
	}
	return 0;
}

