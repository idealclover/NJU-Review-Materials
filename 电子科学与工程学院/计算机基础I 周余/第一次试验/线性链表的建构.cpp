

//数据结构课程实验一



#include<cstdio>
#include<cstdlib>
#define ElemType int
#define print printf
#define MAX_NUMBER 100
#define Position_Insert 101
#define Data_Insert 101
#define Delete_Position 100



typedef struct LNode{ 
	//建立结点结构
	ElemType data;
	LNode *next;
}*Node;

typedef struct {
	//定义链表结构
	Node head, tail; //分别指向线性链表中的头结点和最后一个结点
	int len;
}Linklist;

Linklist *InitList() {
	//构造一个空的线性链表
	Linklist *Linklist1 = (Linklist *)malloc (sizeof(Linklist));
	Linklist1->head = (Node)malloc(sizeof(Node));
	Linklist1->tail= (Node)malloc(sizeof(Node));
	Linklist1->head->next = NULL;
	Linklist1->tail->next = NULL;
	Linklist1->len = 0;
	return Linklist1;
}

Linklist *Init_LinkList(int Len) {
	//建立链表创建函数
	Linklist *Linklist1 = InitList();
	while (Len > 0)
	{
		Node p = (Node)malloc(sizeof(Node));
		if (!p) exit(1);
		p->data = Len;
		p->next = Linklist1->head->next;
		Linklist1->head->next = p;
		if(Len == MAX_NUMBER) Linklist1->tail = p;
		Linklist1->len++, Len--;
		printf("Element %d 存入链表\n", p->data);
	}
	return Linklist1;
}

void insert(Linklist *L, int i, ElemType e){
	//在带头结点的单链表中第i个元素之前插入元素
	Node Move = (Node)malloc(sizeof(Node));
	Move = L->head->next;
	//寻找链表的插入节点前驱
	for (int Middle = 1; Middle < i-1; Middle++)
		Move = Move->next;
	//插入节点
	Node Insert = (Node)malloc(sizeof(Node));
	Insert->data = e;
	Insert->next = Move->next;
	Move->next = Insert;
}

void Delete(Linklist *L, int i, ElemType &e) {
	//删除链表中第i个元素
	Node Move = (Node)malloc(sizeof(Node));
	Move = L->head->next;
	//寻找链表的插入节点前驱
	for (int Middle = 1; Middle < i - 1; Middle++)
		Move = Move->next;
	Node Be_Delete = (Node)malloc(sizeof(Node));
	Be_Delete = Move->next;
	e = Be_Delete->data;
	Move->next = Move->next->next;
}

void Print_LinkList(Linklist *Linklist1){
	//建立链表打印函数
	int i = 1;
	if (Linklist1->len == 0) {
		printf("空链表\n");
		return;
	}
	Node Move = (Node)malloc(sizeof(Node));
	Move = Linklist1->head->next;
	while (Move != NULL){
		printf("Linklist 第 %d 个数据: %d\n", i++, Move->data);
		Move = Move->next;
	}
}
/*
int main()
{

	//创建一个存储 1~100 整数的链表
	printf("创建一个存储 1~100 整数的链表\n");
	Linklist *LinkList = Init_LinkList(MAX_NUMBER);

	//打印上述链表
	printf("\n\n打印上述链表\n");
	Print_LinkList(LinkList);

	//插入第101个结点
	printf("\n\n插入第101个结点后\n");
	insert(LinkList, Position_Insert, Data_Insert);
	Print_LinkList(LinkList);

	//删除第100个结点
	printf("\n\n删除第100个结点后\n");
	int Delete_Data;
	Delete(LinkList, Delete_Position, Delete_Data);
	Print_LinkList(LinkList);


	//找到两个链表的公共结点
	Linklist *Linklist1 = Init_LinkList(MAX_NUMBER);
	Linklist *Linklist2 = Init_LinkList(10);
	Linklist2->head->next->next = Linklist1->head->next->next->next;
	Linklist2->tail = Linklist1->tail;
	Node FindFirstCommonNode(Linklist *Link1, Linklist *Link2);
	Node Common = FindFirstCommonNode(Linklist1, Linklist2);

	printf("\n\n链表1:\n");
	Print_LinkList(Linklist1);

	printf("\n\n链表2:\n");
	Print_LinkList(Linklist2);

	printf("\n\n公共结点的元素为:%d\n", Common->data);

	//将链表2转置
	printf("\n\n将链表2转置:\n");
	void Reverse_LinkList(Linklist *Linklist);
	Reverse_LinkList(Linklist2);
	Print_LinkList(Linklist2);

	system("pause");
	return 0;

}
*/

Node FindFirstCommonNode(Linklist *Link1, Linklist *Link2) {
	//求两个带头结点的单链表的相交的第一个结点
	int flag = 0;
	if (Link1->tail != Link2->tail) {
		printf("没有公共结点");
		exit(1);
	}
	Node Link1_Move = (Node)malloc(sizeof(Node));
	Link1_Move = Link1->head;
	while(Link1_Move != NULL){
		//遍历第一个链表
		Node Link2_Move = (Node)malloc(sizeof(Node));
		Link2_Move = Link2->head;
		for (; Link2_Move != NULL; Link2_Move = Link2_Move->next) 
		{
			if (Link2_Move == Link1_Move)
			{
				flag = 1;
				break;
			}
		}
		if (flag) break;
		Link1_Move = Link1_Move->next;
	}
	return Link1_Move;
}



void Reverse_LinkList(Linklist *Linklist) {
	//将单链表进行就地逆置
	Node Pre_Node = (Node)malloc(sizeof(Node));
	Node Front_Node = (Node)malloc(sizeof(Node));
	Node Middle_Node = (Node)malloc(sizeof(Node));

	Front_Node = Linklist->head->next->next;
	Middle_Node = Linklist->head->next;
	//先将头结点进行转置
	Linklist->head->data = Linklist->head->next->data;
	Linklist->head->next = NULL;
	Linklist->tail = Linklist->head;

	Pre_Node = Linklist->head;

	while (Front_Node->next != NULL)
	{
		Middle_Node->next = Pre_Node;
		Middle_Node->data = Front_Node->data;
		Pre_Node = Middle_Node;
		Middle_Node = Front_Node;
		Front_Node = Front_Node->next;
	}
	Middle_Node->data = Front_Node->data;
	Middle_Node->next = Pre_Node;
	Front_Node->next = Middle_Node;
	Linklist->head = Front_Node;
}
