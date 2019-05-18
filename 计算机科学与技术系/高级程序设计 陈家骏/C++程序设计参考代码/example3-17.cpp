#include <iostream>
using namespace std;
int main()
{	int n;
	cin >> n;
	int fib_1=1; //第一个Fibonacci数
	int fib_2=1; //第二个Fibonacci数
	for (int i=3; i<=n; i++) //循环计算第3、4、...、n个Fibonacci数
	{	int temp=fib_1+fib_2; //计算新的Fibonacci数
		fib_1 = fib_2;  //记住前一个Fibonacci数
		fib_2 = temp;  //记住新的Fibonacci数
	}
	cout << "第" << n << "个费波那契数是：" << fib_2 << endl;
	return 0;
}
