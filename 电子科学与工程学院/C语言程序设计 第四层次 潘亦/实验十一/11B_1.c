#include<cstdio>
#include<stdlib.h>
#include<ctype.h>
long stoi(char *s, int *i)
{
	long n = 0;
	while (isdigit(s[*i]))
		n = n * 10 + s[(*i)++]-'0';
	return n;
}
long add(char *s)
{
	int i = 0, *pi=&i;
	char op;
	long a = 0, b = 0, c;
	a = stoi(s, pi);
	op = s[i++];
	b = stoi(s, pi);
	switch (op)
	{
	case '+':return a + b ; 
	case '-':return a - b   ; 
	case '*':return a*b     ; 
	case '/':
		if (b == 0) { printf("div!0"); exit(0); }
		else return a / b;
	default: printf("operator error!"); exit(0);
	}
}
int main(void)
{
	char s[80];
	gets_s(s);
	printf("%s=", s);
	printf("%ld\n", add(s));
	system("pause");
	return 0;
}
