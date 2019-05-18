#include<cstdio>
#include<cstdlib>
#include<cstring>
//PS存储联系人信息
char *m[1];
typedef struct
{
	long id;
	char name[10];
	char sex[2];
}PS;
//删除重复联系人信息
int Delete(PS *p1, int m, PS *p2, int n)
{
	int Count_Member = m;
	for (int i = 0; i < m; i++)
		for (int l = 0; l < n; l++)
			if (p1[i].id == p2[l].id)
			{
				Count_Member--;
				for (int h = i + 1; h < m; h++)
					p1[h - 1] = p1[h];
			}
	return Count_Member;
}
//合并两个联系人结构数组
int merge(PS *p1, int m, PS *p2, int n)
{
	PS a[50];
	int M = 0, N = 0, A = 0;
	while (M != m&&N != n)
	{
		if (p1[M].id > p2[N].id)
			a[A++] = p2[N++];
		else
			a[A++] = p1[M++];
		if (M == m)
		{
			for (int h = N; h < n; h++)
			{
				a[A++] = p2[h];
			}
			break;
		}
		if (N == n)
		{
			for (int h = M; h < m; h++)
				a[A++] = p1[h];
			break;
		}
	}
	for (int x = 0; x < m + n; x++)
		p1[x] = a[x];
	return m + n;
}
void sort(PS *p, int n)
{
	for(int i=0;i<n-1;i++)
		for (int l = 0; l < n - i - 1; l++)
		{
			if (p[l].sex == p[l + 1].sex)
			{
				if (strcmp(p[l].name, p[l + 1].name) > 0)
				{
					p[20] = p[l];
					p[l] = p[l + 1];
					p[l + 1] = p[20];
				}
			}
			if (strcmp(p[l].sex, p[l + 1].sex) > 0)
			{
				p[20] = p[l];
				p[l] = p[l + 1];
				p[l + 1] = p[20];
			}
		}
}
void display(PS *p, int n)
{
	printf("ID\tNAME\tSEX\n\n");
	for (int i = 0; i < n; i++)
		printf("%d\t%s\t%s\n", p[i].id, p[i].name, p[i].sex);
	printf("\n\n");
}
int main()
{
	PS a[5] ={ { 101, "tom","m" }, { 103,"mary","f" }, { 104,"mark","m" },
	{ 105,"julia","f" }, { 106, "sara","f" }};
	PS b[10] = { { 102, "mark","m" },{ 104,"mark","m" } };
	printf("a:\n");
	display(a, 5);
	printf("b:\n");
	display(b, 2);
	int m=Delete(a, 5, b, 2);
	printf("a:\n");
	display(a,m);
	int n=merge(b, 2, a, m);
	printf("b:\n");
	display(b,n);
	sort(a, 4);
	printf("a:\n");
	display(a, 4);
	system("pause");
	return 0;
}

