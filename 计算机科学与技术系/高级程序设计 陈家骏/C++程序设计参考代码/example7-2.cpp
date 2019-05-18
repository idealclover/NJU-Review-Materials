#include <iostream>
#include <cstdlib>
using namespace std;
class Complex
{		double real, imag;
	public:
		Complex() { real = 0; imag = 0; }
		Complex(double r, double i) { real = r; imag = i; }
		bool operator ==(const Complex& x) const
		{	return (real == x.real) && (imag == x.imag);
		}
		bool operator !=(const Complex& x) const
		{	return !(*this == x);
		}
};

int main()
{ Complex a(1.0,2.0),b(3.0,4.0);
  if (a != b)
    cout << "ok\n";
  else 
    cout << "error\n";
  return 0;
}