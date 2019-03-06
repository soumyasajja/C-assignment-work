#include <iostream>
#include <string>
#include <stack>
using namespace std;
int add(int, int);
int sub(int, int);
long int mul(int, int);
int division(int, int);
bool areParanthesisBalanced(string expr)
	{
		stack<char> ip_str;
		char stack_x;
		for (int count = 0; count < expr.length(); count++)
		{
			if (expr[count] == '(' || expr[count] == '[' || expr[count] == '{')
			{
				ip_str.push(expr[count]);
				continue;
			}
			if (ip_str.empty())
				return true;
			switch (expr[count])
			{
			case ')':
				stack_x = ip_str.top();
				ip_str.pop();
				if (stack_x == '{' || stack_x == '[')
					return false;
				break;
			case '}':
				stack_x = ip_str.top();
				ip_str.pop();
				if (stack_x == '(' || stack_x == '[')
					return false;
				break;
			case ']':
				stack_x = ip_str.top();
				ip_str.pop();
				if (stack_x == '(' || stack_x == '{')
					return false;
				break;
			}
		}
		return (ip_str.empty());
	}
	int postfixeval(string ip_str) {
		stack<double> st;
		st.push(0);
		double c1, c2;
		int i = 0;

		for (i = 0; ip_str[i] != '\0'; i++) {
			if (isdigit(ip_str[i])) {
				int asc = (int)ip_str[i];
				//cout<<a-48;
				st.push(asc - 48);
			}
			else {
				if (ip_str[i] == '*') {
					c1 = st.top();
					st.pop();
					c2 = st.top();
					st.pop();
					long int multip = mul(c1, c2);
					st.push(multip);
				}
				if (ip_str[i] == '/') {
					c1 = st.top();
					st.pop();
					c2 = st.top();
					st.pop();
					int quotient = division(c1, c2);
					st.push(quotient);
				}
				if (ip_str[i] == '+') {
					c1 = st.top();
					st.pop();
					c2 = st.top();
					st.pop();
					int sum = add(c1, c2);
					st.push(sum);
				}
				if (ip_str[i] == '-') {
					c1 = st.top();
					st.pop();
					c2 = st.top();
					st.pop();
					int diff = sub(c2, c1);
					st.push(diff);
				}
			}

		}
		cout << st.top();
		return 0;
	}
	int precedence(char c)
	{
		if (c == '*' || c == '/')
			return 2;
		else if (c == '+' || c == '-')
			return 1;
		else
			return -1;
	}
	int main() {
		stack<char> st;
		st.push('N');

		string s, ns, ns1;
		cin >> s;
		if (areParanthesisBalanced(s)) {
			cout << "Balanced" << endl;
		}
		else {
			cout << "Not Balanced" << endl;
			system("pause");
			return 0;
		}
		int l = s.length();
		char c;

		for (int i = 0; i < l; i++) {
			if (isdigit(s[i])) {
				ns += s[i];
			}
			else if (s[i] == '(') {
				st.push(s[i]);
			}
			else if (s[i] == ')') {
				while (st.top() != 'N'&&st.top() != '(') {
					c = st.top();
					st.pop();
					ns += c;
				}
				if (st.top() == '(') {
					c = st.top();
					st.top();
				}
			}
			else {
				while (st.top() != 'N'&&precedence(s[i]) <= precedence(st.top())) {
					c = st.top();
					st.pop();
					ns += c;
				}
				st.push(s[i]);
			}
		}
		while (st.top() != 'N') {
			c = st.top();
			st.pop();
			ns += c;
		}
		for (int i = 0; i < l; i++) {
			if (ns[i] == '(') {
				continue;
			}
			ns1 += ns[i];
		}
		postfixeval(ns1);
		system("pause");
		return 0;
	}
