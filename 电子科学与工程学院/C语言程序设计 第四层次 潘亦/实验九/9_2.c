#include<cstdlib>
#include<cstdio>
//定义函数获取十六进制数对应的表示
void Ljz(int x)
{
	switch (x)
	{
	case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9: printf("%d", x); break;
	case 10:printf("A");
	case 11:printf("B");
	case 12:printf("C");
	case 13:printf("D");
	case 14:printf("E");
	case 15:printf("F");
	}
}
void itoah(long int x)
{
	if (x != 0)
	{
		itoah(x / 16);
		Ljz(x % 16);
	}
}
int main()
{
	long int x;
	scanf_s("%ld", &x);
	itoah(x);
	system("pause");
	return 0;
}