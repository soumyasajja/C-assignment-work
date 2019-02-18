#include <iostream>
using namespace std;
struct __stack__
{
	int top;
	int *s;
	int size;
};
class _stack_
{
	struct __stack__ sta;
public:
	_stack_();
	void push(int);
	int pop();
	int peek();
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
	sta.s = new int[n];
}
bool _stack_::IsFull()
{
	return(sta.top == (sta.size - 1));
}
bool _stack_::IsEmpty()
{
	return(sta.top == -1);
}
void _stack_::push(int ele)
{
	if (!IsFull())
		sta.s[++sta.top] = ele;
	else
		cout << "stack is full" << endl;
}
int _stack_::pop()
{
	int x=-999;
	if (!IsEmpty())
	{
		x = sta.s[sta.top--];
	}
	else
		cout << "stack is empty" << endl;
	return x;
}
int _stack_::peek()
{
	int x = -999;
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
	int n;
	cout << "enter the size" << endl;
	cin >> n;
	st.getsize(n);
	for (int i = 0; i < n; i++)
	{
		int e;
		cout << "enter the element" << endl;
		cin >> e;
		st.push(e);
	}
	st.pop();
	st.pop();
	st.peek();
	cout << "display after popping" << endl;
	st.display();
	return 0;
}