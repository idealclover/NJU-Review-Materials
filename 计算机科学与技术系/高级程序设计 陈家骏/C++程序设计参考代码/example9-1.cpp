void sort(void *base, //需排序的数据首地址
			     unsigned int count, //数据元素的个数
				   unsigned int element_size, //数据元素的尺寸
				   int (*cmp)(const void *, const void *) 
									//比较两个数组元素大小的函数指针
				)
{	/*
	不论采用何种排序算法，一般都需要对数组进行以下操作：	
	1、取第i个元素
	(char *)base+i*element_size
	
	2、比较第i个和第j个元素的大小 
	(*cmp)((char *)base+i*element_size,(char *)base+j*element_size)
	
	3、交换第i个和第j个元素
	char *p1=(char *)base+i*element_size,
			 *p2=(char *)base+j*element_size;
	for (int k=0; k<element_size; k++)
	{	char temp=p1[k];
		p1[k] = p2[k];
		p2[k] = temp;
	}
	*/
}
int int_compare(const void *p1, const void *p2)  
//比较int类型元素大小。
{	if (*(int *)p1 < *(int *)p2) 
		return -1;
	else if (*(int *)p1 > *(int *)p2) 
		return 1;
	else 
		return 0;
}
int double_compare(const void *p1, const void *p2) 
//比较double类型元素大小。
{	if (*(double *)p1 < *(double *)p2) 
		return -1;
	else if (*(double *)p1 > *(double *)p2) 
		return 1;
	else 
		return 0;
}

class A
{ //......
  public:
    bool operator < (const A &a);
    bool operator > (const A &a);
};

int A_compare(const void *p1, const void *p2) 
//比较A类元素大小。
{	if (*(A *)p1 < *(A *)p2)  //类A需重载操作符：<
		return -1;
	else if (*(A *)p1 > *(A *)p2)  //类A需重载操作符：>
		return 1;
  else 
		return 0;
}
int main()
{ int a[100];
  sort(a,100,sizeof(int),int_compare);
  double b[200];
  sort(b,200,sizeof(double),double_compare);
  A c[300];
  sort(c,300,sizeof(A),A_compare);
  //......
  return 0;
}