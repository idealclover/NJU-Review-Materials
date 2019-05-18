#include<iostream>
using namespace std;
double power(double x, int y)
{
	if (y == 0) return 1;
	else if (y > 0) return x*power(x, y - 1);
	else return power(x, y + 1) / x;
}
int main()
{
	double x; int y;
	cin >> x >> y;
	cout << power(x, y);
	system("pause");
	return 0;
}