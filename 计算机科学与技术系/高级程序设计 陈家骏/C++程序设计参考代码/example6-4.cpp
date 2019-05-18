#include <iostream>
#include <cstdlib>
using namespace std;

class A
{		static int obj_count;
		//......
	public:
		A() { obj_count++; }
		~A() { obj_count--; }
		static int get_num_of_objects() { return obj_count; }
		//......
};	
int A::obj_count=0;
int main()
{ A a1,a2,a3;
  cout << A::get_num_of_objects() << endl;
  return 0;
}