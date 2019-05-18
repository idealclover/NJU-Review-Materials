#include<stdio.h> 
#include<cstdlib>
int main()
{
	char A, B;
	printf("请输入两个学生的姓名:");
	scanf_s("%c%c", &A,1, &B,1);
	printf("请输入学生%c的三门成绩:", A);
	double M_1, M_2, P_1, P_2, C_1, C_2;
	scanf_s("%lf%lf%lf", &M_1, &P_1, &C_1);
	printf("请输入学生%c的三门成绩:", B);
	scanf_s("%lf%lf%lf", &M_2, &P_2, &C_2);
	double SUM1, SUM2, AVERAGE1, AVERAGE2;
	SUM1 = M_1 + C_1 + P_1;
	AVERAGE1 = SUM1 / 3;
	SUM2 = M_2 + C_2 + P_2;
	AVERAGE2 = SUM2 / 3;
	for (int i = 1; i <= 85; i++) printf("*");
	printf("\n");
	for (int i = 1; i <= 85; i++) printf(" ");
	printf("\n");
	printf("NAME"); for (int i = 1; i <= 10; i++) printf(" ");
	printf("MATH"); for (int i = 1; i <= 10; i++) printf(" ");
	printf("PHYSICS"); for (int i = 1; i <= 10; i++) printf(" ");
	printf("CHEMSTRY"); for (int i = 1; i <= 10; i++) printf(" ");
	printf("SUM"); for (int i = 1; i <= 10; i++) printf(" ");
	printf("AVERAGE"); printf("\n");
	for (int i = 1; i <= 3; i++) printf(" ");
	printf("%c", A); for (int i = 1; i <= 10; i++) printf(" ");
	printf("%.1f", M_1); for (int i = 1; i <= 13; i++) printf(" ");
	printf("%.1f", P_1); for (int i = 1; i <= 14; i++) printf(" ");
	printf("%.1f", C_1); for (int i = 1; i <= 8; i++) printf(" ");
	printf("%.1f", SUM1); for (int i = 1; i <= 13; i++) printf(" ");
	printf("%.1f", AVERAGE1); printf("\n");
	for (int i = 1; i <= 3; i++) printf(" ");
	printf("%c", B); for (int i = 1; i <= 10; i++) printf(" ");
	printf("%.1f", M_2); for (int i = 1; i <= 13; i++) printf(" ");
	printf("%.1f", P_2); for (int i = 1; i <= 14; i++) printf(" ");
	printf("%.1f", C_2); for (int i = 1; i <= 8; i++) printf(" ");
	printf("%.1f", SUM2); for (int i = 1; i <= 13; i++) printf(" ");
	printf("%.1f", AVERAGE2); printf("\n");
	for (int i = 1; i <= 85; i++) printf(" ");
	printf("\n");
	for (int i = 1; i <= 85; i++) printf("*");
	printf("\n");
	system("pause");
	return 0;
}
