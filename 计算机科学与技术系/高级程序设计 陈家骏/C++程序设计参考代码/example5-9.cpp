#include <iostream>
using namespace std;
const int N=20,M=5;
int main()
{	bool in_circle[N];
	int num_of_children_remained,index;
	//初始化数组in_circle。
	for (index=0; index<N; index++)  
		in_circle[index] = true;
	
	//开始报数
	index = N-1;  //从编号为0的小孩开始报数，index为前一个小孩的下标。
	num_of_children_remained = N;  //报数前的圈子中小孩个数。
	while (num_of_children_remained > 1)
	{	int count = 0;
		while (count < M)  //对成功的报数进行计数。
		{	index = (index+1)%N;  //计算要报数的小孩的编号。
			if (in_circle[index]) count++;  
									//如果编号为index的小孩在圈子中，该报数为成功的报数。
		}
		in_circle[index] = false;  //小孩离开圈子
		num_of_children_remained--;  //圈中小孩数减1。
	}
	
	//找最后一个小孩
	for (index=0; index<N; index++) 
		if (in_circle[index]) break;
	
	cout << "The winner is No." << index << ".\n";
	return 0;
}
