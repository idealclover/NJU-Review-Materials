//顺序查找
#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LEN=20;
const int TABLE_LEN=100;
struct TableItem
{ char name[NAME_LEN];
  // ...... //其它信息
};	
TableItem name_table[TABLE_LEN]={"北京","上海","南京","广州","武汉" ,"哈尔滨","西藏"};

int linear_search(char key[], TableItem t[], int num_of_items)
{	int index;
	for (index=0; index<num_of_items; index++)
		if (strcmp(key,t[index].name) == 0) break;
	if (index < num_of_items)
		return index;
	else
		return -1;
}

int main()
{ 
  for (int i=0; i<7; i++)
    cout << name_table[i].name << ' ';
  cout << endl;

	int result;
	result = linear_search("南京",name_table,7);
	cout << "南京: " << result << endl;
	return 0;
}

/*
//二分法查找
#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LEN=20;
const int TABLE_LEN=100;
struct TableItem
{ char name[NAME_LEN];
  // ...... //其它信息
};	
TableItem name_table[TABLE_LEN]={"北京","上海","南京","广州","武汉" ,"哈尔滨","西藏"};

int binary_search(char key[], TableItem t[], int num_of_items)
{	int index,first,last;
	first = 0;
	last = num_of_items-1;
	while (first <= last)
	{	index = (first+last)/2;
		int r=strcmp(key,t[index].name);
		if (r == 0)  // key等于t[index].name
			return index;
		else if (r > 0)  // key大于t[index].name
			first = index+1;
		else  //key小于t[index].name
			last = index-1;
	}
	return -1;
}

int max(TableItem x[],int n) //计算x中最大元素的下标
{	int i,j;
	j = 0; 	//j用于保存最大元素的下标，首先假设第0个元素最大
	for (i=1; i<n; i++)
		if (strcmp(x[i].name,x[j].name) > 0) j = i;  //修改j的值，使其一直为最大元素的下标。
	return j;
}

void sel_sort(TableItem x[], int n)
{ int i,j;	
	for (i=n; i>1; i--) 
	{	j = max(x,i);  //计算x的前i个元素中最大元素的下标j。
		//交换x[j]和x[i-1]的值
		TableItem temp;
    temp = x[j];
		x[j] = x[i-1];
		x[i-1] = temp;
	}
}

int main()
{ 
  sel_sort(name_table,7);
  for (int i=0; i<7; i++)
    cout << name_table[i].name << ' ';
  cout << endl;

	int result;
	result = binary_search("南京",name_table,7);
	cout << "南京: " << result << endl;
	return 0;
}
*/