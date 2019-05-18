#include<cstdio>
#include<cmath>
double f(double x)                    //定义函数f(x)=cosx+sinx
{
	return cos(x) + sin(x);
}
double integral(double a, double b, long n)//定义函数求定积分
{
	double m = (b - a) / n;
	double sum = 0;
	for (int i = 1; i <= n - 1; i++)
		sum += f(a + i*m);
	return m*((f(a) + f(b)) / 2 + sum);
}
int main()
{
	double a(0), b(0);
	int n(0);
	for (int i = 1; i <= 5; i++)
	{
		printf("请输入一组数据:");
		scanf_s("%lf%lf%d", &a, &b, &n);
		printf("[%lf,%lf]区间内定积分为%lf\n", a, b, integral(a, b, n));
	}
	system("pause");
	return 0;

}