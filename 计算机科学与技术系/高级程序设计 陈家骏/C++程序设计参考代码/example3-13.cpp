#include <iostream>
using namespace std;
int main()
{	int n;
	cout << "请输入整数的个数：";
	cin >> n;
	cout << "请输入" << n << "个整数：";
	int sum=0；
	for (int i=1; i<=n; i++)
	{	int a; 
		cin >> a;
		sum += a; 
	}
	cout << "输入的" << n << "个整数的和是：" << sum << endl;
	return 0;
}
