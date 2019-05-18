#include <iostream>
using namespace std;
int main()
{	int h1,m1,s1, //第一个时刻的时、分、秒
			h2,m2,s2, //第二个时刻的时、分、秒
			r; //比较的结果
	cout << "请输入第一个时刻（时、分、秒）：";
	cin >> h1 >> m1 >> s1;
	cout << "请输入第二个时刻（时、分、秒）：";
	cin >> h2 >> m2 >> s2;
	if (h2 > h1) //先比较两个时刻的时
		r = 1;
	else if (h2 < h1)
		r = -1;
	else if (m2 > m1)  //从此，h1 == h2
		r = 1;
	else if (m2 < m1)
		r = -1;
	else if (s2 > s1)  //从此，h1 == h2 并且 m2 == m1
		r = 1;
	else if (s2 < s1)
		r = -1;
	else  // h1 == h2 并且 m1 == m2 并且 s1 == s2
		r = 0;
	if (r == 1)
		cout << "第一个时刻在前。";
	else if (r == -1)
		cout << "第二个时刻在前。";
	else
		cout << "两个时刻相同";
	cout << endl;
	return 0;
}
