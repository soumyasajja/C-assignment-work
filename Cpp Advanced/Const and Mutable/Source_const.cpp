#include <iostream>
using namespace std;
class MyClass
{
	mutable int number1;
	int	number2;
public:
	MyClass(int n1, int n2)
	{
		number1 = n1;
		number2 = n2;
	}
	int get_num1()const
	{
		return number1;
	}
	void set_num1(int n1)const
	{
		number1 = n1;	
	}
	int get_num2()const
	{
		return number2;
	}
};
int main()
{
	MyClass obj(2, 4);
	cout << "the value of number 1:" << obj.get_num1() << endl;
	obj.set_num1(55);
	cout << "the modified value of mutable number:" << obj.get_num1() << endl;
	cout << "the value of constant number 2:" << obj.get_num2() << endl;
	system("pause");
	return 0;
}