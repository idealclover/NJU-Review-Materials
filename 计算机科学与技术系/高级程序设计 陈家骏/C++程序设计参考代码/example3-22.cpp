#include <iostream>
#include <cmath>
using namespace std;
int main()
{	int n;
	double square_root;
	cout << "请输入若干整数（以0结束）：";
	for (cin>>n; n!=0; cin>>n)
	{	if (n < 0) continue;
		square_root = sqrt(n);
		cout << n << "的平方根是：" << square_root << endl;
	}
	return 0;
}
