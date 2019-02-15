#include <iostream>
using namespace std;
class STUDENT
{
	int rollno;
	char name[20];
	int marks[3];
	int total=0;
	char grade;
public:
	friend ostream& operator<<(ostream& cout, STUDENT s);
	friend istream& operator>>(istream& cin, STUDENT s);
	friend void generate_results(STUDENT[], int n);
};
ostream& operator<<(ostream& cout, STUDENT s)
{
	cout << "rollno=" << s.rollno << endl;
	cout << "name=" << s.name << endl;
	cout << "marks of three subjects=" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << s.marks[i]<<endl;
	}
	cout << "total of marks=" << s.total << endl;
	cout << "grade=" << s.grade << endl;
	return cout;
}
istream& operator>>(istream& cin, STUDENT s)
{
	cin >> s.rollno;
	for (int i = 0; i < 3; i++)
	{
		cin >> s.marks[i];
	}
	cin >> s.name;
	return cin;
}
void generate_results(STUDENT *s_arr, int n)
{
	s_arr = new STUDENT[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			s_arr[i].total += s_arr[i].marks[j];
		}

	}
	for (int i = 0; i < n; i++)
	{
		if (s_arr[i].total > 70)
		{
			s_arr[i].grade = 'A';
		}
		else if (s_arr[i].total > 60 && s_arr[i].total < 70)
		{
			s_arr[i].grade = 'B';
		}
		else if(s_arr[i].total>50&&s_arr[i].total<60)
		{
			s_arr[i].grade = 'C';
		}
	}
	/*for (int i = 0; i < n; i++)
	{
		delete s_arr[i];
	}
	delete[]s_arr;*/
}
int main()
{
	STUDENT s1, s2, s3;
	STUDENT s_arr[] = { s1,s2,s3 };
	cout << "enter the values of 1st object" << endl;
	cin >> s1;+
	cout << "enter the value of second object" << endl;
	cin >> s2;
	cout << "enter the value of third object" << endl;
	cin >> s3;
	generate_results(s_arr, 3);
	cout << s1;
	cout << s2;
	cout << s3;
	return 0;
}