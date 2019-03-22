#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
template <typename T>
struct _stack_
{
	int size;
	T *stack_ip;
	int top;
};
template <class T>
class Stack
{
	struct _stack_<T> sta;
public:
	Stack(int);
	void push(T);
	void pop();
	T peak();
	bool IsEmpty();
	bool IsFull();
	void display();
	//void getsize(int);
	~Stack();
};
template <class T>
Stack<T>:: ~Stack()
{
	delete sta.stack_ip;
}
template <class T>
Stack<T>::Stack(int s)
{
	sta.top = -1;
	sta.size = s;
	sta.stack_ip = new T[s];

}
template <class T>
bool Stack<T>::IsFull()
{
	return (sta.top == (sta.size - 1));
}

template <class T>
bool Stack<T>::IsEmpty()
{
	return (sta.top == -1);
}
template <class T>
void Stack<T>::push(T ele)
{
	if (!IsFull())
	{
		sta.stack_ip[++sta.top] = ele;
	}
	else
		cout << "Stack is full";
}
template <class T>
void Stack<T>::pop()
{
	T x;
	if (!IsEmpty())
	{
		x = sta.stack_ip[sta.top--];
		cout << "Popped element is " << x << endl;
	}
	else
		cout << "Stack is Empty";

}
template <class T>
T Stack<T>::peak()
{
	T x;
	if (!IsEmpty())
	{
		x = sta.stack_ip[sta.top];
	}
	else
		cout << "Stack is Empty";
	return x;
}
template <class T>
void Stack<T>::display()
{
	for (int i = 0; i <= sta.top; i++)
		cout << sta.stack_ip[i] << endl;
}
template <class T>
void operation(Stack<T> st_ip)
{
	int ch;
	T ele;
	cout << "\n 1.Push";
	cout << "\n 2.Pop";
	cout << "\n 3.Display\n";
	cout << "\n 4.push complex numbers";
	do
	{
		cout << "Enter your choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter a value to be inserted\n";
			cin >> ele;
			st_ip.push(ele);
			break;

		case 2:
			st_ip.pop();
			break;

		case 3:
			st_ip.display();
			break;
		}
	} while (ch != 3);

}
//Complex class to account for complex input
//class Complex
//{
//	float real;
//	float img;
//public:
//	void get_complex()
//	{
//		cout << "enter the real part of the complex number\n";
//		cin >> real;
//		cout << "enter the imaginary part of the complex number\n";
//		cin >> img;
//	}
//	void put_complex()
//	{
//		cout << "the complex number is" << real << "+i" << img << endl;
//	}
//};
int main()
{
	int ch, size1;
	/*Complex comp1, comp2, comp3;
	comp1.get_complex();
	comp2.get_complex();
	comp3.get_complex();*/
	cout << "\n 1.Integer stack";
	cout << "\n 2.Float stack";
	cout << "\n 3.Character stack";
	cout << "\nEnter the size of stack\n";
	cin >> size1;
	do
	{
		cout << "enter your choice\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			Stack<int> aint1(size1);//Integer array
			operation(aint1);
			break;
		}

		case 2:
		{
			Stack<float> bfloat(size1);//Float array
			operation(bfloat);
			break;
		}

		case 3:
		{
			Stack <char> c_ch(size1);//Character array
			operation(c_ch);
			break;
		}
		default: break;
		}

		cout << "\n 1.Integer stack";
		cout << "\n 2.Float stack";
		cout << "\n 3.Character stack";

	} while (ch != 4);
	getchar();
	//Stack<Complex> d_comp;
	return 0;
}
