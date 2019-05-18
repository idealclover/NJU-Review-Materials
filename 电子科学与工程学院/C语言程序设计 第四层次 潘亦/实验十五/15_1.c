#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
/*ÅĞ¶ÏËØÊı*/
int prime_judge(int n)
{
	int i;
	if (n % 2 == 0) return 0;
	for (i = 3; i <= n; i += 2)
		if (n%i == 0) break;
	if (i == n) return 1;
	return 0;
}
/*ÅĞ¶ÏÎ»Êı*/
int Num_Judge(int i)
{
	int sum = 0;
	while (i != 0)
	{
		i = i / 10;
		sum++;
	}
	return sum;
}
int rev_prime(int m, int n, int x[])
{
	int i = 0;
	for (; m <= n; m++)
	{
		int M = m;
		int New = 0;
		int Num = Num_Judge(m);
		while (M != 0)
		{
			New += (M % 10)*(int)pow(10, --Num);
			M = M / 10;
		}
		if (prime_judge(New) == 1) x[i++] = New;
	}
	return i;
}
int main()
{
	int x[20];
	int m,n;
	scanf("%d%d",&m,&n);
	int i=rev_prime(m, n, x);
	FILE *fp;
	if ((fp = fopen("C:\\Users\\ÁõêÏÍ©\\Desktop\\p.txt", "w")) == NULL)
	{
		puts("Cannot open file p.txt");
		exit(0);
	}
	for(int l=0;l<i;l++)
	       fprintf(fp, "%d  ", x[l]);
	fclose(fp);
	system("pause");
	return 0;
}
