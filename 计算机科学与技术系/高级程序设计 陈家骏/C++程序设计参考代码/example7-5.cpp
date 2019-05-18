#include <iostream>
#include <cstring>
using namespace std;
class A
{		int x,y;
	public:
		void *operator new(size_t size)
		{	char *p=new char[size]; //调用系统堆空间分配操作。
			memset(p,0,size); //把申请到的堆空间初始化为全"0"。
			return p;
		}
    void display()
    { cout << x << ',' << y;
    }
		//......
};
int main()
{ A *p=new A; //对象的数据成员x和y被初始化为0。
  
  p->display();
  
  delete p;
  return 0;
}
