#include <iostream>
using namespace std;
class Distance2;
class Distance1
{
	float mt,cm;
public:void readDistance1()
	{
	cout << "enter the distance in meters" << endl;
	cin >> mt;
	cout << "enter the distance in centimeters" << endl;
	cin >> cm;
	}
	   void convert1()
	   {
		   mt = mt * 3.281;
		   cm = cm * 0.393;
	   }
	   friend void add(Distance1, Distance2);
};
class Distance2
{
	float ft, in;
public:void readDistance2()
{
	cout << "enter the distance in feet" << endl;
	cin >> ft;
	cout << "enter the distance in inches" << endl;
	cin >> in;
}
	   void convert2()
	   {
		   ft = ft * 0.3048;
		   in = in * 2.54;
	   }
	   friend void add(Distance1, Distance2);
};
void add(Distance1 p, Distance2 q)
{
	p.convert1();
	q.ft = p.mt + q.ft;
	q.in = p.cm + q.in;
	cout << "result=" << q.ft<<" " << q.in;
}
int main()
{
	Distance1 d1;
	Distance2 d2;
	d1.readDistance1();
	d2.readDistance2();
	add(d1, d2);
	return 0;
}