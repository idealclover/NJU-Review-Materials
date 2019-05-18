#include <iostream>
using namespace std;
int main()
{	int a,b,c;
	cin >> a >> b >> c;
	if (a+b <= c || b+c <= a || c+a <= b)
		cout << "不是三角形";
	else if (a == b && b == c)
		cout << "等边三角形";
	else if (a == b || b == c || c == a)
		cout << "等腰三角形";
	else if (a*a+b*b == c*c || b*b+c*c == a*a || c*c+a*a == b*b)
		cout << "直角三角形（非等腰）";
	else
		cout << "其它三角形";	
	cout << endl;
	return 0;
}
