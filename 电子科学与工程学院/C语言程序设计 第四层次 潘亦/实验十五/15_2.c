#include<cstdio>
#include<cstdlib>
#include<cstring>
char *insert(char *p)
{
	int m = 0;
	int flag = 0;
	while (p[m] != '\0')	/*Ñ°Ö·µ½Êý×éÄ©Î²*/
	{
		if (p[m] >= 48 && p[m] <= 57 && flag == 0)
		{
			flag = 1;
			int num = strlen(p);
			for (int i = num; i >=m;i--)
				p[i ] = p[i-1];
			p[m] = '-';
			m += 2;
		}
		while ((p[m] < 48 || p[m] > 57)&&p[m]!='\0')
			flag=0,m++;
		while ((p[m] >= 48 && p[m] <= 57) && flag&&p[m] != '\0')
			m++;
	}
	return p;
}
int main()
{
	char a[100];
	gets_s(a);
	char *A=insert(a);
	puts(A);
	FILE *fp;
	if ((fp = fopen("C:\\Users\\ÁõêÏÍ©\\Desktop\\data.txt", "w")) == NULL)
	{
		puts("Cannot find data.txt");
		exit(1);
	}
	fprintf(fp, "%s\n", A);
	system("pause");
	return 0;
}