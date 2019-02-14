#include<stdio.h>
int countLeapYears(struct Date dt);
int main()
{
	struct Date
	{
		int d, m, y;
	};
	 struct Date dt1 = { 1,2,2000 };
	 struct Date dt2 = { 1,2,2004 };
	printf("the difference between the dates is %d", getDifference(dt1, dt2));
	return 0;
}
int countLeapYears(struct Date dt)
{
	int years = dt.y;
	if (dt.m > 2)
	{
		years--;
		return years / 4 - years / 100 + years / 400;
	}
	else
	{
		return years / 4 - years / 100 + years / 400;
	}
}
int getDifference(struct Date dt1, struct Date dt2)
{
	long int n1, n2;
	const int monthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	n1 = dt1.y * 365 + dt1.d;
	for (int i = 0; i < dt1.m; i++)
	{
		n1 += monthDays[i];
	}
	n1 += countLeapYears(dt1);
	n2 = dt2.y * 365 + dt2.d;
	for (int i = 0; i < dt2.m; i++)
	{
		n2 += monthDays[i];
	}
	n2 += countLeapYears(dt2);
	return(n2 - n1);
}