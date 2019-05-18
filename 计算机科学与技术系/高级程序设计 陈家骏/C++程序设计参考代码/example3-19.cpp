#include <iostream>
using namespace std;
int main()
{	int n,count=0;
	cout << "请输入一个正整数："
	cin >> n;  //从键盘输入一个正整数
	for (int i=2; i<n; i++)  //循环：分别判断2、3、...、n-1是否为素数
	{	int j=2;
		while (j < i && i%j != 0) //循环：分别判断i是否能被2、3、...、i-1整除
			j++;
		if (j == i) //i是素数
		{	cout << i << ",";
			count++;
			if (count%6 == 0) cout << endl; //控制每一行输出6个素数。
		}
	}
	cout << endl;
	return 0;
}

/*
//改进的程序
#include <iostream>
#include <cmath>
using namespace std;
int main()
{	int n,count=1;
	cin >> n;   //从键盘输入一个数
	if (n < 2) return -1;
	cout << 2 << ",";  //输出第一个素数
	for (int i=3; i<n; i+=2)  //循环：分别判断3、5、...、是否为素数
	{	int j=2;
		while (j<=sqrt(i) && i%j!=0) //循环：分别判断i是否能被2、3、...、 整除
			j++;
		if (j > sqrt(i)) //i是素数
		{	cout << i << ",";
			count++;
			if (count%6 == 0) cout << endl; //控制每一行输出6个素数。
		}
	}
	cout << endl;
	return 0;
}

*/
