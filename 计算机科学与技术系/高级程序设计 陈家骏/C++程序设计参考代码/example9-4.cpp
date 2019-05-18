template <class T, int size> 
class Stack
{		T buffer[size];
		int top;
	public:
		Stack() { top = -1; }
		bool push(const T &x);
		bool pop(T &x);
};
template <class T,int size> 
bool Stack <T,size>::push(const T &x) { /*......*/ return true; }

template <class T, int size> 
bool Stack <T,size>::pop(T &x) { /*......*/ return true; }

int main()
{ Stack<int,100> st1; //创建一个最多由100个int型元素所构成的栈对象。
  Stack<double,200> st2; //创建一个最多由200个double型元素所构成的栈对象。
  //.......
  return 0;
}
