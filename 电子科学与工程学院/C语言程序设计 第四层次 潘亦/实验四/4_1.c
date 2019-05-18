#include<stdio.h>
#include<cmath>
int main()
{
	int a, b, c;
	double p, q, derta;
	printf("Please enter three coefficents:");
	scanf_s("%d%d%d", &a, &b, &c);
	derta = b*b - 4 * a*c;
	p = -b / (2 * a);
	q = sqrt(abs(derta)) / (2 * a);
	if (derta < 0)
		printf("The equation has no real root");
	else if (derta == 0)
		printf("Solution of the equation:x1=x2=%.2f\n", p);
	else
		printf("Solution of the equation:x1=%.2f,x2=%.2f\n", p + q, p - q); 
	getchar(); getchar();
	return 0;
}