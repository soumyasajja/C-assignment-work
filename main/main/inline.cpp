#include <iostream>
using namespace std;
inline int add(int a, int b)
{
	return (a + b);
}
inline int sub(int a, int b)
{
	return (a - b);
}
inline long int mul(int a, int b)
{
	return(a*b);
}
inline float div(float a, float b)
{
	return (a / b);
}
int main()
{
	int a, b;
	float c, d;
	cout << "enter a and b"<<endl;
	cin >> a >> b;
	cout << "enter c and d" << endl;
	cin >> c >> d;
	cout<<"sum="<< add(a, b)<<endl;
	cout<<"diff ="<< sub(a, b)<<endl;
	cout<<"prod ="<<mul(a, b)<<endl;
	cout<<"division ="<<div(c, d)<<endl;
	return 0;
}