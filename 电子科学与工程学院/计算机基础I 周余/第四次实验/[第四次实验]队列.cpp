#include<iostream>
using namespace std;

typedef int QElemType;
typedef bool Status;
#define OK true
#define ERROR false
typedef struct QNode {
	//节点结构
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q);     //构造一个空队列
Status DestroyQueue(LinkQueue &Q);  //销毁一个队列 队列Q将不存在
Status EnQueue_Tail(LinkQueue &Q, QElemType e);  //插入元素e为Q新的队尾元素
Status EnQueue_Head(LinkQueue &Q, QElemType e);  //插入元素e为Q新的队头元素
Status DeQueue_Head(LinkQueue &Q, QElemType &e); //若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK;//否则返回ERROR
Status DeQueue_Tail(LinkQueue &Q, QElemType &e); //若队列不空, 则删除Q的队尾元素, 用e返回其值, 并返回OK;//否则返回ERROR
Status ClearQueue(LinkQueue &Q);                 //将队列清空

int main() {
	//给定n,k的值以及数列
	int n, k;
	cout << "请输入n和k的值:" << endl;
	cin >> n >> k;
	int *list = (int*)malloc(n * sizeof(int));
	cout << "请输入数列元素" << endl;
	for (int i = 0; i < n; i++)
		cin >> list[i];
	//建立一个新的双向队列
	LinkQueue Q;
	InitQueue(Q);
	cout << "滑动最小值如下:" << endl;
	cout << "[";
	int Frequency = 0; //标记操作次数
	int Pop;
	for (int i = 0; i <= n; i++) {
		if (Frequency >= k) cout << list[Q.front->data] << " ";
		if (i == n) break;
		if (Frequency == 0) {
			EnQueue_Head(Q, i);
			Frequency++;
		}
		if (i - Q.front->data >= k)
		{
			DeQueue_Head(Q, Pop);
		}
		if (list[i] < list[Q.front->data] &&list[i] < list[Q.rear->data]) {
			InitQueue(Q);
			EnQueue_Head(Q, i);
			Frequency++;
		}
		else if (list[i] > list[Q.front->data] && list[i] > list[Q.rear->data]) {
			EnQueue_Tail(Q, i);
			Frequency++;
		}
		else if (list[i] > list[Q.front->data] && list[i] < list[Q.rear->data]) {
			DeQueue_Tail(Q, Pop);
			EnQueue_Tail(Q, i);
			Frequency++;
		}

	}
	cout << "]" << endl;
	system("pause");
	return 0;
}

Status InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q) {
	while (Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status EnQueue_Tail(LinkQueue &Q, QElemType e) {
	 //插入e为Q的新的队尾元素
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue_Head(LinkQueue &Q, QElemType &e) {
	//删除队列的头元素
	if (Q.front == Q.rear) return ERROR;
	QueuePtr p = Q.front;
	e = p->data;
	p = Q.front->next;
	Q.front = p;
	if (Q.rear == p) Q.rear = Q.front;
	return OK;
}

Status DeQueue_Tail(LinkQueue &Q, QElemType &e) {
	//删除队列的尾元素
	QueuePtr Current = Q.front;
	while (Current->next != Q.rear)
		Current = Current->next;
	e = Current->data;
	free(Current->next);
	Q.rear = Current;
	Q.rear->next = NULL;
	return OK;
}

Status EnQueue_Head(LinkQueue &Q, QElemType e) {
	//插入e为新的队头元素
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = Q.front->next;
	Q.front->next = p;
	Q.front = p;
	if (!Q.front->next) Q.rear = Q.front;
	return OK;
}

