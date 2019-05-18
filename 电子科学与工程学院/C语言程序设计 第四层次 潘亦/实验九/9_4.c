#include<iostream>
using namespace std;
int x = 5, Num, m = 4;//x用来计数（五次）；Num为桃子数；m为最后剩下的桃子数
int CountPeach(int);
int main()
{
	cout << CountPeach(4) << endl;
	system("pause");
	return 0;
}
int CountPeach(int Num)//定义函数求解桃子个数
{
	if (Num % 4 == 0 && x > 0)//如果可以被四整除则继续
	{
		x--;
		return CountPeach((Num / 4) * 5 + 1);
	}
	else if (Num % 4 != 0 && x > 0)//如果中途桃子数不可被四整除则重新开始
	{
		x = 5;
		m++;
		return CountPeach(m);
	}
	else return Num;  //如果连续五次满足条件则返回桃子数
}