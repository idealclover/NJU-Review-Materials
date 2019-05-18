#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<cstdlib>
typedef struct
{
	char  name[10], degree[10];
}ST;
void sort(ST x[], int n, char *key[10], int m)
{
	int i, j, k, con1, con2;
	ST v;
	for (i = 0; i<n - 1; i++)
		for (j = 0; j<n - i - 1; j++)
		{
			for (k = 0; k<m; k++)
				if (strcmp(x[j].degree, key[k]) == 0)
				{
					con1 = k;
					break;
				}
			for (k = 0; k<m; k++)
				if (strcmp(x[j + 1].degree, key[k]) == 0) 
				{
					con2 = k;
					break;
				}
			if (con1>con2 || con1 == con2&&strcmp(x[j].name, x[j + 1].name)>0)
			{
				v = x[j];
				x[j] = x[j + 1];
				x[j + 1] = v;
			}
		}
}
int main(void)
{
	ST s[5] = { { "Andy","master" },{ "Beth","bachelor" },{ "Can","doctor" },
	{ "Deo","bachelor" },{ "Emy","master" } };
	char *sortkey[3] = { "bachelor","master","doctor" };
	int i;
	sort(s, 5, sortkey, 3);
	for (i = 0; i<5; i++)
		printf("\n%s    %s", s[i].name, s[i].degree);
	system("pause");
	return 0;
}