#include<iostream>
using namespace std;
//定义一个函数用于把大写字母转换为小写字母
char Letter_Change(char a)
{
	a = a + 32;
	return a;
}
//定义一个函数用于寻找数组中某字符出现的次数
void Letter_Count(char a[],char m,int Len)
{
	int count = 0;
	for (int n = 0; n <= Len-1; n++)
	{
		if (a[n] >= 'A'&&a[n] <= 'Z') 
			a[n] = Letter_Change(a[n]);
		if (a[n] == m) 
			count++;
	}
	if(count!=0) cout << m << ":" << count<<" ";
}
int main()
{
	char a[30] ;
	gets_s(a);
	//从字母a到z寻找数组a
	for (char x = 97; x <= 122; x++)
		Letter_Count(a, x,30);
	system("pause");
	return 0;
}