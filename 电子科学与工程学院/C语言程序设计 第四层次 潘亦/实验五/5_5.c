#include<cstdlib>
#include<cstdio>
int main()
{
	for (int n = 317; n <= 999; n++)
	{
		long int m = n*n;
		int a1, a2, a3, a4, a5, a6;
		a1 = m / 100000;
		a2 = m / 10000 % 10;
		a3 = m / 1000 % 10;
		a4 = m / 100 % 10;
		a5 = m / 10 % 10;
		a6 = m % 10;
		if (a1 == a6&&a2 == a5&&a3 == a4) printf("%d", m);
		else continue;
	}
	system("pause");
	return 0;
}