#include<iostream>
#include<cmath>
#define Error 1e-6
using namespace std;
//编写函数
double f(double x)
{
	return (x*x) / 4 - sin(x);
}
//定义求根函数
double root(double a, double b)
{
	if (f((a+b)/2)*f(a)<=0&&fabs(a-b)<=Error) return (a+b)/2;
	else if (f((a + b) / 2)*f(b) <= 0 && fabs(a - b) <= Error) return (a + b) / 2;
	else if (f((a + b) / 2)*f(a) >= 0) return root((a + b) / 2, b);
	else if (f((a + b) / 2)*f(b) >= 0) return root(a,(a + b) / 2);
}
int main()
{
	if (f(1)*f(2) <= 0) cout << root(1, 2)<<endl;
	else cout << "没有实根"<<endl;
	system("pause");
	return 0;
}