#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
//strcmp
//strcpy
//使用选择排序法进行排序
void SelSort(char sdata[][20], int count)
{
	char a[200];
	for (int i = count-1; i >= 1; --i)
	{
		int max =i;
		for (int j = 0; j < i; ++j)
			if (strcmp(sdata[max] ,sdata[j])<0)
				max = j;
		if (max != i )
		{
			strcpy_s(a, strlen(sdata[max]) + 1, sdata[max]);
			strcpy_s(sdata[max], strlen(sdata[i]) + 1, sdata[i ]);
			strcpy_s(sdata[i ] , strlen(a) + 1, a);
		}
	}
}
int FindNoVowel(char *str[], int num, char res[][20])
{
	//先将这些字符串放入数组中
	int count = 0, Count = 0, h = 0;
	for (int i = 0; i < num; i++)
		for (int m = 0; m < strlen(str[i]); m++)
			if (str[i][m] != 97 && str[i][m] != 101 && str[i][m] != 105 && str[i][m] != 111 && str[i][m] != 117)
			{
				count++;
				if (count != m + 1)
				{
					count = 0; break;
				}
				if (count == strlen(str[i]) - 1)
				{
					strcpy_s(res[h++], strlen(str[i]) + 1, str[i]);
					Count++;
					count = 0;
					break;
				}
			}
	//再对这些字符串进行排序
	SelSort(res, Count);
	return Count;
}
int main()
{
	char *str[10] = { "ftp", "qq", "msn", "internet", "web", "google", "bbs", "mp3", "blog", "ibm" };
	char res[10][20];
	int num = 10;
	int count = FindNoVowel(str, num, res);
	for (int i = 0; i < count; i++)
		printf("%s ", res[i]);
	printf("%d", count);
	system("pause");
	return 0;
}