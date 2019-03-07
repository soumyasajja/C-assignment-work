extern int division(int num1, int num2)
{
	if (num1 == 0)
	{
		throw"Tried division by 0. Not possible\n";
	}
	return(num2 / num1);
}