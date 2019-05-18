#include<stdio.h>
#include<cstdlib>
#include<cmath>
int main()
{
	double x; int m=0;
	scanf_s("%lf", &x);
	if (abs(x) >= 1)
	{
		while (abs(x) >= 1)
		{
			m = m + 1;
			x = x / 10;
		}
		printf("%.4fe%d", x, m);
	}
	else if (abs(x) <= 0.1)
	{
		while (abs(x) <= 0.1)
		{
			m = m - 1;
			x = x * 10;
		}
		printf("%.4fe%d", x, m);

	}
	else
	{
		printf("%.4fe0", x);
	}
	system("pause");
	return 0;
}