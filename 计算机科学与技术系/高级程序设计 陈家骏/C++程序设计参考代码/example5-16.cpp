#include <iostream>
using namespace std;
struct Node
{	int no;  //小孩的编号
	Node *next; //指向下一个小孩的指针
};
int main()
{	int m, //用于存储要报的数
		n, //用于存储小孩的个数
		num_of_children_remained; //用于存储圈子里剩下的小孩个数
	cout << "请输入小孩的个数和要报的数：";
	cin >> n >> m;
	//构建圈子
	Node *first,*last; //first和last用于分别指向第一个和最后一个小孩
	first = last = new Node;  //生成第一个结点
	first->no = 0; //第一个小孩的编号为0
	for (int i=1; i<n; i++) //循环构建其它小孩结点
	{	Node *p=new Node;  //生成一个小孩结点
		p->no = i; //新的小孩结点的编号为i
		last->next = p; //最后一个小孩的next指向新生成的小孩结点
		last = p; //把新生成的小孩结点成为最后一个结点
	}
	last->next = first;  //把最后一个小孩的下一个小孩设为第一个小孩
	
	//开始报数
	num_of_children_remained = n;  //报数前的圈子中小孩个数
	Node *previous=last;  //previous指向开始报数的前一个小孩
	while (num_of_children_remained > 1)
	{	for (int count=1; count<m; count++)  //循环m-1次
			previous = previous->next;
		//循环结束时，previous指向将要离开圈子的小孩的前一个小孩
		Node *p=previous->next;  //p指向将要离圈的小孩结点
		previous->next = p->next;  //小孩离开圈子
		delete p;  //释放离圈小孩结点的空间
		num_of_children_remained--;  //圈中小孩数减1
	}
	
	//输出胜利者的编号
	cout << "The winner is No." << previous->no << "\n";
	delete previous;  //释放胜利者结点的空间
	return 0;
}
