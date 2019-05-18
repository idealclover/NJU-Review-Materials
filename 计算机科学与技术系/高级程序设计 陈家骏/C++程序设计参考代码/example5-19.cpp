#include <iostream>
using namespace std;
int max(int x[], int n) //计算某一行的最大元素
{	int *p_max=x; //p_max指向最大元素，先假设第一个元素最大
	int *p=x+1, //p指向第二个元素
			*p_last=x+n-1; //p+last指向最后一个元素
	for ( ; p <= p_last; p++) //从第二个元素开始找最大元素
		if (*p > *p_max) p_max = p;
	return *p_max;
}
#define M 20
#define N 10
int main()
{	int a[M][N];
	//...... //获取数组元素的值
	int (*p)[N]=a, //p为数组的行指针，初始化为指向第一行，用于对数组的行进行遍历
			(*p_last_line)[N]=a+M-1; //p_last_line也为数组的行指针，它指向最后一行
	for ( ; p <= p_last_line; p++) //对数组的行进行循环，计算每一行的最大元素
		cout << max(*p,N) << endl;
	return 0;
}
