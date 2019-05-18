#include <iostream>
using namespace std;
int main()
{	Day d;
	int i;
	cin >> i;
	switch (i)
	{	case 0: d = SUN; 	break;
		case 1: d = MON; 	break;
		case 2: d = TUE; 	break;
		case 3: d = WED; 	break;
		case 4: d = THU; 	break;
		case 5: d = FRI; 	break;
		case 6: d = SAT; 	break;
		default: cout << "Input Error!" << endl; exit(-1);
	}
	//......
	switch (d)
	{	case SUN: cout << "SUN" << endl; 	break;
		case MON:	cout << "MON" << endl; 	break;
		case TUE:	cout << "TUE" << endl; 	break;
		case WED:	cout << "WED" << endl; 	break;
		case THU:	cout << "THU" << endl; 	break;
		case FRI:	cout << "FRI" << endl; 	break;
		case SAT:	cout << "SAT" << endl; 	break;
	}
	return 0;
}
