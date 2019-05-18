struct Node
{	int content;  //代表结点的数据
	Node *next;  //代表后一个结点的地址
}; 
extern Node *input(); //输入数据，建立链表
extern void sort(Node *h); //排序
extern void output(Node *h); //输出数据
extern void remove(Node *h); //删除链表
int main()
{ Node *head;
	head = input();
	sort(head);
	output(head);
	remove(head);
  return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
Node *input() //从表尾插入数据
{ Node *head=NULL,*tail;
	int x;
	cin >> x;
	while (x != -1)
	{ Node *p=new Node;
	   p->content = x;
	   p->next = NULL;
	   if (head == NULL)
	     head = p;
     else
			tail->next = p;
     tail = p;
     cin >> x;
	}
	return head;
}
void sort(Node *h) //采用选择排序，小的往前放
{ if (h == NULL || h->next == NULL) //链表中没有或只有一个结点
		return;
	//从链表的头开始逐步缩小链表的范围
  for (Node *p1=h; p1->next != NULL; p1 = p1->next)
	{ Node *p_min=p1; //p_min指向最小的结点，初始化为p1
		//从p1的下一个开始与p_min进行比较
		for (Node *p2=p1->next; p2 != NULL; p2=p2->next) 
			if (p2->content < p_min->content)  p_min = p2; //保持p_min指向最小的
		if (p_min != p1)
		{ int temp = p1->content;
			p1->content = p_min->content;
			p_min->content = temp;
		}
	}
}
void output(Node *h)
{ for (Node *p=h; p!=NULL; p=p->next)
	 	cout << p->content << ',';
   cout << endl;
}
void remove(Node *h)
{	while (h != NULL)
	{	Node *p=h;
		h = h->next;
		delete p;
	}
}
