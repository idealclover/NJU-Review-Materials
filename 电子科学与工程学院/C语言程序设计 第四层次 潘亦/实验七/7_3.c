#include<iostream>
#include<cstdio>
using namespace std;
//定义函数CountDigit()对整数进行计数
int CountDigit(int n)				   
{
	int m = 0;
	while (n != 0)
	{
		n /= 10;
		++m;
	}
	return m;
}
//定义函数判断是否为勾股弦数
int f(int n)
{
	int a, b, c;
	if (CountDigit(n) == 3)
	{
		a = n / 100;
		b = n / 10 % 10;
		c = n % 10;
		if (a*a + b*b == c*c&&a!=0&&b!=0&&c!=0)
			return 1;
		else return 0;
	}
	else if (CountDigit(n) == 4)
	{
		a = n / 1000;
		b = n / 100 % 10;
		c = n - 1000 * a - 100 * b;
		if (a*a + b*b == c*c&&a != 0 && b != 0 && c != 0)
			return 1;
		else return 0;
	}
}
//试用main函数作为主体
int main()
{
	int m, n;
	cout << "请输入m和n的值:";
	M: cin >> m >> n;
	if ((m <= 100 || m >= 10000) || (n <= 100 || n >= 10000) || m >= n)
	{
		cout << "输入错误请重新输入:";
		goto M;
	}
	for (; m <= n; m++)
	{
		if (f(m) == 1)
		{
			if (CountDigit(m) == 3)
				printf("%d:%d*%d+%d*%d=%d*%d\n", m, m / 100, m / 100, m / 10 % 10, m / 10 % 10, m % 10, m % 10);
			else 
				printf("%d:%d*%d+%d*%d=%d*%d\n", m, m / 1000, m / 1000, m / 100 % 10, m / 100 % 10, m-m/100*100, m - m / 100*100);
		}
	}
	system("pause");
	return 0;
}