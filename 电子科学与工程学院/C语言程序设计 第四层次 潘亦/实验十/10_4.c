#include<iostream>
using namespace std;
//定义函数用bruter-force算法求解两个数的最大公约数
int Gcd(int a, int b)
{
	int z = a < b ? a : b;
	while ((a%z != 0) || (b%z != 0))
		z--;
	return z;
}
//定义函数求解剩余元素的最大公约数
int  Del_findgcd(int a[], int n, int *f)
{
	int m = 1;
	//去掉数组中的奇数下标元素并将偶数下标元素前移
	for (int i = 2; i <= n - 1; i+=2)
	{
		a[m++] = a[i];
	}
	//依次检索两个数间的最大公约数
	int GCD = Gcd(a[0], a[1]);
	for (int i = 2; i <= m - 1; i ++)
	{
		GCD = Gcd(GCD, a[i]);
	}
	*f = GCD;
	//返回元素中的剩余元素个数
	return m;
}
int main()
{
	int a[10] = { 6,  8,  9,   11,  12,  13,  15,  16,  18 , 19 };
	int n = 10; int f; 
	int number = Del_findgcd(a, n, &f);
	//依次打印出数组中的剩余元素
	for (int i = 0; i <= number - 1; i++)
		cout << a[i]<<" ";
	cout << ", " << "max common divisor is:" << f;
	system("pause");
	return 0;
}

