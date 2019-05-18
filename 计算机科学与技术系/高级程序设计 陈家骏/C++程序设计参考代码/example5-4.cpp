#include <iostream>
#include <cstring>
using namespace std;
int str_to_int(char str[])
{	if (str[0] == '\0') return 0; //如果字符串为空，则返回0作为转换结果
	int n=str[0]-'\0'; //n用于存储转换结果，初始化为最高位数字的数值
	for (int i=1; str[i]!='\0'; i++) //循环处理其它数位的数字
		n = n*10+(str[i]-'0'); 
	return n;
}

/*
#include <iostream>
#include <cstring>
using namespace std;
int str_to_int(char str[])
{	int n=0; //n用于存储转换结果，初始化为0
	for (int i=0; str[i]!='\0'; i++) //循环处理每一位数字
		n = n*10+(str[i]-'0'); //对最高位而言，空做一次乘法（乘以0）
	return n;
}

*/