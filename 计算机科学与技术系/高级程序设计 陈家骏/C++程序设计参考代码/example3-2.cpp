#include <iostream>
using namespace std;
int main()
{	int n; //n用于存储项数
	double a,sum; //a和sum分别用于存储首项和级数的和
	cout << "a=";
	cin >> a; //输入首项
	cout << "n=";
	cin >> n; //输入项数
	sum = a*(1+n)*n/2; //计算级数和
	cout << "sum=" << sum << endl; //输出计算结果
	return 0; //程序结束
}
