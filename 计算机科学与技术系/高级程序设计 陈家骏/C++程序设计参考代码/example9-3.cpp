template <class T> 
class Stack
{		T buffer[100];
		int top;
	public:
		Stack() { top = -1; }
		bool push(const T &x);
		bool pop(T &x);
};
template <class T> 
bool Stack <T>::push(const T &x) { /*......*/ return true; }

template <class T> 
bool Stack <T>::pop(T &x) { /*......*/ return true; }
class A
{ //......
};

int main()
{ Stack<int> st1; //创建一个元素为int型的栈对象。
  int x;
  st1.push(10);
  st1.pop(x);
  Stack<double> st2; //创建一个元素为double型的栈对象。
  double y;
  st2.push(1.2);
  st2.pop(y);
  Stack<A> st3; //创建一个元素为A类型的栈对象（A为定义的一个类）。
  A a,b;
  st3.push(a);
  st3.pop(b);
  //......
  return 0;
}