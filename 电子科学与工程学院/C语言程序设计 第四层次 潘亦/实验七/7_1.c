#include<iostream>
#include<cstdlib>
using namespace std;
int find(int);
int main()
{
	for (int i = 1000; i <= 9999; i++)//从第一个四位数1000遍历到最后一个
	{
		int m = find(i);
		if (m != 0) cout <<i<<" "<<m;
	}
	system("pause");
	return 0;
}
int find(int n)//定义函数find确定其是否为目标数
{
	int a, b, c, d;
	a = n / 1000;
	b = n / 100 % 10;
	c = n / 10 % 10;
	d = n % 10;
	int m = (1000 * d + 100 * c + 10 * b + a);
	if (m== 9 * n)
		return m;
	else return 0;
}