#include<iostream>
#include<math.h>
using namespace std;
double Fun(double );								//声明函数Fun（x）
int main()
{                                                        
	double a, b, mid;
	a = 0, b = 3;
	while (fabs(Fun(a)) >1e-6 && fabs(Fun(b)) >1e-6)				//当端点值不为所求值时执行循环
	{
		mid = (a*Fun(b)-b*Fun(a))/(Fun(b)-Fun(a));
		while (Fun(mid) == 0)						//当截点为所求值时结束循环
		{
			cout << mid << endl;
			break;				
		}
		if (Fun(mid) > 0) b = mid;					//当截点不为所求值时赋为端点值
		else a = mid;
	}
	if (fabs(Fun(a))<=1e-6) cout << a;
	else cout << b;
	system("pause");
	return 0;
}
double Fun(double x)								//定义函数求F（x）
{
	return 2 * x*x*x - 4 * x*x + 3 * x - 6;
}