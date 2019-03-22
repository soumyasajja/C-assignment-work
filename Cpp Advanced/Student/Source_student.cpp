#include <iostream>
using namespace std;
#define MAX_NAME 50
#define MAX_BRANCH 20
class Student
{
protected:
	char *name_student;
	int rollno;
public:
	Student()
	{
		name_student = NULL;
		rollno = 0;
	}
	void get_name()
	{
		name_student = new char[MAX_NAME + 1];
		cin >> name_student;
	}
	void get_rno()
	{
		cin >> rollno;
	}
	virtual void get_details() = 0;
	virtual void display_details() = 0;
	~Student()
	{
		delete[] name_student;
	}
};
class Engineering:public virtual Student
{
	char *branch;
public:
	Engineering()
	{
		branch = NULL;
	}
	void get_details()
    {
        cout << "enter the name of engg student:\n";
		get_name();
		cout << "enter the roll number:\n";
		get_rno();
		branch = new char[MAX_BRANCH + 1];
		cout << "enter the branch:\n";
		cin >> branch;
    }
    void display_details()
    {
	cout << "Student name:" << name_student << endl;
	cout << "roll no:" << rollno << endl;
	cout << "branch:" << branch << endl;
    }
	~Engineering()
	{
		delete[] branch;
	}
};
class Medicine :public virtual Student
{
	char *stream_medico;
public:
	Medicine()
	{
		stream_medico = NULL;
	}
	void get_details()
	{
		cout << "enter the medical student name:\n";
		get_name();
		cout << "enter the rollno:\n";
		get_rno();
		stream_medico = new char[MAX_BRANCH + 1];
		cout << "enter the stream:\n";
		cin >> stream_medico;
	}
	void display_details()
	{
		cout << "Student name:" << name_student << endl;
		cout << "roll no:" << rollno << endl;
		cout << "stream:" << stream_medico<< endl;
	}
	~Medicine()
	{
		delete[] stream_medico;
	}
};
class Science :public virtual Student
{
	char* area_research;
public:
	Science()
	{
		area_research = NULL;
	}
	void get_details()
	{
		cout << "enter the name of science student:\n";
		get_name();
		cout << "enter the rollno:\n";
		get_rno();
		area_research = new char[MAX_BRANCH + 1];
		cout << "enter the area of research:\n";
		cin >> area_research;
	}
	void display_details()
	{
		cout << "Student name:" << name_student << endl;
		cout << "roll no:" << rollno << endl;
		cout << "area of research:" << area_research << endl;
		getchar();
	}
};
int main()
{
	Engineering *eng1 = new Engineering();
	Medicine *mdn = new Medicine();
	Science *scie = new Science();
	Student *sptr[3];
	sptr[0] = eng1;
	sptr[1] = mdn;
	sptr[2] = scie;
	for (int loop = 0; loop < 3; loop++)
		sptr[loop]->get_details();
	for (int out_loop = 0; out_loop < 3; out_loop++)
		sptr[out_loop]->display_details();
	delete eng1;
	delete mdn;
	delete scie;
	system("pause");
	getchar();
	return 0;
}