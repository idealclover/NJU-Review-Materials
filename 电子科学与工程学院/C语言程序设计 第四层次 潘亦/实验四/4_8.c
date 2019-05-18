#include<cstdio>
#include<cstdlib>
int main()
{
	int m, n,day;
	scanf_s("%d.%d", &m, &n);
	if (m == 1)
	{
		if (n == 2) day = 5;
		else if (n == 3) day = 6;
		else
		day = (n + 4 - 1) % 7;
	}
	else if (m == 2) day = (n + 31 + 4 - 1) % 7;
	else if (m == 3) day = (n + 31 + 28 + 4 - 1) % 7;
	else if (m == 4) day = (n + 31 * 2 + 28 + 4 - 1) % 7;
	else if (m == 5) day = (n + 31 * 2 + 28 + 30 + 4 - 1) % 7;
	else if (m == 6) day = (n + 31 * 3 + 28 + 30 + 4 - 1) % 7;
	else if (m == 7) day = (n + 31 * 3 + 28 + 30 * 2 + 4 - 1) % 7;
	else if (m == 8) day = (n + 31 * 4 + 28 + 30 * 2 + +4 - 1) % 7;
	else if (m == 9) day = (n + 31 * 5 + 28 + 30 * 2 + 4 - 1) % 7;
	else if (m == 10) day = (n + 31 * 5 + 28 + 30 * 3 + 4 - 1) % 7;
	else if (m == 11) day = (n + 31 * 6+ 28 + 30 * 3 + 4 - 1) % 7;
	else if (m == 12) day = (n + 31 * 31 + 28 + 30 * 3+ 4 - 1) % 7;
	else printf("type error");
	switch (day)
	{
	case 0: printf("Sunday"); break;
	case 1: printf("Monday"); break;
	case 2: printf("Tuesday"); break;
	case 3: printf("Wednesday"); break;
	case 4: printf("Thursday"); break;
	case 5: printf("Friday"); break;
	case 6: printf("Saturday"); break;
	default:printf("type error");
	}
	system("pause");
	return 0;
}