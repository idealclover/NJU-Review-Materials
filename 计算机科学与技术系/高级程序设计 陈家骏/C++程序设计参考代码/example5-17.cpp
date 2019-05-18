#include <iostream>
#include <cmath>
using namespace std;
const int MAX_LEN=8;
typedef double (*FP)(double);
FP func_list[MAX_LEN]={sin,cos,tan,asin,acos,atan,log,log10};
int main()
{	int index;
	double x;
	do  //循环以获得正确的输入
	{	cout << "请输入要计算的函数(0:sin 1:cos 2:tan 3:asin\n"
				<< "4:acos 5: atan 6:log 7:log10):";
		cin >> index;
	} while (index < 0 || index > 7);
	cout << "请输入参数：";
	cin >> x;
	cout << "结果为：" << (*func_list[index])(x) << endl;
	return 0;
}
