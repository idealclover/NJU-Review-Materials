#include<cstdlib>
#include<cstdio>
int main()
{
	for (int i = 100; i <= 999; i++)
	{
		int m,a1=0,a2=0,a3=0;
		m = i;
		int h = 2;
		for (; h <= m; h++)
		{
			if (m%h == 0) break;
		}
		if (h == m)
		{
			a1 = m / 100; a2 = m / 10 % 10; a3 = m % 10;
			if ((a2 + a3) % 10 == a1) printf("%d\n", m);
		}
	}
	system("pause");
	return 0;
}