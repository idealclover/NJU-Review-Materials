#include<iostream>
#include<cstdlib>
int *count(char *ch_p)
{
	//定义局部静态变量对元音字母进行计数
	static int count = 0;
	//将字符转化为并输出
	if ('A' <= *ch_p&&*ch_p <='Z') printf("%c", *ch_p - 'A' + 'a');
	else printf("%c", *ch_p);
	//当字符为元音，累加
	if (*ch_p == 'a' || *ch_p == 'e' || *ch_p == 'i' || *ch_p == 'u' || *ch_p == 'o' || *ch_p == 'A' ||*ch_p == 'E' || *ch_p == 'O' || *ch_p == 'I' || *ch_p == 'U')
	{
		count++;
	}
	return &count;
}
int main()
{
	char ch; int *Count=0;
	while ((ch = getchar()) != '\n')
	{
		Count=count(&ch);
	}
	printf(": %d", *Count);
	system("pause");
	return 0;
}