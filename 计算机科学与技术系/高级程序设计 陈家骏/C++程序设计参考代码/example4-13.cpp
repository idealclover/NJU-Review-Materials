#include <iostream>
using namespace std;
void hanoi(char x,char y,char z,int n) //把n个圆盘从x表示的柱子移至y所表示的柱子。
{	if (n == 1)
		cout << "1: " << x << "→" << y << endl;  //把第1个盘子从x表示的柱子移至
                                                      //y所表示的柱子。
	else
	{	hanoi(x,z,y,n-1);  //把n-1个圆盘从x表示的柱子移至z所表示的柱子。
		cout << n << ": " << x << "→" << y << endl;  
									//把第n个圆盘从x表示的柱子移至y所表示的柱子。
		hanoi(z,y,x,n-1);  //把n-1个圆盘从z表示的柱子移至y所表示的柱子。
	}
}
