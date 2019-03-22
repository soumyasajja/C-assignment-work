#include <iostream>
using namespace std;
class Power
{
	double base,value;
	int exponent;
public:
	Power()
	{
		base = 0; value = 0; exponent = 0;
	}
	Power(double bs, int exp)
	{
		base = bs;
		exponent = exp;
		for (; exponent != 0; exponent--)
			value = base * value;
	}
	Power operator+(Power obj)
	{
		Power temp;
		temp.base = base + obj.base;
		temp.exponent = exponent + obj.exponent;
		cout << "inside operator overload\n";
		return temp;
	}
	double get_Value()
	{
		return value;
	}
	operator double()
	{
		cout << "inside conversion\n";
		return value;
	}
};
int main()
{
	Power p_obj1(3.2,2), p_obj2(2.0,4);
	double result_1;
	Power result_obj = p_obj1 + p_obj2;
	result_1 = p_obj1 + 11.2;
	cout << "the addition of the objects is:" << result_obj.get_Value() << endl;
	cout << "result 2" << result_1<<endl;
	system("pause");
	return 0;
}