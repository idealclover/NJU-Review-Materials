#include<cstdio>
#include<cstdlib>
int main()
{
	int n, p = 0;
	scanf_s("%d", &n);
	if (n >= 10)
	{
		while(n!= 0)
		{
			n = n / 10;
			p = p + 1;
		}
		printf("%d", p);
	}
	else printf("1");
	system("pause");
	return 0;
}