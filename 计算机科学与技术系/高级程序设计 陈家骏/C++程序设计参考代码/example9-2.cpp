template <class T> 
void sort(T elements[], unsigned int count)
{	/*
	1、取第i个元素
	elements[i] 
	
	2、比较第i个和第j个元素的大小
	elements[i] < elements [j] 
	
	3、交换第i个和第j个元素
	T temp=elements [i];
	elements[i] = elements [j];
	elements[j] = temp;
	*/
}

class A
{ //......
  public:
    bool operator < (const A &a);
};

int main()
{ int a[100];
  sort(a,100);  //调用void sort(int elements[], unsigned int count)
  double b[200]; 
  sort(b,200);  //调用void sort(double elements[], unsigned int count)
  A c[300];  //类A中需重载操作符：<，需要时还应自定义拷贝构造函数和重载操作符=。
  sort(c,300);  //调用void sort(A elements[], unsigned int count)
  return 0;
}