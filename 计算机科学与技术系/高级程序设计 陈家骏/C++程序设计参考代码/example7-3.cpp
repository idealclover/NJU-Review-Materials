#include <iostream>
using namespace std;
class Complex
{		double real, imag;
	public:
		Complex() { real = 0; imag = 0; }
		Complex(double r, double i) { real = r; imag = i; }
		void display() const //¸´ÊıÏÔÊ¾
		{ cout << real << '+' << imag << 'i';
		} 
	friend Complex operator + (const Complex& c1, const Complex& c2);
	friend Complex operator + (const Complex& c, double d);
	friend Complex operator + (double d, const Complex& c);
};
Complex operator + (const Complex& c1, const Complex& c2)
{	return Complex(c1.real+c2.real,c1.imag+c2.imag);
}
Complex operator + (const Complex& c, double d)
{	return Complex(c.real+d,c.imag);
}
Complex operator + (double d, const Complex& c)
{	return Complex(d+c.real,c.imag);
}

int main()
{ Complex a(1,2),b(3,4),c1,c2,c3;
  c1 = a + b;
  c2 = b + 21.5;
  c3 = 10.2 + a;

  a.display();
  cout << " + ";
  b.display();
  cout << " = ";
  c1.display();
  cout << endl;

  b.display();
  cout << " + 21.5 = ";
  c2.display();
  cout << endl;

  cout << " 10.2 + ";
  a.display();
  cout << " = ";
  c3.display();
  cout << endl;

  return 0;
}