#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double a, b,mid;
	a = -1, b = 0;
	while(exp(a) + a != 0 && exp(b) + b != 0)
	{
		mid = (a + b) / 2;
		while (exp(mid) + mid == 0)
		{
			cout << mid << endl;
			break;
		}
		if (exp(mid) + mid > 0) b = mid;
		else a = mid;
	}
	if (exp(a) + a == 0) cout << a;
	else cout << b;
	system("pause");
	return 0;
}