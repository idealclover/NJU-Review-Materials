#include<iostream>
using namespace std;
//定义一个函数确定数字在十二进制中的表示
void ShiEr(int m)
{
	switch (m)
	{
	case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:cout << m; break;
	case 10:cout << "A"; break;
	case 11:cout << "B"; break;
	case 12:cout << "C"; break;
	}
}
int main()
{
	int n, Yushu[20], i = 0;
	//输入一个十进制整数
	cin >> n;
	//依次求余数
	do {
		Yushu[i] = n %12;
		i++;
		n = n / 12;
	} while (n / 12 != 0);
	//输出十二进制数的第一位
	ShiEr(n);
	for (int m = i - 1; m >= 0; m--)
	{
		//依次倒序输出数组中的元素
		ShiEr(Yushu[m]);
	}
	system("pause");
	return 0;
}