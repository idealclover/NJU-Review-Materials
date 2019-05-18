#include<iostream>
#include<iomanip>
using namespace std;
double Sina_Next(double,double,int);
int main()
{
	double x,sum=0;
	cout << "x=";
	cin>> x;
	double a = x;
	sum += a;
	for (int n = 1; fabs(a) >= 1e-8; n++)
	{
		a = Sina_Next(a, x, n);
		sum += a;
	}
	cout <<"sinx="<< fixed<<setprecision(1)<<sum;
	system("pause");
	return 0;
}
double Sina_Next(double a,double x,int n)                           //定义函数求每一项的值
{
	return (-1)*(a*x*x) / ((2 * n)*(2 * n + 1));

}