#include <iostream>
#include <cstring>
using namespace std;
int find_substr(char str[], char sub_str[])
{	int len=strlen(str), //主串长度
			sub_len=strlen(sub_str); //子串的长度
	for (int i=0; i<=len-sub_len; i++) //从主串的头开始循环查找子串
	{	//下面的循环在主串中从位置i开始逐个字符与子串中的字符进行比较
		int j=0;
		while (j < sub_len && sub_str[j] == str[i+j]) j++;
		if (j == sub_len) return i; //匹配到子串，返回它在主串中的位置i
	}
	return -1; //未找到子串，返回-1
}
