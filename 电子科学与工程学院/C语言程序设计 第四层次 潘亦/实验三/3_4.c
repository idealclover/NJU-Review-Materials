#include<stdio.h>
#include<cstdlib>
int main()
{
	int a;
	int w1, w2, w3, w4;
	printf("请输入一个四位正整数:");
	scanf_s("%d", &a);
	w1 = a / 1000;
	w2 = a / 100 % 10;
	//w3 = a / 10 % 10;
	w4 = a % 10;
	printf("%d,%d,%d,%d", w1, w2, w3, w4);
	system("pause");
	return 0;
}