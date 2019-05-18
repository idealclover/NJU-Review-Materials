#include<stdio.h>
#include<cstdlib>
void encode(int  a, int b[]);
int main(void)
{
	int x = -2, y[8], n;
	encode(x, y);
	putchar('\n');
	for (n = 7; n >= 0; n--)
		printf("%d,", y[n]);
	system("pause");
	return 0;
}
void encode(int  a, int b[])
{
	int k, sign, carry;
	for (k = 0; k<8; k++)
		b[k] = 0;
	if (a >= 0)
		sign = 0;
	else {
		sign = 1;
		a = -a;
	}
	k = 0;
	do
	{
		b[k++] = a % 2;
		a = a / 2;
	} while (a>0);
	if (sign) {
		carry = 1;
		for (k = 0; k<7; k++)
		{
			b[k] = 1- b[k] + carry;
			if (b[k]>1)
			{
				b[k] -= 2;
				carry = 1;
			}
			else
				carry = 0;
		}
	}
	b[7] = sign;
}
