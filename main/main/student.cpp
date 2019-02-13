#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
	char studentName[24];
	char grade;
	int english;
	int maths;
	int science;
};
class CollegeCourse
{
	Student s1;
	int len;
	float avg;
public:
	void setData(char *str, char grade, int eng, int mat, int sc)
	{
		len = strlen(str);
		str = (char*)malloc(sizeof(char)*(len + 1));
		strcpy(s1.studentName, str);
		s1.grade = grade;
		s1.english = eng;
		s1.maths = mat;
		s1.science = sc;
	}
	void calculateAverage()
	{
		avg = (s1.english + s1.maths + s1.science)/3;
		cout << avg << endl;
	}
	void computeGrade()
	{
		if (avg > 60)
		{
			s1.grade = 'A';
			cout << "First class" << endl;
		}
		else if (avg > 50 && avg < 60)
		{
			s1.grade = 'B';
			cout << "Second class" << endl;
		}
		else if (avg > 40 && avg < 50)
		{
			s1.grade = 'C';
			cout << "Third class" << endl;
		}
		else if (avg < 40)
		{
			s1.grade = 'F';
			cout << "Fail" << endl;
		}
	}
	void display()
	{
		cout << "Name" << s1.studentName << endl;
		cout << "Grade" << s1.grade << endl;
		cout << "English" << s1.english << endl;
		cout << "Maths" << s1.maths << endl;
		cout << "Science" << s1.science << endl;
	}
};
int main()
{
	CollegeCourse c1;
	c1.setData("Soumya", 'a', 20, 30, 50);
	c1.calculateAverage();
	c1.computeGrade();
	c1.display();
	return 0;
}