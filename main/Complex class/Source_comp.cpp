#include <iostream>
using namespace std;
class Complex
{
	float real_part;
	float img_part;
public:
	Complex();
	Complex(float arg);
	Complex(float arg_real, float arg_img);
	friend void add_complex(Complex, Complex);
	friend void mul_complex(Complex, Complex);
	~Complex();
};
Complex::Complex()
{
	real_part = 0; img_part = 0;
}
Complex::Complex(float arg)
{
	real_part = arg; img_part = arg;
}
Complex::Complex(float arg_real, float arg_img)
{
	real_part = arg_real;
	img_part = arg_img;
}
void add_complex(Complex c_obj1, Complex c_obj2)
{
	Complex add_result;
	add_result.real_part = c_obj1.real_part + c_obj2.real_part;
	add_result.img_part = c_obj1.img_part + c_obj2.img_part;
	cout << "addition of complex numbers is" << add_result.real_part << "+i" << add_result.img_part<<endl;
}
void mul_complex(Complex c_obj1, Complex c_obj2)
{
	Complex mul_result;
	mul_result.real_part = c_obj1.real_part * c_obj2.real_part;
	mul_result.img_part = c_obj1.real_part * c_obj2.img_part;
	cout << "multiplication of complex numbers is" << mul_result.real_part << "+i" << mul_result.img_part << endl;
}
Complex::~Complex()
{
}
int main()
{
	/*int input, loop = 0;*/
	Complex comp1, comp2(4), comp3(34, 12);
	add_complex(comp1, comp2);
	add_complex(comp2, comp3);
	mul_complex(comp2, comp3);
	//cout << "enter an operatio to perform\n";
	//cout << "1.def const\n 2.single par const\n 3.2 par const\n";
	//cin >> input;
	//if (input == 1)
	//{
	//	Complex comp4;
	//}
	//else if (input == 2)
	//{
	//	float arg;
	//	cout << "enter float value for single parameter constructor\n";
	//	cin >> arg;
	//	Complex comp5(arg);
	//}
	//else if (input == 3)
	//{
	//	float real, img;
	//	cout << "enter the float real and imaginary values for 2 parameter constructor\n";
	//	cin >> real >> img;
	//	Complex comp6(real, img);
	//}
	//else
	//{
	//	cout << "invalid input value\n";
	//}
	cout << "waiting for input before exiting\n";
	getchar();
	return 0;
}