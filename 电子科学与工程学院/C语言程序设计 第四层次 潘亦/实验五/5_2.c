#include<cstdio>
#include<cstdlib>
#include<cmath>
int main()
{
	int count = 1;
	for (int M = 2;; M++)
	{
		int m1;
		m1 = M;
		int n1 = 2;
		for (; n1 <= m1; n1++)
		{
			if (m1%n1 == 0) break;
		}
		if (n1 == m1)
		{
			for (int P = 2; P <= m1; P++)
			{
				int m2;
				m2 = P;
				int n2 = 2;
				for (; n2 <= m2; n2++)
				{
					if (m2%n2 == 0) break;
				}
				if (m2 == n2)
				{
					if ((pow(2, m2) - 1) == m1)
					{
						printf("%d\n", m1);
						count++;
						if (count == 6) break;
					}
				}
			}
		}
		if (count == 6) break;
	}
	system("pause");
	return 0;
}
