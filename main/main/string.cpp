#include <iostream>
#include <string>
using namespace std;
class String
{
public:
	char *sptr;
	int len;
	String operator=(String temp)
	{
		len = temp.len;
		if (sptr != NULL)
			free sptr;
		sptr = (char*)malloc(sizeof(char)*(len + 1));
	}
	friend istream& operator>>(istream& cin, String& s);
	friend ostream& operator<<(ostream& cout, String s);
};
istream& operator>>(istream& cin, String& s)
{
	cin >> s.len;
	s.sptr = new char[s.len+1];
	for (int i = 0; i < s.len; i++)
	{
		cin >> s.sptr[i];
	}
	return cin;
}
ostream& operator<<(ostream& cout, String s)
{
	cout <<"The length of the string is "<< s.len<<endl;
	cout <<"The string is"<< s.sptr<<endl;
	return cout;
}
int main()
{
	String s;
	cout << "enter the contents of the string"<<endl;
	cin >> s;
	cout << s;
}