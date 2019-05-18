#include <iostream>
using namespace std;
int main()
{	int a,sum=0;
	cout << "请输入若干个整数（以-1结束）：";
	cin >> a; //输入第一个数
	while (a != -1)
	{	sum += a; 
		cin >> a; //输入下一个数
	}
	cout << "输入的整数的和是：" << sum << endl;
	return 0;
}
