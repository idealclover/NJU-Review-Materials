#include <iostream>
using namespace std;
class A
{		int x,y;
	public:
		void f() {;}
		void g() {;}
};

class B  //智能指针类
{		A *p_a;
		int count;
	public:
		B(A *p) 
		{	p_a = p; 
			count = 0; 
		}
		A *operator ->()  //操作符"->"的重载函数
		{	count++; 
			return p_a; 
		}
		int num_of_a_access() const
		{	return count; 
		}
};
int main()
{
  A a;
  B b(&a);  //b为一个智能指针，它"指向"了a。
  b->f();  //等价于：b.operator->()->f(); 即访问的是a.f()
  b->g();  //等价于：b.operator->()->g(); 即访问的是a.g()
  cout << b.num_of_a_access() << endl; // 显示对象a的访问次数
  return 0;
}
