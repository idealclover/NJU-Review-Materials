#include<cstdio>
#include<cstdlib>
#include<cstring>
void Compress(char a[], char*b)
{
	char flag;
	int x = 0, B = 0;
	while (x != strlen(a))
	{
		flag = a[x];
		int count = 1;
		while (a[++x] == flag)/*临时保存字母*/
			count++;
		if (count == 1)
			b[B++] = flag;/*对字母进行计数*/
		else
		{
			b[B++] = count + 48;
			b[B++] = flag;
		}
	}
	b[B] = '\0';
}
int main()
{
	char p[50];
	int i = 0;
	FILE *fp1;
	if ((fp1 = fopen("C:\\Users\\刘晗桐\\Desktop\\p.txt", "r")) == NULL)
	{
		puts("Cannot open p.txt");
		exit(1);
	}
	while (!feof(fp1))p[i++] = fgetc(fp1);
	p[i - 1] = '\0';
	FILE *fp2;
	if ((fp2 = fopen("C:\\Users\\刘晗桐\\Desktop\\file2.txt", "w")) == NULL)
	{
		puts("Cannot open file2.txt");
		exit(1);
	}
	char b[20];
	Compress(p, b);
	printf("%s", b);
	fprintf(fp2, "%s", b);
	fclose(fp1);
	fclose(fp2);
	system("pause");
	return 0;
}