#include <iostream>
#include <cstring>
using namespace std;

class LinearList
{		//......
	public:
		bool insert(int x, int pos); //在线性表中位置pos后面增加元素。
												  //当pos为0时，在表头增加元素；
												  //返回值表示操作成功或失败。
		bool remove(int &x, int pos); //删除线性表中位置pos处的元素。
												   //返回值表示操作成功或失败。
		int element(int pos) const; //返回位置pos处的元素。
		int search(int x) const; //查找值为x的元素，返回元素的位置。未找到时返回0。
		int length() const; //返回元素个数。
};

//用继承实现Queue
class Queue: private LinearList //这里的继承方式private可以省略。
{	public:
		bool en_queue(int x) //元素进队。
		{	return insert(x,length());
		}
		bool de_queue(int &x) //元素出队。
		{ return remove(x,1);
		}
};

/*
//用聚集实现Queue
class Queue
{		LinearList list;
	public:
		bool en_queue(int i) 
		{	return list.insert(i,list.length());
		}
		bool de_queue(int &i) 
		{ return list.remove(i,1);
		}
};
*/