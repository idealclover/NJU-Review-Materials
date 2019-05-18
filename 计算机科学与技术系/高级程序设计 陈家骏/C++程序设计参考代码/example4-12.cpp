int gcd(int x, int y)
{	int d;
	d = (x <= y)?x:y;
	while (d > 1)
	{	if (x%d == 0 && y%d == 0) break;
		d--;
	} 
	return 	d;
}

//µİ¹éÇó½â
/*
int gcd(int x, int y)
{	return (y==0)?x:gcd(y,x%y);
}
*/