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
	int Delete_Spec(int);
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
		curr = start;
		while (curr != NULL && curr->data != sele)
			curr = curr->next;
		if (curr != NULL)
		{

		}
	}
}