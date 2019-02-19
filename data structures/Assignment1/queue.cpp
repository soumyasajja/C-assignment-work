#include <iostream>
using namespace std;
struct __queue__
{
	int front;
	int rear;
	int size;
	int *data;
};
class _queue_
{
	struct __queue__ q;
public:
	_queue_();
	bool underflow();
	bool overflow();
	void enque(int);
	int deque();
	void getsize(int);
	void display();
	~_queue_();
};
_queue_::_queue_()
{
	q.front = -1;
	q.rear = -1;
	q.size = 0;
}
void _queue_::getsize(int n)
{
	q.size = n;
	q.data = new int[n];
}
bool _queue_::underflow()
{
	return(q.rear == -1 && q.front == -1);
}
bool _queue_::overflow()
{
	return(q.rear == (q.size - 1));
}
void _queue_::enque(int ele)
{
	if (!overflow())
	{
		if (q.front == -1)
		{
			q.front = 0;
		}
		q.data[++q.rear] = ele;
	}
	else
		cout << "overflow";
}
int _queue_::deque()
{
	int x;
	if (!underflow())
	{
		if (q.front == q.rear)
		{
			x = q.data[q.front];
			q.front = -1;
			q.rear = -1;
		}
		else
			x = q.data[q.front++];
	}
	else
		cout << "underflow";
	return x;
}
void _queue_::display()
{
	for (int i = q.front; i <=q.rear; i++)
		cout << q.data[i];
}
_queue_::~_queue_()
{
	delete q.data;
}
int main()
{
	_queue_ que;
	int n,ch;
	cout<< "enter the size of the queue" << endl;
	cin >> n;
	que.getsize(n);
	cout << "enter the choice 1) enque 2)deque 3)display" << endl;
	cin >> ch;
	switch (ch)
	{
	case 1:
		int x;
		cout << "enter the element to be queued" << endl;
		cin >> x;
		que.enque(x);
		break;
	case 2:
		int y;
		y = que.deque();
		cout << "the dequed element is" << y << endl;
		break;
	case 3:
		que.display();
		break;
	}
	return 0;
}