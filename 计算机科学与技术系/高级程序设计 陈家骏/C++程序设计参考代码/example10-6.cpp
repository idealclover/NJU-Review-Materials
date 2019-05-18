#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_NUM_OF_COURSES=30;
const int MAX_ID_LEN=10;
const int MAX_NAME_LEN=8;
class StudentScores
{	public:
		StudentScores() { initialized = false; }
		bool data_is_ok() const { return initialized; }
	private:	
		int scores[MAX_NUM_OF_COURSES],num_of_courses;
		char id[MAX_ID_LEN+1],name[MAX_NAME_LEN+1];
		bool initialized; //表示学生成绩数据是否被成功读入。
	friend istream &operator >>(istream &in, StudentScores &x);
	friend ostream &operator <<(ostream &out, StudentScores &x);
};
istream &operator >>(istream &in, StudentScores &x)
{	if (&in == &cin) //从键盘输入时需要给出提示。
		cout << "请输入学号、姓名、选课数及各门课成绩（以学号为'E'结束）：\n";
	in >> setw(11) >> x.id; //读入学号。
	if (in.eof() || x.id[0] == 'E') //判结束标记。
	{	x.initialized = false;
		return in;
	}
	in >> setw(9) >> x.name; //读入姓名。
	in >> x.num_of_courses; //读入选课数。
	if (x.num_of_courses > MAX_NUM_OF_COURSES)
	{	x.initialized = false;
		return in;
	}
	for (int i=0; i<x.num_of_courses; i++) //循环读入各门课成绩。
		in >> x.scores[i];
	x.initialized = true;
	return in;
}
ostream &operator <<(ostream &out, StudentScores &x)
{	out << x.id << ' ' //输出学号。
			<< x.name << ' ' //输出姓名。
			<< x.num_of_courses; //输出选课数。
	for (int i=0; i<x.num_of_courses; i++) //循环输出各门课成绩。
		out << ' ' << x.scores[i];
	return out;
}
int main()
{	ofstream out_file("d:\\scores.txt",ios::out); //以文本方式打开文件用于输出。
	if (!out_file) //判文件打开是否成功。
	{	cerr << "打开文件失败！\n";
		return -1;
	}
	StudentScores st;
	cin >> st; //从标准输入设备读入第一个学生的选课信息。
	while (st.data_is_ok()) //判输入是否结束。
	{	out_file << st << endl; //往文件中写入学生选课信息。
		cin >> st; //从标准输入设备读入下一个学生的选课信息。
	}
	out_file.close(); //关闭文件。
	return 0;
}
