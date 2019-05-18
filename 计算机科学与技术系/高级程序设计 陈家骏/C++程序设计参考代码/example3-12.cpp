#include <iostream>
using namespace std;
int main()
{	int n,i,f;
	cin >> n;
	for (i=2,f=1 //循环初始化
			; 
			i<=n  //循环条件
			;
			i++)     //下一次循环准备
		f *= i;     //循环体：把i的值乘到f中
       
	cout << "factorial of " << n << " = " << f << endl;
	return 0;
}
