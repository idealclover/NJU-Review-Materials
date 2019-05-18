#include<cstdio>
#include<cstdlib>
int main()
{
	int n,m;
	scanf_s("%d", &n);
	if (n >= 100) return -1;
	m = n;
	printf("%d=", n);
	for (int k = 2; k < m; k++)
	{
		while (n%k == 0)
		{
			printf("%d", k);
			if (n / k != 1) printf("*");
			n = n / k;
		}
	}
	system("pause");
	return 0;
}