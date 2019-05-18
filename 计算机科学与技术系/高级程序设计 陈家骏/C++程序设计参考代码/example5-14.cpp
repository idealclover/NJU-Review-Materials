#include <iostream>
using namespace std;
int main()
{ int max_len=20; //动态数组的大小，初始为20
  const int INCREMENT=10; //用于改变数组大小的增量
  int count=0, //对输入的数的个数进行计数
  int	n; //用于存储当前输入的数
  int *p=new int[max_len]; //创建初始的动态数组
  cin >> n; //输入第一个数
  while (n != -1) //循环输入各个数，直到输入了-1为止
  {	if (count >= max_len) //已有数组空间不够了
	  {	max_len += INCREMENT; 
		  int *q=new int[max_len]; //创建较大的动态数组
		  for (int i=0; i<count; i++) q[i] = p[i]; //转移已输入的数到新的数组中
		  delete []p; //撤消较小的数组
		  p = q; //p指向新的、较大的数组
	  }
	  p[count] = n; //存储输入的数
	  count++; //输入的数的个数加一
	  cin >> n; //输入下一个数
  }
  sort(p,count);
  delete []p; //撤消动态数组
  return 0;
}
