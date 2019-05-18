#include <cstring>
#include <cstdlib>
#include <iostream>
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
		int length() const {	return strlen(str); }
		char &operator[](int i)
		{	if (i < 0 || i >= strlen(str)) 
			{	cerr << "超出字符串范围!\n";
				exit(-1);
			}
			return str[i];	
		}
		char operator[](int i) const //用于常量对象。
		{	if (i < 0 || i >= strlen(str)) 
			{	cerr << "超出字符串范围!\n";
				exit(-1);
			}
			return str[i];	
		}
		//类型转换操作符（char *）重载函数
		operator const char *() const { return str; }  
		String &operator =(const char *p)  //赋值操作符=重载函数
		{	char *p1=new char[strlen(p)+1];
			strcpy(p1,p);
			delete []str;
			str = p1;
			return *this;
		}
		String &operator =(const String &s)  //赋值操作符=重载函数
		{	if (&s != this)
				*this = s.str;
			return *this;
		}
		String &operator +=(const char *p)  //复合赋值操作符+=重载函数
		{	char *p1=new char[strlen(str)+strlen(p)+1];
			strcpy(p1,str);
			strcat(p1,p);
			delete []str;
			str = p1;
			return *this;
		}
		String &operator +=(const String &s)  //复合赋值操作符+=重载函数
		{	*this += s.str;
			return *this;
		}
	friend bool operator ==(const String &s1, const String &s2);
	//friend bool operator ==(const String &s, const char *p);
	//friend bool operator ==(const char *p, const String &s);
};
bool operator ==(const String &s1,const String &s2) 
{ return strcmp(s1.str,s2.str)==0;
}
/*bool operator ==(const String &s, const char *p) 
{ return strcmp(s.str,p)==0; 
}
bool operator ==(const char *p, const String &s) 
{ return strcmp(p,s.str)==0; 
}*/
String operator +(const String &s1, const String &s2)
{	String temp(s1);
	temp += s2;
	return temp;
}
String operator +(const String &s, const char *p)
{	String temp(s);
	temp += p;
	return temp;
}
String operator +(const char *p, const String &s)
{	String temp(p);
	temp += s;
	return temp;
}
int main()
{	String s1;
	String s2("abcdefg");
	String s3;
	s1 = "xyz";
	s2 += s1;
	s3 = s1+s2;
	for (int i=0; i<s2.length(); i++)
	{	if (s2[i] >= 'a' && s2[i] <= 'z')
			s2[i] = s2[i]-'a'+'A';
	}
	if (s2 == String("ABCDEFGXYZ")) cout << "OK\n";
  cout << (const char *)s1 << endl
			 << (const char *)s2 << endl
			 << (const char *)s3 << endl;
	return 0;
}
