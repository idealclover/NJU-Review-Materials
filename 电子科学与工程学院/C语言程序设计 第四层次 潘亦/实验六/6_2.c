#include<iostream>
#include<cmath>
using namespace std;
double Pi_Next(double pi);
int main()
{
	double sum = 2 * (2 / sqrt(2));
	double pi = 2 / sqrt(2);
	for (int i = 1; pi >(1+1e-6)||pi<(1-1e-6); i++)
	{
		pi = Pi_Next(pi);
		sum *= pi;
	}
	cout << sum;
	system("pause");
	return 0;
}
double Pi_Next(double pi)
{
	return 2*(1 / sqrt(2 + 1 / (pi / 2)));
}