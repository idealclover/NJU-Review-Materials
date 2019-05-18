//VS2017下可以运行
#include<cstdio>
#include<cstdlib>
int Prime_Judge(int n)
{
	int i;
	for ( i = 2; i <= n; i++)
	{
		if (n%i == 0)
			break;
	}
	if (i == n) return 1;
	return 0;
}
int main(int argc,char* argv[])
{
	int a[200],i;
	//将命令行得到的整数转化后保存于a中
	for ( i = 1; i <argc; i++)
		a[i] = atoi(argv[i]);
	printf("%d\n", i-1);
	for (int m = 1; m < i ; m++)
		if (Prime_Judge(a[m])) printf("%d .", a[m]);
	printf("\n");
	for (int m = 1; m < i; m++)
		if (Prime_Judge(a[m])==0) printf("%d .", a[m]);
	printf("\n");
	system("pause");
	return 0;
}