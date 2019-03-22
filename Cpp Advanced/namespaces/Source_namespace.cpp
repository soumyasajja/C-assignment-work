#include <iostream>
#include <stdlib.h>
namespace CounterNamespace
{
	int lowerBound;
	namespace NCRnamespace {
		int upperBound;
	}
}
namespace CounterNamespace
{
	class Counter
	{
		int count;
	public:
		Counter(int c_1)
		{
			count = c_1;
		}
		int increaseCount()
		{
			count++;
			if (count > NCRnamespace::upperBound)
				return NCRnamespace::upperBound;
			else
				return count;
			getchar();
		}
		int decreaseCount()
		{
			count--;
			if (count < lowerBound)
				return lowerBound;
			else
				return count;
			getchar();
		}
	};
}
using namespace std;
using namespace CounterNamespace;
int main()
{
	cout << "enter the lower bound for counting:\n";
	cin >> lowerBound;
	cout << "enter the upper bound for counting:\n";
	cin >> CounterNamespace::NCRnamespace::upperBound;
	Counter cnt(5);
	for (int loop = 0; loop < 20; loop++)
		cout << cnt.increaseCount()<<endl;
	//cout << cnt.decreaseCount()<<endl;
	cout << "waiting for input:\n";
	getchar();
	return 0;
}