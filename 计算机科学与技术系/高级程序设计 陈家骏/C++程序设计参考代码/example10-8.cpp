#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
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
{	char id[11];
	char name[9];
	Sex sex;
	Date birth_date;
	char birth_place[40];
	Major major;
};
class StudentsFile
{	public:
		StudentsFile(const char filename[])
		{	io_file.open(filename,ios::in|ios::out|ios::binary);
		}
		~StudentsFile()
		{	io_file.close();
		}
		bool is_open() const { return io_file.is_open(); }
		int find(char id[],Student &st) //查找学号为id的学生。
		{	int index=0;
			io_file.seekg(0);
			io_file.read((char *)&st,sizeof(st)); //读入第一个学生的数据。
			while (!io_file.eof()) //循环查找学号为id的学生。
			{	if (strcmp(st.id,id) == 0) 
					return index; //返回找到的学生在文件中的位置。
				index++;
				io_file.read((char *)&st,sizeof(st)); //读入下一个学生的数据。
			}
			return -1; //没找到返回-1。
		}
		bool put_at(int index,Student &st) //更新文件中指定位置上的学生信息。
		{	io_file.seekp(index*sizeof(st)); //文件位置指针定位。
			if (io_file.fail()) return false;
			io_file.write((char *)&st,sizeof(st)); //写入数据。
			return !io_file.fail();
		}
	private:
		fstream io_file; //用于文件输入/输出的成员对象
};
int main()
{	StudentsFile students_file("d:\\students.dat");
	if (!students_file.is_open())
	{	cerr << "文件打开失败！";
		return -1;
	}
	char id[11];
	int major;
	cout << "请输入要查找的学生的学号：";
	cin >> setw(11) >> id;
	cout << "请输入要改成的专业\n"
			 << "(0:MATHEMATICS,1:PHYSICS,2:CHEMISTRY,3:COMPUTER,\n"
			 << "4:GEOGRAPHY,5:ASTRONOMY,6:ENGLISH,7:CHINESE,8:CHINESE)：";	
	cin >> major;
	Student st;
	int i=students_file.find(id,st);
	if (i == -1)
	{	cout << "\n没找到学号为" << id << "的学生。\n";
		return -1; 
	}
	else
	{	st.major = (Major)major; //修改找到的学生的专业。
		students_file.put_at(i,st);
		cout << "\n学号为" << id << "的学生信息已更新。\n";
	}
  return 0;
}
