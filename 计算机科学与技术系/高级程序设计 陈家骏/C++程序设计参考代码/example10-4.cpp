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
{	FILE *fp=fopen("d:\\students.dat","rb"); //以二进制方式打开文件用于输入。
	if (fp == NULL) //判文件打开是否成功。
	{	printf("打开文件失败！\n");
		return -1;
	}
	Student st;
	int count=0;
	fread(&st,sizeof(st),1,fp); //读入第一个学生的信息。
	while (!feof(fp))
	{	if (st.sex == MALE) count++;
		fread(&st,sizeof(st),1,fp); //读入下一个学生的信息。
	}
	printf("男生的人数是：%d\n",count);
	fclose(fp);
  return 0;
}
