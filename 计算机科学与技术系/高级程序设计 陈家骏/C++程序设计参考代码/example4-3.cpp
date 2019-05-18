void display_message(int score)
{	if ( score >= 90 )				
		cout << "优" << endl;
	else if (score >= 80)
		cout << "良" << endl;
	else if (score >= 70)
		cout << "中" << endl;
	else if (score >= 60)
		cout << "及格" << endl;
	else
		cout << "不及格" << endl;
	return; 
}
