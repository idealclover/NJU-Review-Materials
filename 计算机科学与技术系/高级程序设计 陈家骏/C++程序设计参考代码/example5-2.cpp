#include <iostream>
using namespace std;
int main()
{	const int MAX_N=40;
	int fibs[MAX_N];
	int n,i;
	cout << "请输入n(1-" << MAX_N << "):";
	cin >> n;
	if (n > MAX_N) 
	{	cout << "n太大!" << endl;
		return -1;
	}
	fibs[0] = fibs[1] = 1;
	for (i=2; i<n; i++)  //计算费波那契数
		fibs[i] = fibs[i-1] + fibs[i-2];

	cout << "第" << n << "个费波那契数是：" << fibs[n-1] << endl;
	return 0;
}
