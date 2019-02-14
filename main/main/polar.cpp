#include <iostream>
#include <math.h>
using namespace std;
class Polar
{
	float r,theta;
public:
	static int count;
	void inc_count()
	{
		count++;
		cout << "The number of active objects are" << count << endl;
	}
	void calc_polar()
	{
		int x, y;
		cout << "enter the cartesian coordinates" << endl;
		cin >> x >> y;
		r = sqrt(pow(x, 2) + pow(y, 2));
		theta = atan(y / x);
		cout << "the polar coordinates are" << r << " " << theta<<endl;
	}
};
int Polar::count;
int main()
{
	Polar p1, p2;
	p1.calc_polar();
	p1.inc_count();
	p2.calc_polar();
	p2.inc_count();
	return 0;
}