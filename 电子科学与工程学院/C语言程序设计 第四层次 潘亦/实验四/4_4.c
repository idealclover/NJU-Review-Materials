#include<stdio.h>
#include<cstdlib>
int main()
{
	for(int n=100;n <=999;n++)
	{
		if (n % 37 == 0)
		{
			int a, b, c;
			a = n / 100;
			b = n / 10 % 10;
			c = n % 10;
			if (((100 * c + 10 * a + b) % 37) != 0)
			{
				printf("wrong"); return -1;
			}
			if (((b * 100 + c * 10 + a) % 37) != 0)
			{
				printf("wrong"); return -1;
			}
			printf("%d\n", n);
		}
	}
	system("pause");
	return 0;
}