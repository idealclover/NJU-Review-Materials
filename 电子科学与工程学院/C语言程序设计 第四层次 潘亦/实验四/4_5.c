#include<cstdio>
#include<cstdlib>
int complex(int a);
//主程序体
int main()
{
	int n, n1, n2, n3, l = 1;
	scanf_s("%d", &n);
	n1 = n / 100;
	n2 = n / 10 % 10;
	n3 = n % 10;
	if (n1 == n2&&n1 == n3) return -1;
	else
	{
		while (n != 495 && l <= 7)
		{
			printf("%d\n", n);
			n = complex(n);
			l++;
		}
		printf("%d", n);
	}
	system("pause");
	return 0;
}
//定义一个函数为循环体
int complex(int a)
{
	int a1, a2, a3, t,m;
	a1 = a / 100;
	a2 = (a / 10)% 10;
	a3 = a % 10;
	if (a1 <=a2) { t = a1; a1 = a2; a2 = t;}
	if (a1  <=a3) { t = a1; a1 = a3; a3 = t;}
	if (a2 <= a3) { t = a2; a2 = a3; a3 = t;}
	m = (a1 * 100 + a2 * 10 + a3) - (a3 * 100 + a2 * 10 + a1);
	return m;
}