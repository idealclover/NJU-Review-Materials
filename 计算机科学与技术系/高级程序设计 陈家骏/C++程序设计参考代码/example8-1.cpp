#include <iostream>
#include <cstring>
using namespace std;

class String
{		char *str;
	public:
		String()
		{	str = NULL;
		}
		String(const char *p)
		{	str = new char[strlen(p)+1];
			strcpy(str,p);
		}
		String(const String &s)  //拷贝构造函数
		{	str = new char[strlen(s.str)+1];
			strcpy(str,s.str);
		}
		~String()
		{	delete []str;
			str = NULL;
		}
		operator const char *() const { return str; }  
	friend bool operator ==(const String &s1, const String &s2);
    //......
};
bool operator ==(const String &s1,const String &s2) 
{ return strcmp(s1.str,s2.str)==0;
}

class Employee //普通职员类
{		String name; //String为例 7 7中定义的字符串类。
		int salary;
	public:
		Employee(const char *s, int n=0):name(s) 
		{	salary = n; 
		}
		void set_salary(int n) { salary = n; }
		int get_salary() const { return salary; }
		String get_name() const { return name; }
};
const int MAX_NUM_OF_EMPS=20;
class Manager: public Employee //部门经理类
{		Employee *group[MAX_NUM_OF_EMPS];
		int num_of_emps;
	public:
		Manager(const char *s, int n=0): Employee(s,n) 
		{ num_of_emps = 0; 
		}
		Employee *add_employee(Employee *e) 
		{ if (num_of_emps >= MAX_NUM_OF_EMPS) return NULL;
			group[num_of_emps] = e; 
			num_of_emps++;
			return e;
		}
		Employee *remove_employee(Employee *e) 
		{	int i;
			for (i=0; i<num_of_emps; i++)
				if (e->get_name() == group[i]->get_name())
					break;
			if (i < num_of_emps)
			{	for (int j=i+1; j<num_of_emps; j++)
					group[j-1] = group[j];
				num_of_emps--;
				return e;
			}
			else 
				return NULL;
		}
		Employee *get_employee(int index) 
    { if (index >= num_of_emps) 
        return NULL;
      else
        return group[index];
    }
};
int main()
{
  Employee e1("Jack",1000),e2("Jane",2000);
  Manager m("Mark",4000);
  m.add_employee(&e1);
  m.add_employee(&e2);
  cout << (const char *)m.get_name() 
       << "is a manager.\nHis salary is "
       << m.get_salary() 
       << ".\nThe persons managed by him are\n";
  int i=0;
  Employee *p=m.get_employee(i++);
  while (p != NULL)
  { cout << (const char *)p->get_name() << endl;
    p = m.get_employee(i++);
  }
  return 0;
}