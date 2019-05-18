#include<cstdio>
#include<cstdlib>
int main()
{
	
	unsigned int a,b, mode;
	scanf_s("%u",&a);
	b = a; mode = 0x8000;
	printf("%u in binary format is:",a);
	for (int n = 16; n >= 0; n--) 
	{
		printf("%d", b/mode);
		b = b%mode;
		mode = mode / 2;
	}
	system("pause");
	return 0;
}