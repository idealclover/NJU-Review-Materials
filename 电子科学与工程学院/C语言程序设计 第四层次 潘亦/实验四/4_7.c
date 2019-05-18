#include<cstdio>
#include<cstdlib>
int main()
{ 
	for (int k = 2; k <= 1000; k++)
	{
		int m=0;
		int sum = 0;
		m = k;
		int n; n = k;
		for (int a = 2; a < m; a++)
		{
			if (m%a == 0) sum += a;
		}
		if ((sum+1) == m) printf("%d\n",m);
	}
	system("pause");
	return 0;
}