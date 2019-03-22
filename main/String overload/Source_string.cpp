#include <iostream>
#include <string>
using namespace std;
class String
{
public:
	char *sptr;
	int len;
	String()
	{
		sptr = NULL;
		len = 0;
	}
	String(const char *s)
	{
		sptr = new char[strlen(s) + 1];
		strcpy(sptr, s);
		len = strlen(s);
	}
	String(const String&temp)
	{
		len = temp.len;
		sptr = new char[len + 1];
		strcpy(sptr, temp.sptr);
	}
	~String()
	{
		if (sptr != NULL)
			free(sptr);
	}
	String operator=(String temp)
	{
		if (sptr != NULL)
			free;
		sptr = new char[strlen(temp.sptr)+1];
		strcpy(sptr, temp.sptr);
		len = temp.len;
		return(*this);
	}
	char& operator[](int pos)
	{
		if (pos > len)
		{
			cout << "index out of bounds\n";
		}
		else
		{
			return sptr[pos];
		}
		//return sptr[0];
	}
	friend String operator+(const String &str1, const String &str2);
	friend istream& operator>>(istream& cin, String& s);
	friend ostream& operator<<(ostream& cout, String s);
};
String operator+(const String &str1, const String &str2)
{
	String temp;
	temp.len = str1.len + str2.len;
	temp.sptr = new char[temp.len + 1];
	strcpy(temp.sptr, str1.sptr);
	strcat(temp.sptr, str2.sptr);
	return temp;
}
istream& operator>>(istream& cin, String& s)
{
	char buffer[100];
	cin >> buffer;
	s.sptr = new char[strlen(buffer) + 1];
	s.len = strlen(buffer);
	strcpy(s.sptr, buffer);
	return cin;
}
ostream& operator<<(ostream& cout, String s)
{
	cout << "The length of the string is " << s.len << endl;
	cout << "The string is" << s.sptr << endl;
	return cout;
}
int main()
{
	String def_string, param_string("Soumya"), copy_const_str(param_string), deepcpy_str, concat_string;
	cout << "Enter the string\n";
	cin >> def_string;
	cout << "Entered string is\n";
	cout << def_string<<endl;
	cout << "parameterized string is\n";
	cout << param_string << endl;
	cout << copy_const_str << endl;
	deepcpy_str = def_string;
	cout << "the deep copied string is\n";
	cout << deepcpy_str<<endl;
	concat_string = param_string + deepcpy_str;
	cout << "concatenation after deep copying\n";
	cout << concat_string << endl;
	cout << "index output\n";
	cout << param_string[4];
	return 0;
}