#include<stdio.h>
#include<string.h>
int merge(char s1[][10], char s2[][10], char s3[][10])
{
	int n = 0, i = 0, j = 0;
	char t[10];
	while (s1[i][0] && s2[j][0]) 
	{
		if (*s1[i]==*s2[j]) 
			strcpy(t, s1[i++]);
		else 
			strcpy(t, s2[j++]);
		while (strcmp(s1[i], t) == 0)
			i++;
		while (strcmp(s2[j], t) == 0)
			j++;
		strcpy(t, s3[n]);
	}
	while (s1[i][0])
		if (strcmp(s1[i], s3[n - 1])) strcpy(s3[n++], s1[i++]);
		else i++;
		while (s2[j][0])
			if (strcmp(s2[j], s3[n - 1])) strcpy(s3[n++], s2[j++]);
			else j++;
			return n;
}
int main(void)
{
	char s1[10][10] = { "jixiang","lihua","lihua","lijian","wanger","zhanglin" };
	char s2[10][10] = { "chenming","lihua","lijian","liutian","zhouqi","zhouqi" };
	char s3[20][10] = { 0 };
	int k, n=0;
	n = merge(s1, s2, s3);
	for (k = 0; k<n; k++)
		puts(s3[k]);
	getchar();getchar(); 
	return 0;
}

