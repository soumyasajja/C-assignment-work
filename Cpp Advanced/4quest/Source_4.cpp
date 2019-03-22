#include <iostream>
using namespace std;
class MyClass1
{
	const int numA;
	const int numB;
public:
	MyClass1(){}
	MyClass1(int num_x,int num_y):numA(num_x),numB(num_y)
	{}
	int get_numA()
	{
		return numA;
	}
	int get_numB()
	{
		return numB;
	}
};

