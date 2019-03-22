
#include<iostream>
#include<cstring>
using namespace std;
#include<string.h>
#define LEN 50
class MyString     //MyString Class
{
	char *name;
	int length;

public:

	MyString()     //Default Constructor
	{
		name = NULL;
		length = 0;
	}

	MyString(const char *para)    //Parameterised Constructor
	{
		name = new char[strlen(para) + 1];
		strcpy(name, para);
		length = strlen(para);
	}

	MyString(const MyString &copy)   //Copy Constructor
	{

		name = new char[copy.length + 1];
		strcpy(name, copy.name);
		length = copy.length;
	}

	void Display()
	{
		cout << name << endl;
	}
	void input()
	{
		name = new char[10];
		cin >> name;
	}
	~MyString()
	{
		if (name != NULL)
			delete[]name;
	}

	MyString operator=(MyString c)
	{
		delete[]name;
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
		length = c.length;
		return (*this);
	}

	MyString operator+(MyString &c)
	{
		MyString temp;
		temp.length = length + c.length;
		temp.name = new char[temp.length + 1];
		strcpy(temp.name, name);
		strcat(temp.name, c.name);
		return temp.name;
	}
	friend ostream& operator<<(ostream &cout, const MyString &str);
	friend istream& operator>>(istream &cin, MyString &str);
	friend void sort(MyString s[], int);
};

void sort(MyString s[10], int n)  	// Sorting strings using bubble sort 
{
	char temp[LEN];
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = j + 1; i < n; i++)
		{
			if (strcmp(s[j].name, s[i].name) > 0)
			{
				strcpy(temp, s[j].name);
				strcpy(s[j].name, s[i].name);
				strcpy(s[i].name, temp);
			}
		}
	}
}


ostream& operator<<(ostream &cout, const MyString &str)
{
	cout << str.name;
	return cout;
}
istream& operator>>(istream &cin, MyString &str)
{
	char temp[100];
	cin >> temp;
	str.name = new char[strlen(temp) + 1];
	str.length = strlen(temp);
	strcpy(str.name, temp);
	return cin;
}
int main()
{
	char pass[10];
	cout << "Enter a string tos be passed in parameterised constructor:";
	gets_s(pass);
	MyString first_str, para_str(pass), copy_str(para_str), deep_str, concat_str;
	cout << "Enter the string:";
	first_str.input();
	cout << "Entered string is :";
	cout << first_str;
	cout << endl << "Parameterised constructer string consists of :";
	para_str.Display();
	cout << endl << "Copy constructor string consists of :";
	copy_str.Display();
	deep_str = first_str;  //deep copying
	cout << endl << "Deep copied string has :";
	deep_str.Display();
	concat_str = copy_str + deep_str;
	cout << endl << "After concatinating copy and deep string :";
	cout << concat_str << endl;

	int itr1;

	MyString sample[10];
	int number;
	cout << "Enter no of Strings to be sorted:";
	cin >> number;

	for (itr1 = 0; itr1 < number; itr1++)
	{
		cout << "Enter string" << itr1 << ":";
		sample[itr1].input();
	}
	sort(sample, number);
	for (itr1 = 0; itr1 < number; itr1++)
	{
		sample[itr1].Display();
		cout << endl;
	}
	return 0;
}

