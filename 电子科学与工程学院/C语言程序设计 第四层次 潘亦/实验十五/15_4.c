#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	FILE  *fp1, *fp2;
	fp1 = fopen(argv[1], "r");
	if (fp1 == NULL) 
	{
		puts("Can't read file .");
		exit(1);
	}
	fp2 = fopen(argv[2], "w");
	if (fp2 == NULL) 
	{
		puts("Can't write file .");
		exit(1);
	}
	while (!feof(fp1))    fputc(fgetc(fp1), fp2);
	system("pause");
	return 0;
}
