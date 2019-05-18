#include <iostream>
using namespace std;
int main()
{	const int N=3;
	int a[N][N]; 
	int i,j;
	//输入矩阵数据
	cout << "请输入" << N << "×" << N << "矩阵：\n";
	for (i=0; i<N; i++)
		for (j=0; j<N; j++)
			cin >> a[i][j];
	//矩阵转置
	for (i=0; i<N; i++)
		for (j=i+1; j<N; j++)
		{	//交换a[i][j]与a[j][i]的值
			int temp=a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	//输出转置后的矩阵
	cout <<	"转置后为：\n";
	for (i=0; i<N; i++)
	{	for (j=0; j<N; j++)
			cout << a[i][j] << '凵';
		cout << endl;
	}
	return 0;
}
