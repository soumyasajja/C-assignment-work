#include <iostream>
using namespace std;
struct __stack__
{
	int top;
	char *s;
	int size;
};
class _stack_
{
	struct __stack__ sta;
public:
	_stack_();
	void push(char);
	char pop();
	char peek();
	bool IsEmpty();
	bool IsFull();
	void display();
	~_stack_();
	void getsize(int);
};
_stack_::_stack_()
{
	sta.top = -1;
	sta.s = NULL;
	sta.size = 0;
}
void _stack_::getsize(int n)
{
	sta.size = n;
	sta.s = new char[n];
}
bool _stack_::IsFull()
{
	return(sta.top == (sta.size - 1));
}
bool _stack_::IsEmpty()
{
	return(sta.top == -1);
}
void _stack_::push(char ele)
{
	if (!IsFull())
		sta.s[++sta.top] = ele;
	else
		cout << "stack is full" << endl;
}
char _stack_::pop()
{
	char x;
	if (!IsEmpty())
	{
		x = sta.s[sta.top--];
	}
	else
		cout << "stack is empty" << endl;
	return x;
}
char _stack_::peek()
{
	char x = -999;
	if (!IsEmpty())
		x = sta.s[sta.top];
	else
		cout << "stack is empty" << endl;
	return x;
}
void _stack_::display()
{
	for (int i = 0; i < sta.top; i++)
		cout << sta.s[i];
}
_stack_::~_stack_()
{
	delete sta.s;
}
int main()
{
	_stack_ st;
	char str[20],ch;
	int flag;
	cout << "enter the string" << endl;
	cin >> str;
	st.getsize(strlen(str));
	for (int i = 0; i < strlen(str); i++)
	{
		ch = str[i];
		switch (ch)
		{
		case '(':
		case '[' :
		case '{' : 
				st.push(ch);
				break;
		case ')':
		case ']':
		case '}' : 
			if (!st.IsEmpty())
			{
				if ((ch == ')'&&st.peek() == '(') || (ch == ']'&&st.peek() == '[') || (ch == '}'&&st.peek() == '{'))
				{
					st.pop();
					break;
				}
				else
					flag = 1;
				break;
			}
			else
				flag = 1;
		}
	}
	if (!st.IsEmpty())
		flag = 1;
	if (flag==1)
			cout <<"not matched" << endl;
	else
		cout << "matched" << endl;
	return 0;
}