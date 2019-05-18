double power(double x, int n)
{	if (x == 0) return 0;
	double product=1.0;
	if (n >= 0)
		while (n > 0)
		{	product *= x;
			n--;
		}
	else
		while (n < 0)
		{	product /= x;
			n++;
		}
	return product;
}
