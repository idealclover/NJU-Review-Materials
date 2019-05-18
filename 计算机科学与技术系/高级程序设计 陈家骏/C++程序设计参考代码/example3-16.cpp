#include <iostream>
using namespace std;
int main()
{	int n;
	cin >> n;
	int i=2;
	while (i < n && n%i != 0) //循环条件包含了计数控制和事件控制
		i++; 
	if (i == n) //所有小于n的数都不能整除n
		cout << n << "是素数。" << endl;
	else
		cout << n << "不是素数。" << endl;
	return 0;
}
