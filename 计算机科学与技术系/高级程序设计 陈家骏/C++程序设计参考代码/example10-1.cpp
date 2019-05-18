#include <cstdio>
//using namespace std;
int main()
{	FILE *fp=fopen("d:\\scores.txt","w"); //以文本方式打开文件用于输出。
	if (fp == NULL) //判文件打开是否成功。
	{	printf("打开文件失败！\n");
		return -1;
	}
	char id[11],name[9];
	int num_of_courses,score;
	printf("请输入学号、姓名、选课数及各门课成绩(以学号为'E'结束)：\n");
	scanf("%10s",id); //读入第一个学生的学号。
	while (id[0] != 'E') //判输入是否结束。
	{	scanf("%8s",name); //读入姓名。
		scanf("%d",&num_of_courses); //读入选课数。
		fprintf(fp,"%s %s %d",id,name,num_of_courses); //把学号、姓名和选课数
																	//输出到文件。
		for (int i=0; i<num_of_courses; i++) //循环读入各门课成绩并输出到文件。
		{	scanf("%d",&score);
			fprintf(fp," %d",score);
		}
		fputc('\n',fp); //输出一个换行符到文件。
		scanf("%10s",id); //读入下一个学生的学号。
	}
	fclose(fp);
  return 0;
}
