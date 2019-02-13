#include <iostream>
using namespace std;
class Time
{
	int hrs, min, sec;
public:
	Time()
	{
		hrs = 0;
		min = 0;
		sec = 0;
	}
	Time(int h, int m, int s)
	{
		hrs = h;
		min = m;
		sec = s;
	}
	void add_time(Time &t1, Time &t2)
	{
		hrs = t1.hrs + t2.hrs;
		min = t1.min + t2.min;
		sec = t1.sec + t2.sec;
		if (sec > 60)
		{
			sec = sec - 60;
			min = min + 1;
		}
		if (min > 60)
		{
			min = min - 60;
			hrs = hrs + 1;
		}
		if (hrs > 23)
		{
			hrs = 0;
		}
	}
	void display()
	{
		cout << hrs << ':' << min << ':' << sec<<endl;
	}
};


int main()
{
   // cout<<"Hello world";
	Time t1(10, 20, 30), t2(11, 22, 33), t3;
	t1.display();
	t2.display();
	t3.add_time(t1, t2);
	t3.display();
	return 0;
}