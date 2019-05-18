#include<iostream>
#include<math.h>
using namespace std;
double F(double);							//声明本题所用函数F（x）
int main()
{
	int x;
	double a=1;
	cout << "1.梯形法" << endl;
	cout << "2.矩形法" << endl;
	cout << "3.退出" << endl;
	cout << "请输入您想执行选项前的序号:";
	cin >> x;								//确定执行选项
	double h,sum = 0;
	if (x == 1)                            //n=1则执行梯形法
	{
		cout << "请确定微分度n:";
		double n; cin >> n;
		h = 2 / n;
		for (int i = 1; i <= n - 1; i++)
		{
			a += h;
			sum +=F(a);
		}
		cout << (2 / n)*((F(1) + F(3)) / 2 + sum);
	}
	else if (x == 2)						//n=2则执行矩形法
	{
		cout << "请确定微分度n:";
		double n; cin >> n;
		h = 2 / n;
		for (int i = 1; i <= n - 1; i++)
		{
			a += h;
			sum += F(a);
		}
		cout << (2 / n)*(sum);
	}
	else if (x == 3)						//输入为3结束main函数
	{
		return 0;
	}
	else
	{
		cout << "Type Error" << endl;
	}
	system("pause");
	return 0;
}
double F(double x)							//定义函数F（x）
{
	return exp(3 * x) + pow(x, 7);
}