#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class __List__
{
	struct node *start;
public:
	__List__();
	void push(int);
	int pop();
	void display();
	~__List__();
};
__List__::__List__()
{
	start = NULL;
}
void __List__::push(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
	cout << start->data;
}
int __List__::pop()
{
	int x = -999;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		start = start->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "List is empty";
	return x;
}
void __List__::display()
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL)
		{
			cout << curr->data;
			curr = curr->next;
		}
	}
}
__List__::~__List__()
{
	struct node *temp;
	while (start != NULL)
	{
		temp = start;
		start = temp->next;
		delete temp;
	}
}
int main()
{
	__List__ ls;
	int i,ele,e1;
	cout << "enter 1.to push an element onto stack\n 2.to pop an element form stack\n 3.to display the contents of stack\n";
	cin >> i;
	while(i<=10)
	{ 
	switch (i)
	{
	case 1:
		cout << "enter an element" << endl;
		cin >> ele;
		ls.push(ele);
		break;
	case 2:
		e1 = ls.pop();
		cout << "the popped element is" << e1 << endl;
		break;
	case 3:
		cout << "the stack elements are" << endl;
		ls.display();
		break;
	}
	cout << "\nEnter an operation to perform:";
	cin >> i;
	}
}