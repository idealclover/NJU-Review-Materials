#include<cstdio>
#include<cstdlib>
int main()
{
	enum color{red,green,blue};
	enum color R, G, B;
	R = (enum color)0;
	G = (enum color)1;
	B = (enum color)2;
	void *r, *g, *b;
	r = &R;
	g = &G;
	b = &b;
	printf("%d,%d,%d", r, g, b);
	system("pause");
	return 0;
}