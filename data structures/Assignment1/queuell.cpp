#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class queue
{
	struct node *front,*rear;
public:
	queue();
	void enque(int ele);
	int deque();
	void display();
	~queue();
};
queue::queue()
{
	front = NULL;
	rear = NULL;
}
void queue::enque(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (rear == NULL)
	{
		front = rear = temp;
		rear->next = NULL;
	}
	else
	{ 
		rear->next = temp;
		rear = temp;
		rear->next = NULL;
	}
}
int queue::deque()
{
	struct node *temp;
	int x;
	temp = new node;
	if (front == NULL)
	{
		cout << "empty queue";
		//return 2;
	}
	else
	{
		temp = front;
		x = temp->data;
		front = front->next;
		delete(temp);
		return x;
	}
}
void queue::display()
{
	if (rear != NULL)
	{
		struct node *temp;
		temp = new node;
		temp = rear;
		cout << temp->data;
		temp = temp->next;
	}
}
queue::~queue()
{
	struct node *temp;
	while (rear!= NULL)
	{
		temp = rear;
		rear = temp->next;
		delete temp;
	}
}
int main()
{
	queue que;
	int i, ele, e1;
	cout << "enter the operation to be performed\n 1.enque\n 2.deque\n 3.display\n";
	cin >> i;
	while (i <= 10)
	{
		switch (i)
		{
		case 1:
			cout << "enter an element" << endl;
			cin >> ele;
			que.enque(ele);
			break;
		case 2:
			e1 = que.deque();
			cout << "the dequed element is" << e1 << endl;
			break;
		case 3:
			cout << "the queue elements are" << endl;
			que.display();
			break;
		}
		cout << "enter an operation to be performed\n";
		cin >> i;
	}
}