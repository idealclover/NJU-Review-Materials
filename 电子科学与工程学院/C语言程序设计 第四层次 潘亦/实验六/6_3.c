#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double x1 = 0.5, x2, m=1;
	for (int i = 1; m >= 1e-6; i++)
	{
		x2 = x1 - (cos(x1) - x1) / (-sin(x1) - 1);
		m = fabs(x1 - x2);
		x1 = x2;
	}
	cout << "cosx-x=0的近似解为" << x1 << endl;
	system("pause");
	return 0;
}