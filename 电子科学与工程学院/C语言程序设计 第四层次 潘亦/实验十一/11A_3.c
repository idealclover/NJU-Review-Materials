#include<iostream>
#include<cstdio>
using namespace std;
//定义一个函数用于对数组进行赋值
void Fuzhi(int a[][10], int n)
{
	int k = 1, M = 0, p;
	int number = n*n;
	while (k <= number)
	{
		//最上一行赋值
		for (p = M; p < n; p++)
			a[M][p] = (k++);
		//最右一行赋值
		for (p = M + 1; p < n ; p++)
			a[p][n - 1] =( k++);
		//最下一行赋值
		for (p = n - 2; p >= M; p--)
			a[n - 1][p] = (k++);
		//最左一行赋值
		for (p = n - 2; p >= M + 1; p--)
			a[p][M] = (k++);
		M++, n--;
	}
}
//定义函数打印n*n方阵
void print(int a[][10], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int m = 0; m < n; m++)
			printf("%5d",a[i][m]);
		cout << endl;
	}
}
int main()
{
	int n;
	cin>> n;
	if (n > 10)
	{
		cout << "Type Error";
		return -1;
	}
	int a[10][10];
	cout << n << "*" << n << "方阵:"<<endl;
	Fuzhi(a, n);
	print(a, n);
	system("pause");
	return 0;
}