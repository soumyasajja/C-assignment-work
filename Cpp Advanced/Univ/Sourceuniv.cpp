#include <iostream>
using namespace std;
#define MAX_UNIV_NAME 100
#define MAX_DEPT 40
#define MAX_PERSON_PROJ 30
#define MAX_COMPANY_NAME 30
#define MAX_TYPE_PROJ 20
class University
{
	char *Univ_name;
	char *department;
	char *person_in_proj;
public:
	University()
	{
		Univ_name = NULL;
		department = NULL;
		person_in_proj = NULL;
	}
	void get_univ_data()
	{
		Univ_name = new char[MAX_UNIV_NAME + 1];
		cout << "enter the university name:\n";
		cin >> Univ_name;
		department = new char[MAX_DEPT + 1];
		cout << "enter the department:\n";
		cin >> department;
		person_in_proj = new char[MAX_PERSON_PROJ + 1];
		cout << "enter the name of the person in the project:\n";
		cin >> person_in_proj;
	}
	virtual void display()
	{
		cout << "name of university: " << Univ_name<<endl;
		cout << "department to which the project is assigned: " << department << endl;
		cout << "person assigned to the project: " << person_in_proj << endl;
	}
	~University()
	{
		delete[] Univ_name;
		delete[] department;
		delete[] person_in_proj;
	}
};
class Company
{
	char *company_name;
	int no_of_engg;
	int amount;
public:
	Company()
	{
		company_name = NULL;
		no_of_engg = 0;
		amount = 0;
	}
	void get_company_data()
	{
		company_name = new char[MAX_COMPANY_NAME + 1];
		cout << "enter the company name:\n";
		cin >> company_name;
		cout << "enter the number of engineers in the project:\n";
		cin >> no_of_engg;
		cout << "enter the amount of the project:\n";
		cin >> amount;
	}
	/*virtual int get_amount()
	{
		return amount;
	}*/
	virtual void display()
	{
		cout << "company name is: " << company_name << endl;
		cout << "number of engineers assigned: " << no_of_engg << endl;
		cout << "amount invested in the project: " << amount << endl;
	}
	~Company()
	{
		delete[] company_name;
	}
};
class Project :public University, public Company
{
	char *type_of_proj;
	int duration_proj;
	int amount_granted;
public:
	Project()
	{
		type_of_proj = NULL;
		duration_proj = 0;
		amount_granted = 0;
	}
	void get_proj_data()
	{
		type_of_proj = new char[MAX_TYPE_PROJ + 1];
		cout << "enter the type of project:\n";
		cin >> type_of_proj;
		cout << "enter the duration of the project:\n";
		cin >> duration_proj;
		cout << "enter the amount granted for the project:\n";
		cin >> amount_granted;
	}
	void display()
	{
		cout << "the type of project assigned: " << type_of_proj << endl;
		cout << "duration of the project: " << duration_proj << endl;
		//cout << "the amount granted for the project is: " << amount_granted < endl;
	}
	~Project()
	{
		delete[] type_of_proj;
	}
};
int main()
{
	University univ,*u_ptr;
	Company comp;
	Project pro;
	//u_ptr = &pro;
	//u_ptr->display();
	pro.get_univ_data();
	pro.get_company_data();
	pro.get_proj_data();
	pro.University::display();
	pro.Company::display();
	pro.display();
	getchar();
	return 0;
}