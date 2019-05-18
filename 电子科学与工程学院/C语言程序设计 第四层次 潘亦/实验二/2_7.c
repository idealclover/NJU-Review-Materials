#include<stdio.h>
#include<cstdlib>
using namespace std;
int main()
{
	int a,b,c;
	printf("请输入一个长方体的长宽高:");
	scanf_s("%d%d%d", &a, &b, &c);
	printf("这个长方体的体积为:%d", a*b*c);
	system("pause");
	return 0;

}