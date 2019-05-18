#include<cstdlib>
#include<cstdio>
void fun(char op, double a, double b, double c, double d)
{
	switch (op)
	{
	case '+':printf("(%lf+%lfi)+(%lf+%lfi)=%lf+%lfi\n", a, b, c, d, a + b, c + d); break;
	case'-':printf("(%lf+%lfi)-(%lf+%lfi)=%lf+%lfi\n", a, b, c, d, a - b, c - d); break;
	case'*':printf("(%lf+%lfi)*(%lf+%lfi)=%lf+%lfi\n", a, b, c, d, a*c - b*d, b*c + a*d); break;
	}
}
int main()
{
	char op;
	double a, b, c, d;
	scanf("(%lf+%lfi)%c(%lf+%lfi)", &a, &b, &op, &c, &d);
	fun(op, a, b, c, d);
	system("pause");
	return 0;
}