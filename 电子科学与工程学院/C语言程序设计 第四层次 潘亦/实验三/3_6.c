#include<stdio.h>
#include<cstdlib>
#include<cmath>
int main()
{
	int a, b, c;
	double s, S;
	scanf_s("%d%d%d", &a, &b, &c);
	s = (a + b + c) / 2;
	S = sqrt(s*(s - a)*(s - b)*(s - c));
	printf("%.2f", S);
	system("pause");
	return 0;
}