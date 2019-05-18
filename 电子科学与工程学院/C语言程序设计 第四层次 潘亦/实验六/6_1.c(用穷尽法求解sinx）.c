#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double x, a = 1;
	cout << "请输入x=";
	cin >> x;
	double s = x / 1;
	long long m;
	int count = 1, n;
	for (int i = 3; fabs(a) >= pow(10, -8); i+=2)			//从3开始迭代计算阶乘
	{
		for(m = 1, n = 1; n <= i; n++)						//计算i的阶乘
			m *= n;
		++count;											//对累加式进行计数以确定正负
		a = pow(x, i) / m; 
		if (count % 2 == 0) s -= a;
		else s += a;
	}
	cout <<"sinx="<<fixed<<setprecision(1)<<s;
	system("pause");
	return 0;
}