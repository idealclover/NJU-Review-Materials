#include<cstdio>
#include<cstdlib>
int Gcd(int a, int b);
int main()
{
	for (int a = 3; a <= 49; a++)
	{
		int b = 99 - a;
		if (Gcd(a, b) % 3 == 0) printf("(%d,%d)", a, b);
	}
	system("pause");
	return 0;
}
int Gcd(int a, int b)
{
	for (int z = a; z >= 2; z--)
	{
		if (a%z == 0 && b%z == 0)
		{
			return z;
		}
		else continue;
	}
}