#include <iostream>
using namespace std;
enum Sex { MALE, FEMALE };
struct Date
{	int year;
	int month;
	int day;
};
enum Major { MATHEMATICS, PHYSICS, CHEMISTRY, COMPUTER, GEOGRAPHY,
						  ASTRONOMY, ENGLISH, CHINESE, PHILOSOPHY};
struct Student
{	int no;
	char name[20];
	Sex sex;
	Date birth_date;
	char birth_place[40];
	Major major;
};
const int MAX_NUM_OF_STUDENTS =1000;
Student students[MAX_NUM_OF_STUDENTS];
extern void display_student_info(Student s); //前面5中定义的函数。
extern int find_substr(char sub_str[], char str[]);  
												//例 5 6中定义的子串查找函数。
extern void bubble_sort(Student s[],int num);  
												//在函数main的后面定义的排序函数。
extern void display_student_info(Student s);

int main()
{	int num_of_students,count,i;
	//从键盘或磁盘文件获得所有学生的数据，学生总数存储在num_of_students中。
	//......
	//统计计算机专业男生的人数。
	count = 0;
	for (i=0; i<num_of_students; i++) 
		if (students[i].major == COMPUTER && students[i].sex == MALE)
			count++; 
	cout << "计算机专业男生的人数是：" << count << endl;
	
	//统计出生地为"南京"的学生人数。
	count = 0;
	for (i=0; i<num_of_students; i++) 
		if (find_substr("南京",students[i].birth_place) != -1)
			count++; 
	cout << "出生地为\"南京\"的学生人数是：" << count << endl;

	//按学号由小到大对students的元素进行排序
	bubble_sort(students,num_of_students);

	//按学号由小到大输出所有学生的信息
	for (i=0; i<num_of_students; i++) 
		display_student_info(students[i]);

	return 0;
}
void bubble_sort(Student s[],int num)  //冒泡排序算法
{	bool exchange;
	while (num > 1)
	{	exchange = false;
		for (int i=0; i<num-1; i++)
		{	if (s[i].no > s[i+1].no)
			{	//交换s[i]和s[i+1]的值
				Student temp=s[i];
				s[i] = s[i+1];
				s[i+1] = temp;
				exchange = true;
			}
		}
		if (!exchange) break;
		num--;
	}
}

void display_student_info(Student s)
{	cout << "学号：" << s.no << endl;
	cout << "姓名：" << s.name << endl;
	cout << "性别：" << (s.sex==MALE?"男":"女") << endl;
	cout << "出生日期：" << s.birth_date.year << ',' 
									 << s.birth_date.month << ',' 
									 << s.birth_date.day << endl;
	cout << "出生地：" << s.birth_place << endl;
	cout << "专业：";
	switch (s.major)
	{	case MATHEMATICS: 	cout << "Mathematics"; break;
		case PHYSICS: 		cout << "Physics"; break;
		case CHEMISTRY: 	cout << "Chemistry "; break;
		case COMPUTER: 		cout << "Computer"; break;
		case GEOGRAPHY: 	cout << "Geography"; break;
		case ASTRONOMY: 	cout << "Astronomy"; break;
		case ENGLISH: 		cout << "English"; break;
		case CHINESE: 		cout << "Chinese"; break;
		case PHILOSOPHY: 	cout << " Philosophy"; break;
	}
	cout << endl;
}

int find_substr(char sub_str[], char str[])
{	int len=strlen(str),
			sub_len=strlen(sub_str);
	for (int i=0; i<=len-sub_len; i++)
	{	int j=0;
		while (j < sub_len && sub_str[j] == str[i+j]) j++;
		if (j == sub_len) return i;
	}
	return -1;
}
