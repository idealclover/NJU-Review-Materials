#include <iostream>
#include <list>
using namespace std;
int main()
{	int m,n; //m用于存储要报的数，n用于存储小孩个数
	cout << "请输入小孩的个数和要报的数：";
	cin >> n >> m;

	//构建圈子
	list<int> children; //children是用于存储小孩编号的容器
	for (int i=0; i<n; i++) //循环创建容器元素
		children.push_back(i); //把i（小孩的编号）放入容器尾部
	
	//开始报数
	list<int>::iterator current; //current为指向容器元素的迭代器
	current = children.begin(); //current初始化成指向容器的第一个元素
	while (children.size() > 1) //只要容器元素个数大于1，就执行循环
	{	for (int count=1; count<m; count++)  //报数，循环m-1次
		{	current++; //current指向下一个元素
			if (current == children.end()) //如果current指向的是容器末尾
				current = children.begin();  //current指向第一个元素
		}
		//循环结束时，current指向将要离开圈子的小孩
		current = children.erase(current);  //小孩离开圈子，current指向下一个元素
		if (current == children.end()) //如果current指向的是容器末尾
			current = children.begin();  //current指向第一个元素
	} //循环结束时，current指向容器中剩下的唯一的一个元素，即胜利者
	
	//输出胜利者的编号
	cout << "The winner is No." << *current << "\n";
	return 0;
}
