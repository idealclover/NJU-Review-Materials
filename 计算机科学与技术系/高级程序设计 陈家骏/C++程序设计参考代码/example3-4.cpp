#include <iostream>
#include <cmath>
using namespace std;
int main()
{ 	double a,b,c,root1,root2;
	cout << "请输入一元二次方程的系数(a,b,c)：" << endl;
	cin >> a >> b >> c;
	if (a == 0) //判断系数a是否为0
	{ 	cout << "不是一个一元二次方程" << endl;
		return -1;
	}
	double t=b*b-4*a*c;
	if (t < 0) //判断方程是否有实根
	{	cout << "方程没有实根" << endl;
		return -1;
	}
	if (t == 0) //判断方程是否有等根
		root1 = root2 = -b/(2*a);
	else
	{ 	root1 = (-b+sqrt(t))/(2*a);
		root2 = (-b-sqrt(t))/(2*a);
	}
	cout << "方程的根为：" << root1 << "和" << root2 << endl;
	return 0;
}
