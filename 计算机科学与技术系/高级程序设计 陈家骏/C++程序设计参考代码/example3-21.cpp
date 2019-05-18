#include <iostream>
using namespace std;
int main()
{	int n;
	cin >> n;
	int i=1,f=1;
loop: 
	f *= i;
	i++;
	if (i <= n) goto loop;
	cout << "factorial of " << n << "=" << f << endl;
	return 0;
}
