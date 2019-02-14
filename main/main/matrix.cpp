#include <iostream>
using namespace std;
class Matrix
{
	int mat[2][2];
public:
	void getElements()
	{
		cout << "enter the matrix elements" << endl;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cin >> mat[i][j];
			}
		}
	}
	friend void mat_mult(Matrix, Matrix);
};
void mat_mult(Matrix m1, Matrix m2)
{
	Matrix m3;
	int i, j, k;
	for (i = 0; i < 2; ++i)
	{
		for (j = 0; j < 2; ++j)
		{
			for (k = 0; k < 2; ++k)
			{
				m3.mat[i][j] = 0;
				m3.mat[i][j] += m1.mat[i][k] * m2.mat[k][j];
			}
		}
	}
	cout << "output matrix" << endl;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			cout << " " << m3.mat[i][j];
			if (j == 1)
				cout << endl;
		}
	}
}
int main()
{
	Matrix m1, m2;
	m1.getElements();
	m2.getElements();
	mat_mult(m1, m2);
	return 0;
}