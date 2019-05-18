#include <cstdio>
//using namespace std;
enum Sex { MALE, FEMALE };
struct Date
{	int year;
	int month;
	int day;
};
enum Major { MATHEMATICS, PHYSICS, CHEMISTRY, COMPUTER, GEOGRAPHY,
							ASTRONOMY, ENGLISH, CHINESE, PHILOSOPHY};
struct Student
{	char id[11];
	char name[9];
	Sex sex;
	Date birth_date;
	char birth_place[40];
	Major major;
};
int main()
{	FILE *fp=fopen("d:\\students.dat","wb"); //以二进制方式打开文件用于输出。
	if (fp == NULL) //判文件打开是否成功。
	{	printf("打开文件失败！\n");
		return -1;
	}
	Student st;
	printf("请输入学号、姓名、性别、出生日期、出生地和专业(以学号为'E'结束)：\n");
	scanf("%10s",st.id); //读入第一个学生的学号。
	while (st.id[0] != 'E')
	{	//...... //读入姓名、性别、出生日期、出生地和专业至变量st中。
		fwrite(&st,sizeof(st),1,fp); //以二进制格式输出变量st的值到文件。
		scanf("%10s",st.id); //读入下一个学生的学号。
	}
	fclose(fp); //关闭文件。
  return 0;
}
