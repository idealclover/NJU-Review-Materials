#include <iostream>
using namespace std;
int main()
{	int year,month,days;
	cout << "请输入年：";
	cin >> year;
	cout << "请输入月：";
	cin >> month;
	switch (month)
	{	case 1:case 3:case 5:case 7:case 8: case 10:case 12:
			days = 31;
			break;
		case 4:case 6:case 9:case 11:
			days = 30;
			break;
		case 2:
			if (year%400 == 0 || year%4 == 0 && year%100 != 0)
				days = 29;
			else
				days = 28;
	}
	cout << year << "年" << month << "月的天数是：" << days << endl;
	return 0;
}
