#include <iostream>
using namespace std;
int main()
{ 	int day;
	cin >> day;
	if (day == 0)
		cout << "Sunday";
	else if (day == 1)
		cout << "Monday";
	else if (day == 2)
		cout << "Tuesday";
	else if (day == 3)
		cout << "Wednesday"; 
	else if (day == 4)
		cout << "Thursday";
	else if (day == 5)
		cout << "Friday";
	else if (day == 6)
		cout << "Saturday";
	else
		cout << "Input error";
	cout << endl;
	return 0;
}
