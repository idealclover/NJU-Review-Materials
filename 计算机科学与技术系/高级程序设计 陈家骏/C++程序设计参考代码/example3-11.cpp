#include <iostream>
using namespace std;
int main()
{	int n;
	cin >> n;
	int i=1,f=1; //循环初始化
	do
	{	f *= i; //把i的值乘到f中
		i++; //下一次循环的准备
	} while (i <= n); //循环条件
	cout << "factorial of " << n << " = " << f << endl;
	return 0;
}
