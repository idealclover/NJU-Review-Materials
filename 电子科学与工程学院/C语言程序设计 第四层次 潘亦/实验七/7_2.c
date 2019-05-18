#include<stdio.h>
#include<cmath>
using namespace std;
int prime(int);										//声明确定素数的函数
int main()
{
	int m, n;
	int count = 0;
	scanf_s("%d%d", &m, &n);
	for (; m <= n - 2; m++)										//从m开始迭代到n寻找素数
	{
		if (prime(m) == 1)										//如果是素数，确定其加二后是否为素数
		{
			if (prime(m + 2) == 1)
			{
				printf("(%d,%d)\n", m, m + 2);					//加二后也为素数则输出
				++count;										//记录孪生数的对数  
			}
		}
		else
			if (m == (n - 2) && count == 0) 
				printf("该区间内没有孪生数\n");					//迭代到m-2时仍未找到素数则该区间没有孪生素数
			else if ((m == (n - 2)) && count != 0)
				printf("该区间内的孪生数有%d对\n", count);
	}
	system("pause");
	return 0;
}
int prime(int n)												//定义函数判断函数接受数是否为素数
{
	int i = 2;
	for (; i < sqrt(n); i++)
	{
		if (n%i == 0) return 0;									//不是素数，返回0
	}
	if (i >= sqrt(n)) return 1;									//是素数，返回1
}