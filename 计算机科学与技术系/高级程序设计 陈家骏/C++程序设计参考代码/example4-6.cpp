#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(int n); //判断n是否为素数
void print_prime(int n, int count); //打印素数，一行6个素数
int main()
{	int n,count=1; //count用于对找到的素数进行计数
	cout << "请输入一个正整数："
	cin >> n;  //从键盘输入一个正整数
	if (n < 2) return -1;
	cout << 2 << ",";  //输出第一个素数
	for (int i=3; i<n; i+=2)
	{	if (is_prime(i)) //调用函数is_prime来判断i是否为素数
		{	count++; //把找到的素数的个数加1
			print_prime(i,count); //调用函数print_prime打印素数i
		}
	}
	cout << endl;
	return 0;
}
bool is_prime(int n) //判断n是否为素数
{	int i,j;
	for (i=2, j=sqrt(n); i<=j; i++)
		if (n%i == 0) return false;
	return true;
}
void print_prime(int n, int count)//打印素数，一行6个素数
{	cout << n << ',';
	if (count % 6 == 0) cout << endl;
}
