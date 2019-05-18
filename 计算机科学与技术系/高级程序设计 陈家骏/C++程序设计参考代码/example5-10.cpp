//1、选择排序
#include <iostream>
using namespace std;
void sel_sort(int x[], int n)
{	for ( ; n>1; n--)  //基于数的个数进行循环，每次减少一个数
	{	int i_max=0; //i_max用于保存最大元素的下标，首先假设第0个元素最大
		for (int i=1; i<n; i++) //循环找前n个数中的最大元素
			if (x[i] > x[i_max]) i_max = i; //修改i_max的值，使其一直为最大元素的下标
		//交换x[i_max]和x[n-1]的值
		int temp = x[i_max];
		x[i_max] = x[n-1];
		x[n-1] = temp;
	}
}
const int N=10;
int main()
{	int a[N],i;
	for (i=0; i<N; i++)  //输入N个整型数
		cin >> a[i]; 
	sel_sort(a,N);
	for (i=0; i<N; i++)  //输出排序结果
		cout << a[i] << ' '; 
	cout << endl;
	return 0;
}


/*
//2、快速排序
#include <iostream>
using namespace std;

int split(int x[],int first, int last)
{	int split_point,pivot;
	pivot = x[first];
	split_point = first;
	for (int unknown=first+1; unknown <=last; unknown++)
		if (x[unknown] < pivot)
		{	split_point++;
			//交换x[split_point]和x[unknown]的值
			int t=x[split_point];
			x[split_point] = x[unknown];
			x[unknown] = t;
		}
	//交换x[first]和x[split_point]的值
	x[first] = x[split_point];
	x[split_point] = pivot;
	return split_point;
}

void quick_sort(int x[],int first, int last)
{	if (first < last)
	{	int split_point;
		split_point = split(x,first,last);
		quick_sort(x,first,split_point-1);
		quick_sort(x,split_point+1,last);
	}
}

const int N=10;
int main()
{	int a[N],i;
	for (i=0; i<N; i++)  //输入N个整型数
		cin >> a[i]; 
	quick_sort(a,0,N-1);
	for (i=0; i<N; i++)  //输出排序结果
		cout << a[i] << ' '; 
	cout << endl;
	return 0;
}
*/