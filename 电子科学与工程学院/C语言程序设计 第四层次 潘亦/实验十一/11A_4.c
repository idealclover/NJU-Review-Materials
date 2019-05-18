//..4．按要求编写程序。
//...⑴ 编写函数void  line_sort(int a[][4], int b[], int n)，n为行数，根据a指向的数组，
//...计算各行元素之和, 并保存到b指向的数组中，根据和的大小将a指向的
//...数组以行为单位按从小到大的顺序重新排列。
//...⑵ 编写main函数，初始化二维数组，输出原始数组，
//...并调用line_sort函数得到变化以后的数组及每行之和，输出新数
//...组的各行元素以及每行元素的和。
#include<cstdio>
#include<cstdlib>
void print(int a[][4], int m, int n);
void line_sort(int a[][4], int b[], int n)
{
	int B_number = 0;
	//先对数组进行分行求和并保存在数组b中
	for (int x = 0; x < n; x++)
	{
		int count = 0;
		for (int m = 0; m < 4; m++)
			count += a[x][m];
		b[B_number++] = count;
	}
	//利用选择排序法对数组进行排序
	for (int i = 0; i < n-1; i++)
	{
		int point = i;
		for (int j = i + 1; j < n; j++)
			if (b[point] > b[j]) point = j;
		if (b[point] != b[i])
		{
			int t = b[i];
			b[i] = b[point];
			b[point] = t;
		}
		//同时对数组进行[行交换]
		for (int m = 0; i != point&&m < n-1; m++)
		{
			int h = a[i][m];
			a[i][m] = a[point][m];
			a[point][m] = h;
		}
	}
}
//定义一个函数输出数组中的元素
void print(int a[][4],int m,int n)
{
	for (int p = 0; p < m; p++)
	{
		for (int q = 0; q < n; q++)
			printf("%5d", a[p][q]);
		printf("\n");
	}
}
int main()
{
	int a[][4] = { 1,4,5,7,3,5,7,8,9,10,2,3,1,3,4,2,1,2,1,1 };
	int b[10];
	print(a, 5, 4);
	printf("\n");
	line_sort(a, b, 5);
	print(a, 5, 4);
	printf("每行元素之和分别为:%d %d %d %d %d\n", b[0], b[1], b[2], b[3], b[4]);
	system("pause");
	return 0;
}
