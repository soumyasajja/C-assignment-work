#include <iostream>
using namespace std;
//defining node
struct node                           
{
	int data;
	struct node *next;
};
//class for linked list
class _LL_
{
	struct node *start;
public:
	_LL_();                                        //constructor
	void Insert_First(int ele);                   //insert at the beginnign of the list
	void Insert_Last(int ele);
	void Insert_position(int position, int ele); //insert at a certain position
	void print_forward();
	void print_backward();
	void reverse_list();
	void Delete_value(int ele);                 //delete value
	~_LL_();
	friend void print(struct node *);
};
_LL_::_LL_()  //constructor initialization
{
	start = NULL;
}
void _LL_::Insert_First(int ele)    //insert at the beginning
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
void _LL_::Insert_position(int ele, int position)  //insert a given position
{
	struct node *temp, *curr;
	temp = new node;
	temp->data = ele;
	int node_val = 1;
	curr = start;
	while (curr!= NULL && node_val != position)
	{
		curr = curr->next;
		node_val++;
	}
	if (curr!= NULL)
	{
		temp->next = curr->next;
		curr->next = temp;
	}
}
void _LL_::print_forward()     //print the linked list in forward direction
{
	struct node *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data;
		curr = curr->next;
	}
}
void _LL_::print_backward()   //print the list in reverse direction
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
void _LL_::Insert_Last(int ele)  //insert at the ending of the list
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
	{
		temp->next = start;
		start = temp;
	}
	else
	{
		struct node *curr;
		curr = start;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		temp = curr->next;
	}
}
void _LL_::Delete_value(int ele)  //delete a specific value
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
void _LL_::reverse_list()    //reverse the list
{
	struct node *rev,*temp;
	rev = NULL;
	if (start != NULL)
	{
		if (start->next != NULL)
		{
			while (start != NULL)
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
_LL_::~_LL_()   //destructor to free the memory
{
	struct node *temp;
	while (start != NULL)
	{
		temp = start;
		start = temp->next;
		delete temp;
	}
}
int main()   //main program
{
	_LL_ lis;
	cout << "Enter an operation to perform.\n 1.Insert_first\n 2.Insert_last\n 3.Insert at a postion\n";
	cout <<"4.Delete value\n 5.print forward\n 6.print backward\n 7.reverse the list\n";
	int ch;
	int ele, e1,position;
	cin >> ch;
	while (ch <= 7)
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
			cout << "enter the position of placing the element\n";
			cin >> position;
			lis.Insert_position(ele,position);
			break;
		case 4:cout << "enter a value to be deleted\n";
			cin >> ele;
			lis.Delete_value(ele);
			break;
		case 5: lis.print_forward();
			break;
		case 6: lis.print_backward();
			break;
		case 7:cout << "After reversing\n";
			lis.reverse_list();
			lis.print_forward();
			break;
		}
		cout << "\nEnter an operation to perform:";
		cin >> ch;
	}
	return 0;
}