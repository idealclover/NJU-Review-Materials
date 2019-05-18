#include<stdio.h>
#include<cstdlib>
#include<string.h>
void fun(char xx[])
{
	int Len = strlen(xx);
	int count = 0;
	for (int i = 0; i <= Len - 1; i++)
		if (xx[i] >= 48 && xx[i] <= 57) count++;
	for (int i = Len; i <= 29; i++) xx[i] = '\0';
	for (int i = Len - 1; i >= 0; i--)
	{
		xx[i + count] = xx[i];
		if (xx[i] >= 48 && xx[i] <= 57)
			xx[i + (count--) - 1] = '$';
	}
}
int main()
{
	char a[30];
	gets_s(a);
	fun(a);
	puts(a);
	system("pause");
	return 0;
}