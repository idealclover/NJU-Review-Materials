#include <iostream>
using namespace std;
int main()
{	int a,b,c,max;
	cout << "请输入三个整数：" << endl;
	cin >> a >> b >> c;
	if (a > b) //比较a和b的大小，大者赋值给max
		max = a;
	else
		max = b;
	if (c > max) //比较c和max的大小，如果c大，则把max调整为c的值
		max = c; 
	cout << "最大者为：" << max << endl;
	return 0;
}
