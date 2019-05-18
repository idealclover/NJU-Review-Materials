#include <iostream>
#include <cmath>
using namespace std;
int main()
{	const double eps=1e-6; //一个很小的数
	double a,x1,x2; //x1和x2分别用于存储xn和xn+1
	cout << "请输入一个数：";
	cin >> a;
	x2 = a; //第一个值取a
	do
	{	x1 = x2; //记住前一个值
		x2 = (2*x1+a/(x1*x1))/3; //计算新的值
	} while (fabs(x2-x1) >= eps);
	cout << a << "的立方根是：" << x2 << endl;
	return 0;
}
