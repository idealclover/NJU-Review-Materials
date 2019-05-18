#include <iostream>
#include <cstring>
using namespace std;
int main()
{	const int MAX_LEN=100;
	char str[MAX_LEN];
	cin >> str;
	int len = strlen(str); //len为字符串的长度
	for (int i=0,j=len-1; i<j; i++,j--) //i和j分别从字符串的头和尾往中间位置移动
	{	//交换str[i]和str[j]中的字符
		char temp;
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	cout << str << endl;
	return 0;
}
