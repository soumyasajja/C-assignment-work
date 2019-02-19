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
	void Insert_First(int);
	void Insert_Last(int);
	void Insert_After(int, int);
	void Insert_Before(int, int);
	int Delete_First();
	int Delete_Last();
	void Delete_Spec(int);
	void Travel_Forward();
	void Travel_Backward();
	void reverse();
	~__List__();
	friend void print(struct node*);
};
__List__::__List__()
{
	start = NULL;
}
void __List__::Insert_First(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next=start;
	start = temp;
	cout << start->data;
}
void __List__::Insert_Last(int ele)
{
	struct node *temp, *curr;
	temp = new node;
	temp->data = ele;
	temp->next=NULL;
	if (start == NULL)
		start = temp;
	else
	{
		curr = start;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}
	cout << curr->data;
}
void __List__::Insert_After(int sele, int ele)
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL && curr->data != sele)
			curr = curr->next;
		if (curr!=NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "element not found" << endl;
	}
	else
		cout << "List is empty";
}
void __List__::Insert_Before(int sele, int ele)
{
	if (start != NULL)
	{
		if (start->data == sele)
		{
			struct node *temp;
			temp->data = ele;
			temp->next = start;
			start = temp;
		}
		else
		{
			struct node *curr;
			curr = start;
			while (curr->next != NULL && curr->next->data != sele)
				curr = curr->next;
			if (curr->next != NULL)
			{
				struct node *temp;
				temp = new node;
				temp->data = ele;
				temp->next = curr->next;
				curr->next = temp;
			}
			else
				cout << "element not found" << endl;
		}
	}
	else
		cout << "List is empty";
}
int __List__::Delete_First()
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
int __List__::Delete_Last()
{
	int x = -1;
	if (start != NULL)
	{
		if (start->next == NULL)
		{
			x = start->data;
			delete start;
			start = NULL;
		}
		else
		{
			struct node *curr;
			curr = start;
			while (curr->next->next != NULL)
				curr = curr->next;
			x = curr->next->data;
			delete curr->next;
			curr->next = NULL;
		}
	}
	else
		cout << "List is empty";
	return x;
}
void __List__::Delete_Spec(int ele)
{
	struct node *temp, *curr;
	if (start != NULL)
	{
		if (start->data == ele)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
		else
		{
			curr = start;
			while (curr->next != NULL && curr->next->data != ele)
				curr = curr->next;
			if (curr->next != NULL)
			{
				temp = curr->next;
				curr->next = temp->next;
				delete temp;
			}
			else
				cout << "element not found";
		}
	}
	else
		cout << "List is empty";
}
void __List__::Travel_Forward()
{
	struct node *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data;
		curr = curr->next;
	}
}
void __List__::Travel_Backward()
{
	if (start != NULL)
		print(start);
}
void print(struct node *curr)
{
	if (curr != NULL)
	{
		print(curr->next);
			cout << curr->data;
	}
}
void __List__::reverse()
{
	struct node *rev,*temp;
	rev = NULL;
	if (start != NULL)
	{
		if (start->next != NULL)
		{
			while(start!=NULL)
			{
				temp = start;
				start = temp->next;
				temp->next = rev;
				rev = temp;
			}
		}
		start = rev;
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
	__List__ lis;
	cout << "Enter an operation to perform. \n1.Insert_first\n2.Insert_last\n3.Insert_after\n4.Insert_before\n";
	cout << "5.Delete_first\n 6.Delete_last\n7.Delete_ele\n8.Travel_forward\n9.Travel_backward\n10.reverse\n";
	int ch;
	int ele, e1;
	cin >> ch;
	while (ch <= 10)
	{
		switch (ch)
		{
		case 1:cout << "\nEnter an element";
			cin >> ele;
			lis.Insert_First(ele);
			break;
		case 2: cout << "\nEnter an element";
			cin >> ele;
			lis.Insert_Last(ele);
			break;
		case 3: cout << "Enter an element";
			cin >> ele;
			lis.Insert_After(ele, 3);
			break;
		case 4: cout << "Enter an element";
			cin >> ele;
			lis.Insert_Before(ele, 3);
			break;
		case 5: e1 = lis.Delete_First();
			cout << "\nDeleted element is:" << e1;
			break;
		case 6: e1 = lis.Delete_Last();
			cout << "\nDeleted element is:" << e1;
			break;
		case 7: lis.Delete_Spec(7);
			break;


		case 8: lis.Travel_Forward();
			break;
		case 9: lis.Travel_Backward();
			break;
		case 10:cout << "After reversing\n";
			lis.reverse();
			lis.Travel_Forward();
			break;
		}
		cout << "\nEnter an operation to perform:";
		cin >> ch;
	}
	return 0;
}