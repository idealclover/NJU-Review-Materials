#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
double F1(double x)
{
	return sin(x);
}
double F2(double x)
{
	return cos(x);
}
double F3(double x)
{
	return 2 * x + 1;
}
double integral(double a, double b, long n, double(*p)(double))
{
	double sum = 0;
	double h = fabs(b - a) / n;
	for (int i = 1; i <= n - 1; i++)
	{
		a += h;
		sum += p(a);
	}
	double x1 = (p(a) + p(b)) / 2;
	double x2 = sum;
	return h*(x2 + x1);
}
int main()
{
	double a, b;
	long n;
	cout << "请输入等分区间以及积分数:";
	cin >> a >> b >> n;
	cout << "integral sin:" << integral(a, b, n, F1) << endl;
	cout << "integral cos:" << integral(a, b, n, F2) << endl;
	cout << "integral 2*x+1:" << integral(a, b, n, F3) << endl;
	system("pause");
	return 0;
}