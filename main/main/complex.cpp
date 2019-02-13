#include <iostream>
using namespace std;
class Complex
{
	float real, img;
public:
	Complex()
	{
		real = img = 0;
	}
	Complex(float r)
	{
		real = img = r;
	}
	Complex(float r, float i)
	{
		real = r;
		img = i;
	}

	void add_complex(Complex &c1, Complex &c2)
	{
		real = c1.real + c2.real;
		img = c1.img + c2.img;
		cout << "sum=" << real << "+" << img<<endl;
	}
	void mult_complex(Complex &c1, Complex &c2)
	{
		real = (c1.real)*(c2.real) - (c1.img)*(c2.img);
		img = (c1.real)*(c2.img) + (c1.img)*(c2.real);
		cout << "product=" << real << "+" << img<<endl;
	}
};
int main()
{
	Complex c1, c2(3), c3(3, 4);
	c1.add_complex(c2, c3);
	c1.mult_complex(c2, c3);
	return 0;
}