#include <stdio.h>
#include<cstdlib>
#define  M  10
void swap(int *x, int *y)
{
	int t;
	t = *x; *x = *y; *y = t;
}
void change(int a[][M], int n)
{
	int  i, j, c;
	for (i = 0; i<n / 2; i++)
		for (j = n / 2 + 1; j<n; j++)
			swap(&a[i][j], &a[i + n / 2+1 ][j - n / 2 - 1]);
}
void print(int a[][M], int n)
{
	int  i, j;
	printf("\n");
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
}
int main(void)
{
	int a[M][M], i, j, n = 0;
	printf("\nINPUT N (N<10):");
	scanf_s("%d", &n);
	if (n >= 10 || n % 2 == 0)
	{
		printf(" can't do it");
		return -1;
	}
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			a[i][j] = i*n + j;
	print(a, n);
	change(a,n);
	print(a, n);
	system("pause");
	return 0;
}
