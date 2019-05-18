#include<cstdlib>
#include<cstdio>
#include<cmath>
int main()
{
	double n; int m;
	scanf_s("%lf", &n);
	if (n == 0) return -1;
	if (n > 0) printf("sign:+\n");
	else printf("sign:-\n");
	m = abs(n);
	printf("integral part:%d\n", m);
	n = abs(n) - m;
	printf("decimal fraction part:%f\n", n);
	system("pause");
	return 0;
}