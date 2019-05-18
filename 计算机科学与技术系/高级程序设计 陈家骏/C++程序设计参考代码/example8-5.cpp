#define NULL 0
class Stack
{	public:
		virtual bool push(int i)=0;
		virtual bool pop(int& i)=0;
};
class ArrayStack: public Stack
{		int elements[100],top;
  public:
   	ArrayStack() { top = -1; }
		bool push(int i) { /*......*/ return true; }
		bool pop(int& i) { /*......*/ return true; }
};
class LinkedStack: public Stack
{		struct Node
		{	int content;
			Node *next;
		} *first;
	public:
		LinkedStack() { first = NULL; }
		bool push(int i) { /*......*/ return true; }
		bool pop(int& i) { /*......*/ return true; }
};
//......
void f(Stack *p)
{	//......
	p->push(10);  //将根据p所指向的对象类来确定push的归属。
	//......
  int x;
	p->pop(x);  //将根据p所指向的对象类来确定pop的归属。
	//......
}
int main()
{	ArrayStack st1;
	LinkedStack st2;
	f(&st1);  //OK
	f(&st2);  //OK
  //......
	return 0;
}
