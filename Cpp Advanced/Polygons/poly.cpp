#include <iostream>
using namespace std;
class Polygon
{
	float dimen1;
	float dimen2;
public:
	Polygon(float d1, float d2)
	{
		dimen1 = d1;
		dimen2 = d2;
	}
	float get_dimen1()
	{
		return dimen1;
	}
	float get_dimen2()
	{
		return dimen2;
	}
	virtual void calculate_area() = 0;
	~Polygon()
	{
		cout << "Base class polygon destructor" << endl;
	}
};
class Triangle:public virtual Polygon
{
public:
	Triangle(float base, float height) :Polygon(base, height)
	{
	}
	void calculate_area()
	{
		float area_triangle = 0.5*get_dimen1()*get_dimen2();
		cout <<"area of the triangle: "<< area_triangle << endl;
	}
	~Triangle()
	{
		cout << "Triangle class destructor" << endl;
	}
};
class Rectangle :public virtual Polygon
{
public:
	Rectangle(float length,float breadth):Polygon(length,breadth)
	{}
	void calculate_area()
	{
		float area_rectangle = get_dimen1()*get_dimen2();
		cout << "area of rectangle: " << area_rectangle << endl;
	}
	~Rectangle()
	{
		cout << "Rectangle class destructor" << endl;
	}
};
int main()
{
	Triangle *tptr = new Triangle(3, 8);
	Polygon *poly1 = tptr;
	Rectangle *rptr = new Rectangle(4, 7);
	Polygon *poly2 = rptr;
	poly1->calculate_area();
	poly2->calculate_area();
	delete tptr;
	delete rptr;
	/*delete poly1;
	delete poly2;*/
	system("pause");
	getchar();
	return 0;
}