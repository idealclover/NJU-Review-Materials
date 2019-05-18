#include<iostream>
#include<cmath>
using namespace std; 
int s = 0;
int countvalue(int aa[])
{
	int count = 0;
	//从301开始依次递加检查素数(偶数忽略)
	for (int i = 501; i <= 800; i+=2)
	{
		int m = 2;
		for (; m <= i; m++)
		{
			if (i%m == 0) break;
		}
		if (m==i)
		{
			//如果是素数，则赋值给数组aa
			aa[s++] = i;
			count++;
		}
	}
	return count;
}
int main()
{
	int Pri[200];
	//获得素数个数
	int count = countvalue(Pri);
	//依次打印出所有素数
	for (int i = 0; i <= s-1; i++)
	{
		cout << Pri[i]<<"  ";
		if (i % 10 == 9) cout << endl;
	}
	cout << "共" << count << "个素数" << endl;
	system("pause");
	return 0;
}