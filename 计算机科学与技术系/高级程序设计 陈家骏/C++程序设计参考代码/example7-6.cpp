#include <iostream>
using namespace std;
#include <cstring>
const int NUM=32;
class A
{		int x,y; //类A的已有成员说明。
	public:
		static void *operator new(size_t size);
		static void operator delete(void *p);
	private:
		static A *p_free; //用于指向A类对象的自由空间链表。
		A *next; //用于实现自由空间结点的链接。
};
A *A::p_free=NULL;
void *A::operator new(size_t size)
{	cout << "In self defined operator new\n";
  A *p;
	if (p_free == NULL)
	{	p_free = (A *)new char[size*NUM];  //申请NUM个A类对象的堆空间。
		for (p=p_free; p!=p_free+NUM-1; p++)  //建立自由结点链表。
			p->next = p+1;
		p->next = NULL;
	}
	p = p_free; //为当前创建的对象分配空间
	p_free = p_free->next;
	memset(p,0,size);
	return p;
}
void A::operator delete(void *p)
{	((A *)p)->next = p_free;
	p_free = (A *)p;
}

int main()
{ A *p=new A; //对象的数据成员x和y被初始化为0。
  
  //....

  delete p;
  return 0;
}
