#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
//定义函数CountDigit()返回整数位数
int CountDigit(long int n)
{
	int m = 0;
	while (n != 0)
	{
		n /= 10;
		++m;
	}
	return m;
}
//定义函数求反序数
long int IntRevs(long int x)
{
	long int Rx = 0;
	for (int i = 1; i <= CountDigit(x); i++)
		Rx += (x / (long int)(pow(10, i - 1)) % 10 * ((long int)pow(10, (CountDigit(x) - i))));
	return Rx;
}
//定义一个函数判断回文数，是则返回1，否则返回-1
int Palin_Num(long int n)
{
	//当n为偶数时
	if (CountDigit(n) % 2 == 0)
	{
		int Front = n / (long int)pow(10, CountDigit(n) / 2);
		if (Front == IntRevs(n - Front*(long int)pow(10, CountDigit(n) / 2)))
			return 1;
		else return -1;
	}
	//当n为奇数时
	else
	{
		int Front = n / (long int)pow(10, (CountDigit(n) + 1) / 2);
		if (Front == IntRevs(n - (n / (long int)pow(10, (CountDigit(n) - 1) / 2)*(long int)pow(10, (CountDigit(n) - 1) / 2))))
			return 1;
		else return -1;
	}
}
//定义函数返回回文数
int fun(long n, long *hw)
{
	long int m;
	for (int count = 1;; ++count)
	{
		m = IntRevs(n);
		n = m + n;
		if (count >= 10000) return -1;
		if (Palin_Num(n) == 1)
		{
			*hw = n;
			return count;
		}
	}
}
int main()
{
	long a, b, c;
	cin >> a;
	c = fun(a, &b);
	cout << b << "," << c;
	system("pause");
	return 0;
}
