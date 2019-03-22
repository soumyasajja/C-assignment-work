#include <iostream>
using namespace std;
class Deque
{
	int front;
	int rear;
	int *data;
	int size;
public:
	Deque();
	bool overflow();
	bool underflow();
	void get_size(int size_deque);
	void insert_front(int ele);
	void insert_rear(int ele);
	int delete_front();
	int delete_rear();
	~Deque();
};
Deque::Deque()
{
	front = -1;
	rear = -1;
	data = NULL;
	size = 0;
}
void Deque::get_size(int size_deque)
{
	data = new int[size_deque];
	size = size_deque;
}
bool Deque::overflow()
{
	return(rear == size);
}
bool Deque::underflow()
{
	return((front == -1) && (rear == -1));
}
void Deque::insert_rear(int ele)
{
	if (!overflow)
	{
		if (front == -1)
			front = 0;
		data[++rear] = ele;
	}
	else
		cout << "overflow\n";
}
void Deque::insert_front(int ele)
{
	if (front <= 0)
		cout << "Cannot insert element at front\n";
	else
		data[--front] = ele;
}
int Deque::delete_rear()
{
	int del_rele;
		del_rele = data[rear];
		if (front == rear)
		{
			front = 0;
			rear = 0;
		}
		else
			rear = rear + 1;
		cout << "the deleted element is:" << del_rele << endl;
	return del_rele;
}
int Deque::delete_front()
{
	int del_fele;
	if (!underflow)
	{
		del_fele = data[front];
		if (front == rear)
		{
			front = 0;
			rear = 0;
		}
		else
			front = front + 1;
	}
}
