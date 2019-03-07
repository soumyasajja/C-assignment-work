#include <iostream>
#include <string>
#include <stack>
#define MAX_INPUT_STRING 30
using namespace std;
int add(int, int);
int sub(int, int);
long int mul(int, int);
int division(int, int);
bool areParanthesisBalanced(char expr[])
	{
		stack<char> ip_st;
		char stack_x;
		for (int count = 0; count < strlen(expr); count++)
		{
			if (expr[count] == '(' || expr[count] == '[' || expr[count] == '{')
			{
				ip_st.push(expr[count]);
				continue;
			}
			if (ip_st.empty())
				return true;
			switch (expr[count])
			{
			case ')':
				stack_x = ip_st.top();
				ip_st.pop();
				if (stack_x == '{' || stack_x == '[')
					return false;
				break;
			case '}':
				stack_x = ip_st.top();
				ip_st.pop();
				if (stack_x == '(' || stack_x == '[')
					return false;
				break;
			case ']':
				stack_x = ip_st.top();
				ip_st.pop();
				if (stack_x == '(' || stack_x == '{')
					return false;
				break;
			}
		}
		return (ip_st.empty());
	}
	int postfixeval(string ip_str) {
		stack<int> st;
		st.push(0);
		int num1, num2;
		int index = 0;

		for (index = 0; ip_str[index] != '\0'; index++) {
			if (isdigit(ip_str[index])) {
				int asc = (int)ip_str[index];
				st.push(asc - 48);
			}
			else {
				if (ip_str[index] == '*') {
					num1 = st.top();
					st.pop();
					num2 = st.top();
					st.pop();
					long int multip = mul(num1, num2);
					st.push(multip);
				}
				if (ip_str[index] == '/') {
					num1 = st.top();
					st.pop();
					num2 = st.top();
					st.pop(); try {
						int quotient = division(num1, num2);
						st.push(quotient);
					}
					catch (const char *err_msg) {
						cout << err_msg << endl;
					}
				}
				if (ip_str[index] == '+') {
					num1 = st.top();
					st.pop();
					num2 = st.top();
					st.pop();
					int sum = add(num1, num2);
					st.push(sum);
				}
				if (ip_str[index] == '-') {
					num1 = st.top();
					st.pop();
					num2 = st.top();
					st.pop();
					int diff = sub(num2, num1);
					st.push(diff);
				}
			}

		}
		cout << st.top();
		return 0;
	}
	int precedence(char ch)
	{
		if (ch == ']')
			return 6;
		else if (ch == '}')
			return 5;
		else if (ch == ')')
			return 4;
		else if (ch == '*' || ch == '/')
			return 3;
		else if (ch == '+' || ch == '-')
			return 2;
		else if (ch == '(' || ch == '{' || ch == '[')
			return 1;
			return -1;
	}
	int main() {
		stack<char> st;
		st.push('N');
		char *ip_str;
		string ns, ns1;
		ip_str = new char[MAX_INPUT_STRING];
		cout << "enter the input string\n";
		cin >> ip_str;
		if (areParanthesisBalanced(ip_str)) {
			cout << "Balanced" << endl;
		}
		else {
			cout << "Not Balanced" << endl;
			system("pause");
			return 0;
		}
		int len = strlen(ip_str);
		char ch;
		for (int i = 0; i < len; i++) {
			if (isdigit(ip_str[i])) {
				ns += ip_str[i];
			}
			else if (ip_str[i] == '[') {
				st.push(ip_str[i]);
			}
			else if (ip_str[i] == '{') {
				st.push(ip_str[i]);
			}
			else if (ip_str[i] == '(') {
				st.push(ip_str[i]);
			}
			else if (ip_str[i] == ')') {
				while (st.top() != 'N'&&st.top() != '(') {
					ch = st.top();
					st.pop();
					ns += ch;
				}
				if (st.top() == '(') {
					ch = st.top();
					st.top();
				}
			}
			else {
				while (st.top() != 'N'&&precedence(ip_str[i]) <= precedence(st.top())) {
					ch = st.top();
					st.pop();
					ns += ch;
				}
				st.push(ip_str[i]);
			}
		}
		while (st.top() != 'N') {
			ch = st.top();
			st.pop();
			ns += ch;
		}
		for (int i = 0; i < len; i++) {
			if (ns[i] == '('||ns[i]=='{'||ns[i]=='[') {
				continue;
			}
			ns1 += ns[i];
		}
		postfixeval(ns1);
		system("pause");
		delete ip_str;
		return 0;
	}
