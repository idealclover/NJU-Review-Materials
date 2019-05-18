#pragma once
//构造树类
#define Status bool
#define OK true
#define ERROR false 
#include<iostream>
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
using namespace std;
class tree {
	public:
		Status CreateBiTree(BiTree &T);
		//按先序次序输入二叉树中结点的值
		//构造二叉链表表示的二叉树T
		Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e));
		//采用二叉链表存储结构,Visit是对结点操作的应用函数
		//先序遍历二叉树T,对每个结点调用函数Visit一次且仅一次
		//一旦visit()失败, 则操作失败
		Status InOrderTraverse(BiTree T, Status(*visit)(TElemType e));
		//采用二叉链表存储结构, Visit是对结点操作的应用函数.
		//中序遍历二叉树T, 对每个节点调用函数Visit一次且仅一次.
		//一旦visit()失败, 则操作失败
		Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e));
		//采用二叉链表存储结构, Visit是对结点操作的应用函数.
		//后序遍历二叉树T, 对每个节点调用函数Visit一次且仅一次.
		//一旦visit()失败, 则操作失败
		Status BiTree_Transposition(BiTree &T);
		//调用该函数对二叉树进行转置
};



Status tree::CreateBiTree(BiTree &T) {
	//按先序次序输入二叉树中结点的值(一个字符), 空格字符表示空树)
	//构造二叉链表表示的二叉树T
	char ch;
	cin >> ch;
	if (ch == '*') T = NULL;
	else {
		if (!(T = new BiTNode)) exit(OVERFLOW);
		T->data = ch;                     //生成根结点
		CreateBiTree(T->lchild);          //构造左子树
		CreateBiTree(T->rchild);          //构造右子树
	}
	return OK;
}

Status tree::PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	//采用二叉链表存储结构, Visit是对数据元素操作的应用函数,
	//先序遍历二叉树T的递归函数, 对每个数据元素调用函数Visit.
	//最简单的Visit函数是:
	// Status PrintElement( TElemType e ){
	//	 printf(e);
	//   return OK;
	// }
	//调用实例:PrePrderTraverse(T, PrintElement);
	if (T) {
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit)) return OK;
		return ERROR;
	}
	else return OK;
}//PreOrderTtraverse

Status tree::InOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		if (InOrderTraverse(T->lchild, Visit))
			if (Visit(T->data))
				if (InOrderTraverse(T->rchild, Visit)) return OK;
		return ERROR;
	}
}//InOrderTraverse

Status tree::PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		if (PostOrderTraverse(T->lchild, Visit))
			if (PostOrderTraverse(T->rchild, Visit))
				if (Visit(T->data)) return OK;
		return ERROR;
	}
}//PostOrderTraverse

Status tree::BiTree_Transposition(BiTree &T) {
	BiTree Current = new BiTNode;
	if (T) {
		Current = T->lchild;
		T->lchild = T->rchild;
		T->rchild = Current;
		if (BiTree_Transposition(T->lchild))
			if (BiTree_Transposition(T->rchild))
				return OK;
	}
	return ERROR;
}