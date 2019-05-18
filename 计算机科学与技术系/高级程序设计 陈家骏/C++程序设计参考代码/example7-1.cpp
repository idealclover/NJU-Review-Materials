#include <iostream>
using namespace std;
class Complex
{		double real, imag;
	public:
		Complex(double r=0.0, double i=0.0) { real = r; imag = i; }
		void display() const //复数显示
		{ cout << real << '+' << imag << 'i';
		} 

		Complex add(const Complex& x) const
		{	Complex temp;
			temp.real = real+x.real;
			temp.imag = imag+x.imag;
			return temp;
		}
};
int main()
{ Complex a(1.0,2.0),b(3.0,4.0),c;
  c = a.add(b);
  a.display();
  cout << " + ";
  b.display();
  cout << " = ";
  c.display();
  cout << endl;
  return 0;
}

/*
#include <iostream>
using namespace std;
class Complex
{		double real, imag;
	public:
		Complex(double r=0.0, double i=0.0) { real = r; imag = i; }
		void display() const //复数显示
		{ cout << real << '+' << imag << 'i';
		} 

   friend Complex add(const Complex& x1,const Complex& x2);
};
Complex add(const Complex& x1,const Complex& x2)
{	Complex temp;
	temp.real = x1.real+x2.real;
	temp.imag = x1.imag+x2.imag;
	return temp;
}
int main()
{ Complex a(1.0,2.0),b(3.0,4.0),c;
  c = add(a,b);
  a.display();
  cout << " + ";
  b.display();
  cout << " = ";
  c.display();
  cout << endl;
  return 0;
}
*/