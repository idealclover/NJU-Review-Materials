#include <iostream>
using namespace std;
enum Month { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
void display_month(Month m)
{	switch (m)
	{	case JAN:	cout << "January"; break;
		case FEB:	cout << "February"; break;
		case MAR:	cout << "March"; break;
		case APR:	cout << "April"; break;
		case MAY:	cout << "May"; break;
		case JUN:	cout << "June"; break;
		case JUL:		cout << "July"; break;
		case AUG:	cout << "August"; break;
		case SEP:		cout << "September"; break;
		case OCT:	cout << "October"; break;
		case NOV:	cout << "November"; break;
		case DEC:	cout << "December"; break;
	}
	cout << endl;
}
int main()
{	const int NUM_OF_MONTH_PER_YEAR=12;
	double humidities[NUM_OF_MONTH_PER_YEAR];
	Month i,max,min;
	//获得湿度数据
	cout << "请输入某年12个月的湿度数据：";
	for (i=JAN; i<=DEC; i = Month(i+1))
		cin >> humidities[i];

	//计算湿度最大和最小的月份。
	max = min = JAN;
	for (i=FEB; i<=DEC; i = Month(i+1))
		if (humidities[i] > humidities[max])
			max = i;
		else if (humidities[i] < humidities[min])
			min = i;

	//输出结果
	cout << "最大湿度的月份是：";
	display_month(max);
	cout << "最小湿度的月份是：";
	display_month(min);
	return 0;
}
