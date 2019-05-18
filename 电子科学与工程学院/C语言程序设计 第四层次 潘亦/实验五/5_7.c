#include<cstdlib>
#include<cstdio>
int main()
{
	for (int P = 1; P <= 9; P++)
		for (int E = 0; E <= 9; E++)
			for (int A = 0; A <= 9; A++)
				for (int R = 0; R <= 9; R++)
					if (1000 * P + 100 * E + 10 * A + R - 100 * A - 10 * R - A == 100 * P + E * 10 + A)
						printf("(P=%d,E=%d,A=%d,R=%d)", P, E, A, R);
	system("pause");
	return 0;
}