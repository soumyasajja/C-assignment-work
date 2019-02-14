#include <iostream>
#include <math.h>
using namespace std;
class Point
{
	int x, y;
public: 
	void input()
	{
		cout << "enter the values of x and y";
		cin >> x >> y;
	}
	friend void calculateDist(Point,Point);
};
void calculateDist(Point p1,Point p2)
{
	float dist;
	dist = sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
	cout << "distance between p1 and p2=" << dist;
}
int main()
{
	Point p1, p2;
	p1.input();
	p2.input();
	calculateDist(p1, p2);
}