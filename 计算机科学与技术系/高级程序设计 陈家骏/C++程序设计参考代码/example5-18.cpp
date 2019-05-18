#include <iostream>
#include <cstring>
using namespace std;
void reverse(char *str)
{	char *p1=str, //指向字符串的头
			*p2=str+strlen(str)-1; //指向字符串的尾
	for ( ; p1 < p2; p1++,p2--) //p1和p2分别从字符串的头和尾往中间位置移动
	{	//交换*p1和*p2的值
		char temp=*p1;
		*p1 = *p2;
		*p2 = temp;
	}
}
int main()
{ char str[100];

  cin >> str;
  reverse(str);
  cout << str << endl;
  return 0;
}