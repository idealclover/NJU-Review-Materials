//程序1：
#include <iostream>
using namespace std;
int main()
{	double x;
	int n;
	cout << "请输入x和n：";
	cin >> x >> n;
	double sum = 1+x; 
	//依次计算x2/2!、…、xi/i!、… 、xn-1/(n-1)!并加到sum中。
	for (int i=2; i<n; i++) 
	{	int j,a=1,b=x; 
		for (j=2; j<=i; j++) a *= j; //计算i!
		for (j=2; j<=i; j++) b *= x; //计算xi
		sum += b/a; //计算xi/i!并把它加到sum中
	}
	cout << "x=" << x << ",n=" << n << ",sum=" << sum << endl;
	return 0;
}

/*
//程序2： 
#include <iostream>
using namespace std;
int main()
{	double x;
	int n;
	cin >> x >> n;
	int a=1;
	double b=x,sum=1+x;
	//依次计算x2/2!、…、xi/i!、… 、xn-1/(n-1)!并加到sum中
	for (int i=2; i<n; i++) 
	{	a *= i;  //计算i!
		b *= x;  //计算xi
		sum += b/a;  //计算并把它加到sum中
	}
	cout << "x=" << x << ",n=" << n << ",sum=" << sum << endl;
	return 0;
}

//程序3： 
#include <iostream>
using namespace std;
int main()
{	double x;
	int n;

	cin >> x >> n;
	double item=x,sum=1+x;
	//依次计算x2/2!、…、xi/i!、… 、xn-1/(n-1)!并加到sum中
	for (int i=2; i<n; i++) 
	{	item *= x/i;   // 计算xi/i!
		sum += item;  // 把xi/i!加到sum中
  }
  cout << "x=" << x << ",n=" << n << ",sum=" << sum << endl;
	return 0;
}
*/