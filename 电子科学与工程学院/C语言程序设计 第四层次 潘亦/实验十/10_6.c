#include<iostream>
using namespace std;
//定义函数判断素数
int isPrime(int num)
{
	int tmp = num - 1;
	for (int i = 2; i <= tmp; i++)
		if (num %i == 0)
			return 0;
	return 1;
}
int mpsort(int x[],int n)
{
	int Maxa, Last_Prime;
	//从数组中第一个数开始寻找偶数
	for (int i = 0; i <= n - 1; i++)
		if (x[i] % 2 == 0) { Maxa = i; break; }
	//从数组中第一个偶数开始寻找最大偶数
	for (int a = Maxa+1; a <= n - 1; a++)
	{
		if (x[a] % 2 == 0)
			if (x[a] > x[Maxa])
				Maxa = a;
	}
	//从数组最后一个元素开始寻找最后一个素数
	for(int b=n-1;b>=0;b--)
		if (isPrime(x[b]) == 1)
		{
			Last_Prime = b;
			break;
		}
	//下面使用效率较高的插入法进行排序
	int t, j;
	for (int i = Maxa + 1; i <= Last_Prime; i++)
	{
		t = x[i];
		for( j = i - 1; t<x[j] && j >= Maxa; j--)
			x[j + 1] = x[j];
		x[j + 1] = t;
	}
	//返回需要排序的元素个数
	return abs(Last_Prime - Maxa) + 1;
}
int main()
{
	int x[10], t;
	//从键盘中依次输入数组元素
	for (int i = 0; i <= 9; i++)
		cin >> x[i];
	t = mpsort(x, 10);
	//依次打印出数组元素
	for (int i = 0; i <= 9; i++)
		cout << x[i] << " ";
	cout << "t=" << t << endl;
	system("pause");
	return 0;
}
