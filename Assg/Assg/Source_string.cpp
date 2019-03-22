#include <iostream>
#include <string>
using namespace std;
//defining mystring class
class MyString
{
	char *name;
	int length;
public:
	//default constructor
	MyString()
	{
		name = NULL;
		length = 0;
	}
	MyString(const char *temp)//copy constructor
	{
		name = new char[strlen(temp) + 1];
		strcpy(name, temp);
		length = strlen(temp);
	}
	MyString(const MyString &str)
	{
		name = new char[str.length + 1];
		strcpy(name, str.name);
		length = str.length;
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
	MyString operator=(MyString str)
	{
		delete[] name;
		name = new char[strlen(str.name) + 1];
		strcpy(name, str.name);
		length = str.length;
		return (*this);
	}
	MyString operator<(MyString str)
	{
		int i;
		char temp;
		for (i = 0; str.name[i] != '\0'; i++)
		{
			if (str.name[i+1] < str.name[i])
			{
				temp = str.name[i];
				str.name[i] = str.name[i + 1];
				str.name[i + 1] = temp;
			}
		}
	}
	MyString operator+(MyString src)
	{
		MyString temp;
		temp.length = length + src.length;
		strcpy(temp.name,name);
		strcat(temp.name, src.name);
		return temp;
	}
	friend ostream& operator<<(ostream& cout, MyString str);
	friend istream& operator>>(istream& cin, MyString &str);
	//friend MyString operator+(MyString dest, MyString src);
	friend void str_bubble_sort(MyString s[],int size);
};
ostream& operator<<(ostream& cout, MyString str)
{
	cout << "the entered string is" << str.name << endl;
	cout << "the length of the string is" << str.length << endl;
	return cout;
}
istream& operator>>(istream& cin, MyString &str)
{
	char buffer[100];
	cin >> buffer;
	str.name= new char[strlen(buffer) + 1];
	str.length = strlen(buffer);
	return cin;
}
void str_bubble_sort(MyString s[10], int size)  	// Sorting strings using bubble sort 
{
	char temp[20];
	for (int j = 0; j < size - 1; j++)
	{
		for (int i = j + 1; i < size; i++)
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
int main()
{
	char pass_string[10];
	cout << "Enter a string to be passed to parameterised constructor:";
	gets_s(pass_string);
	MyString first_str, para_str(pass_string), copy_str(para_str), deep_str, concat_str;
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
	str_bubble_sort(sample, number);
	for (itr1 = 0; itr1 < number; itr1++)
	{
		sample[itr1].Display();
		cout << endl;
	}
	return 0;
}