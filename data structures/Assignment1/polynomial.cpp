#include <iostream>
using namespace std;
struct node
{
	int coefft;
	int power;
	struct node *next;
};
class poly
{
	struct node *start;
public:
	poly();
	void insert_begin(int coef,int power);
	void insert_end(int coef, int power);
	friend void add_poly(poly,poly,poly&);
	void display();
	~poly();
};
poly::poly()
{
	start = NULL;
}
void poly::insert_begin(int coeff,int power)
{
	struct node *temp;
	temp = new node;
	temp->coefft = coeff;
	temp->power = power;
	temp->next = start;
	start = temp;
}
void poly::insert_end(int coef, int power)
{
	struct node *temp, *curr;
	temp = new node;
	temp->coefft = coef;
	temp->power = power;
	temp->next = NULL;
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
	//cout << curr->data;
}
void add_poly(poly l1, poly l2,poly &l3)
{
	struct node *c1, *c2;
	c1 = l1.start;
	c2 = l2.start;
	while (c1 != NULL && c2 != NULL)
	{
		if (c1->power == c2->power)
		{
			l3.insert_end((c1->coefft + c2->coefft), c1->power);
			c1 = c1->next;
			c2 = c2->next;
		}
		else if (c1->power > c2->power)
		{
			l3.insert_end(c1->coefft, c1->power);
			c1 = c1->next;
		}
		else
		{
			l3.insert_end(c2->coefft, c2->power);
			c2 = c2->next;
		}
	}
	while (c1 != NULL)
	{
		l3.insert_end(c1->coefft, c1->power);
		c1 = c1->next;
	}
	while (c2 != NULL)
	{
		l3.insert_end(c2->coefft, c2->power);
		c2 = c2->next;
	}
}
void poly::display()
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL)
		{
			cout << curr->coefft;
			cout << curr->power;
			curr = curr->next;
		}
	}
}
poly::~poly()
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
	poly l1, l2,l3;
	int coef, power,ch,flag;
	cout << "enter an operation to perform\n 1.enter the 1st polynomial\n 2.enter the second polynomial\n 3.add the two polynomials\n 4.display all the polynomials\n";
	cin >> ch;
	while (ch < 10)
	{
		switch (ch)
		{
		case 1:
			cout << "enter the coefficient\n";
			cin >> coef;
			cout << "enter the power\n";
			cin >> power;
			while (flag)
			{
				l1.insert_begin(coef, power);
			}
			break;
		case 2:
			cout << "enter the coefficient\n";
			cin >> coef;
			cout << "enter the power\n";
			cin >> power;
			l2.insert_begin(coef, power);
			break;
		case 3:
			add_poly(l1, l2,l3);
			break;
		case 4:
			l1.display();
			l2.display();
			l3.display();
			break;
		}
	}
	return 0;
}