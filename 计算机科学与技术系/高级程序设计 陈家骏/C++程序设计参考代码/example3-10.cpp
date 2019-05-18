#include <iostream>
using namespace std;
int main()
{	int n;
	cin >> n;
	int i=2,f=1; //循环初始化
	while (i <= n) //循环条件：对i=2、3、...、n进行循环
	{	f *= i; //把i的值乘到f中
		i++; //下一次循环准备
	}
	cout << "factorial of " << n << " = " << f << endl;
	return 0;
}
