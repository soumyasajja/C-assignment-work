namespace Namespace2
{
	extern int Add(int &num1, int &num2)
	{
		int res_add;
		res_add = num1 + num2;
		return res_add;
	}
	extern int Sub(int &nleft, int &nright)
	{
		int res_sub = nleft - nright;
		return res_sub;
	}
}