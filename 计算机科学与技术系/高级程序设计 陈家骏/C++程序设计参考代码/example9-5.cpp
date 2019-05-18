#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{	vector<int> v; //创建一个vector类容器对象v，其元素为int型

	//生成容器v中的元素
	int x;
	cin >> x;
	while (x > 0) //循环往容器v中增加正的int型元素
	{	v.push_back(x); //往容器v的尾部增加一个元素
		cin >> x;
	}

	//创建容器v的一个迭代器it1并使其指向容器v中的第一个元素位置
	vector<int>::iterator it1 = v.begin(); 
	
	//创建容器v的一个迭代器it2并使其指向容器v中的最后一个元素的下一个位置
	vector<int>::iterator it2 = v.end();

	//利用算法max_element计算并输出容器v中的最大元素
	cout << "Max = " << *max_element(it1,it2) << endl;
	
	//利用算法accumulate计算并输出容器v中所有元素的和
	cout << "Sum = " << accumulate(it1,it2,0) << endl;

	//利用算法sort对容器v中的元素进行排序
	sort(it1,it2); 
	
	//输出排序结果
	cout << "Sorted result is:\n";
	while (it1 != it2)
	{ cout << *it1 << ' '; //输出迭代器it1所指向的容器v的元素
		++it1; //使迭代器it1指向容器v中下一个元素
	}
	cout << endl;

	return 0;
}
