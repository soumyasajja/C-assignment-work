#include <iostream>
#include <string>
using namespace std;
class Copy
{
	char* stored;
public:
	Copy()
	{
		stored = NULL;
	}
	Copy(const char *str)
	{
		stored = new char[strlen(str) + 1];
		strcpy(stored, str);
	}
	~Copy()
	{
		delete[] stored;
	}

};
int main()
{
	Copy c1,c2(c1);
	return 0;
}