#include<iostream>
using namespace std;
//．输入一个整数，用折半查找法查找该数是否在数组{5,23,28,34,43,45,56,60,67,90}内，如果在，则输出下标，否则输出“not found”。
int main()
{
	int n[10] = { 5,23,28,34,43,45,56,60,67,90 };
	cout << "请输入一个整数:";
	int x;
	cin >> x;
	int a = 0, b = 9;
	while (n[a] != x&&n[b] != x)
	{
		int m = (a + b) / 2;
		if (n[m] == x) { a = m; break; }
		else if (n[m] > x) b = m;
		else a = m;
		if (abs(a - b) == 1) break;
	}
	if (n[a] == x) cout << a;
	else if (n[b] == x) cout << b;
	else cout << "not found";
	system("pause");
	return 0;
}