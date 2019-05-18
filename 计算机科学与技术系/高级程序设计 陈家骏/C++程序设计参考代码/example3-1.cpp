#include <cmath>
#include <iostream>
using namespace std;
int main()
{ double x,square,cube,square_root; //定义三个变量分别用于存储输入的数、它的平方、
													 //立方以及平方根
	cout << "Please input a positive number: "; //输出提示信息
	cin >> x; //输入一个数
	square = x * x; //计算x的平方
	cube = x * x * x; //计算x的立方
	square_root = sqrt(x);  //计算x的平方根，sqrt为C++标准库中的计算平方根的函数
	cout << "The square of " << x << " is " << square << endl; //输出x的平方
	cout << "The cube of " << x << " is " << cube << endl; //输出x的立方
	cout << "The square root of " << x << " is " 
			<< square_root << endl; //输出x的平方根
	return 0; //程序结束
}
