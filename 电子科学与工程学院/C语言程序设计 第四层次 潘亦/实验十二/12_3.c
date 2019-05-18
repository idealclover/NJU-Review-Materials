#include<cstdio>
#include<cstdlib>
#include<string.h>
int main()
{
	char a[][10] = { "while", "for", "switch", "if", "break", "continue" };
	char b[][10] = { "for", "case", "do", "else", "char", "switch" };
	for (int i = 0; i < 6; i++)
		for (int m = 0; m < 6; m++)
			if (strcmp(a[i], b[m]) == 0) printf("%s ",a[i]);
	system("pause");
	return 0;
}
