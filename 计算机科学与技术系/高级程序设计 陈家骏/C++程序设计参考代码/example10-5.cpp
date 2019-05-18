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
{	FILE *fp=fopen("d:\\students.dat","r+b"); 
												//以二进制方式打开文件用于输入/输出。
	if (fp == NULL) //判文件打开是否成功。
	{	printf("打开文件失败！\n");
		return -1;
	}
	Student st;
	if (fseek(fp,sizeof(st),SEEK_SET) == 0) //文件位置指针指向第二个学生数据。
	{	fread(&st,sizeof(st),1,fp); //读入第二个学生数据，
												 //文件位置指针移至下一个学生数据。
		st.major = COMPUTER; //修改第二个学生数据的专业。
		fseek(fp,-sizeof(st),SEEK_CUR); //文件位置指针指回第二个学生数据。
		fwrite(&st,sizeof(st),1,fp); //修改后的第二个学生数据写回文件。
	}
	fclose(fp); //关闭文件。
  return 0;
}
