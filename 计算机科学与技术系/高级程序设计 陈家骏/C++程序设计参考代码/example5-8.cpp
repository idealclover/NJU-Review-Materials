#include <iostream>
using namespace std;
int main()
{	const int M=2,N=3,T=4;
	int a[M][N],b[N][T],c[M][T];
	int i,j,k;
	cout << "请输入矩阵A(" << M << "×" << N << ")：\n";
	for (i=0; i<M; i++)
		for (j=0; j<N; j++)
			cin >> a[i][j];

	cout << "请输入矩阵B(" << N << "×" << T << ")：\n";
	for (i=0; i<N; i++)
		for (j=0; j<T; j++)
			cin >> b[i][j];

	for (i=0; i<M; i++) //对数组c的行循环
	{ for (j=0; j<T; j++) //对数组c的列循环
		{ c[i][j] = 0;
			for (k=0; k<N; k++) //计算c[i][j]
				c[i][j] += a[i][k]*b[k][j];
		}
	}
	cout <<	"矩阵C(" << M << "×" << T << ")为：\n";
	for (i=0; i<M; i++)
	{	for (j=0; j<T; j++)
			cout << c[i][j] << '凵';
		cout << endl;
	}
	return 0;
}
