#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
class _DLL_
{
	struct node *start;
public:
	_DLL_();
	void Insert_First(int);
	void Insert_Last(int);
	void Insert_After(int, int);
	void Insert_Before(int, int);
	int Delete_First();
	int Delete_Last();
	void Delete_Spec(int);
	void traverse_forward();
	void traverse_backward();
	~_DLL_();
};
_DLL_::_DLL_()
{
	start = NULL;
}
void _DLL_::Insert_First(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->prev = NULL;
	temp->next = start;
	if(start!=NULL)
	{
		start->prev = temp;
		start = temp;
	}
}
void _DLL_::Insert_Last(int ele)
{
	struct node *temp, *curr;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		temp->prev = curr;
		curr->next = temp;
	}
}
void _DLL_::Insert_After(int sele, int ele)
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL && curr->data != sele)
			curr = curr->next;
		if (curr != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->prev = curr;
			temp->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = temp;
			curr->next = temp;
		}
		else
			cout << "element not found";
	}
	else
		cout << "List is empty";
}
void _DLL_::Insert_Before(int sele, int ele)
{
	if (start != NULL)
	{
		struct node *curr, *temp;
		curr = start;
		while (curr != NULL && curr->data != sele)
			curr = curr->next;
		if (curr != NULL)
		{
			temp = new node;
			temp->data = ele;
			temp->prev = curr->prev;
			temp->next = curr;
			if (curr->prev != NULL)
				curr->prev->next = temp;
			else
				start = temp;
			curr->prev = temp;
		}
		else
			cout << "element not found";
	}
	else
		cout << "List is empty";
}
int _DLL_::Delete_First()
{
	int x = -1;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		start = temp->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "List is empty";
	return x;
}
int _DLL_::Delete_Last()
{
	int x = -1;
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		x = curr->data;
		if (curr->prev != NULL)
			curr->prev->next = NULL;
		else
			start = NULL;
		delete curr;
	}
	else
		cout << "List is empty";
	return x;
}
void _DLL_::Delete_Spec(int ele)
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL && curr->data != ele)
			curr = curr->next;
		if (curr != NULL)
		{
			if (curr->prev != NULL)
				curr->prev->next = curr->next;
			else
				start = curr->next;
			if (curr->next != NULL)
				curr->next->prev = curr->prev;
			delete curr;
		}
		else
			cout << "element not found";
	}
	else
		cout << "List is empty";
}
void _DLL_::traverse_forward()
{
	struct node *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data;
		curr = curr->next;
	}
}
void _DLL_::traverse_backward()
{
	struct node *curr;
	if (start != NULL)
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		while (curr != NULL)
		{
			cout << curr->data;
			curr = curr->prev;
		}
	}
}
_DLL_::~_DLL_()
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
	_DLL_ dll;
	cout << "Enter an operation to perform. \n1.Insert_first\n2.Insert_last\n3.Insert_after\n4.Insert_before\n";
	cout << "5.Delete_first\n 6.Delete_last\n7.Delete_ele\n8.Travel_forward\n9.Travel_backward\n";
	int ch;
	int ele, e1;
	cin >> ch;
	while (ch <= 10)
	{
		switch (ch)
		{
		case 1:cout << "\nEnter an element";
			cin >> ele;
			dll.Insert_First(ele);
			break;
		case 2: cout << "\nEnter an element";
			cin >> ele;
			dll.Insert_Last(ele);
			break;
		case 3: cout << "Enter an element";
			cin >> ele;
			dll.Insert_After(ele, 3);
			break;
		case 4: cout << "Enter an element";
			cin >> ele;
			dll.Insert_Before(ele, 3);
			break;
		case 5: e1 = dll.Delete_First();
			cout << "\nDeleted element is:" << e1;
			break;
		case 6: e1 = dll.Delete_Last();
			cout << "\nDeleted element is:" << e1;
			break;
		case 7: dll.Delete_Spec(7);
			break;
		case 8: dll.traverse_forward();
			break;
		case 9: dll.traverse_backward();
			break;
		}
		cout << "\nEnter an operation to perform:";
		cin >> ch;
	}
	return 0;
}