/*
数据结构课程实验三
内容:栈的表示与实现
时间:2018/3/27/16:24
Copyright@刘晗桐. All Rights Reserved.
*/
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

#define STACK_INIT_SIZE 10
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
typedef bool Status;
typedef char SElemType;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S) {
	//构造一个空栈S
	S.base = (SElemType *)malloc(sizeof(SElemType)*STACK_INIT_SIZE);
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(SqStack &S) {
	//销毁栈S,S不再存在
	free(S.base);
	free(S.top);
	S.stacksize = NULL;
	return OK;
}

SElemType *Push(SqStack &S, SElemType e){
	//插入元素e为新的栈顶元素 返回栈顶指针
	if (S.top - S.base >= S.stacksize) {
		//栈满,追加存储空间
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return S.top;
}

Status Pop(SqStack &S, SElemType &e) {
	//若栈不空, 则删除栈顶元素, 用e返回其值, 并返回OK, 否则返回 ERROR
	if (S.top == S.base) {
		printf("空栈 无法进行Pop操作\n");
		return ERROR;
	}
	e = *--S.top;
	return OK;
}

Status Print(SqStack &S) {
	//把栈中所有元素打印在屏幕上
	SElemType *Temp = S.top - 1;
	for (; Temp+1 != S.base; Temp--)
		printf("%c ", *Temp);
	printf("\n");
	return OK;
}

int main()
{
	//建立一个空栈;
	SqStack S;
	InitStack(S);
	//
	char New;
	while (OK) {
		New = getchar();
		getchar();
		if (New == *(S.top-1))
		{
			Pop(S, New);
			printf("与栈顶元素相同 弹出栈顶元素:\n");
			Print(S);
		}
		else if (New == '$')
		{
			printf("停止输入\n");
			break;
		}
		else
		{
			Push(S, New);
			printf("与栈顶元素不同 压入栈:\n");
			Print(S);
		}
	}
	system("pause");
	return 0;
}