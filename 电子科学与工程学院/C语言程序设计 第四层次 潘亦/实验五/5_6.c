#include<cstdlib>
#include<cstdio>
int main()
{
	int a, b, c, d, count = 0;
	for (int a = 1; a <= 9; a++)
		for (int b = 1; b <= 8; b++)
			for (int c = 1; c <= 7; c++)
				for (int d = 1; d <= 6; d++)
					if (a + b + c + d == 23)
					{
						printf("(%d,%d,%d.%d)\n", a, b, c, d);
						count++;
					}
					else continue;
	printf("¹²%dÖÖ\n", count);
	system("pause");
	return 0;
}