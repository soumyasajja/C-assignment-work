#include <iostream>
using namespace std;
//int Operate1(int x_num, int y_num, int(*fun)(int, int))
//{
//	return (*fun)(x_num, y_num);
//}
class Operate
{
public:
	Operate(){}
	virtual int operator()(int x1, int y1) = 0;
};
class Add :public Operate
{
public:
	Add(){}
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};
class Mul :public Operate
{
public:
	Mul(){}
	int operator()(int num1, int num2)
	{
		return num1 * num2;
	}
};
int operate_func(int num1, int num2, Operate* obj)
{
	return (*obj)(num1, num2);
}
int main()
{
	Operate *obj1 = new Add();
	Operate *obj2 = new Mul();
	int result_add, result_mul, nLeft, nRight;
	cout << "enter the first operand:\n";
	cin >> nLeft;
	cout << "enter the second operand:\n";
	cin >> nRight;
	result_add = operate_func(nLeft, nRight, obj1);
	result_mul = operate_func(nLeft, nRight, obj2);
	cout << "addition=" << result_add << endl;
	cout << "multiplication=" << result_mul << endl;
	system("pause");
	return 0;
}