#include<iostream>
using namespace std;
int C = 0;
#define N 10;
int com(int *a, int *b, int *c)
{
	//先求出数组的大小
	int Num_a = N;
	int Num_b = N;
	//将三个数组以及相同数量初始化
	int A = 0, B = 0, count = 0;
	while ((A < Num_a)&&(B < Num_b))
	{
		if (a[A] == b[B])
				A++, B++, count++;
		else if (a[A] > b[B])
				c[C++] = b[B], B++;
		else if (a[A] < b[B])
				c[C++] = a[A], A++;
	}
	//如果某数组仍未检查完,则将剩余元素加到后面
	if (A <= Num_a - 1)
		for (;A <= Num_a - 1; A++)
			c[C++] = a[A];
	if (B <= Num_b - 1)
		for (;B <= Num_b - 1; B++)
			c[C++] = a[B];
	return count;
}
int main()
{
	int a[10] = { 3,6,7,18,23,33,35,43,48,78 };
	int b[10] = { 2,7,13,21,33,37,48,50,58,67};
	int c[20];
	int count = com(a, b, c);
	for (int m = 0; m <= C-1; m++)
		cout << c[m]<<" ";
	cout << endl;
	cout << "count="<<count<<endl;
	system("pause");
	return 0;
}