#include<iostream>
using namespace std;

int zad4()
{
	int a = 0, b = 0, c = 0, n = 0;
	cin >> a >> b >> c;
	n = a;
	/*
	int mx = a;
	if (a < b)mx = b;
	else if (a < c)mx = c;
	if (b < c)mx = c;
	int mn = a;
	if (a > b)mn = b;
	else if (a > c)mn = c;
	if (b > c)mn = c;
	*/
	int mx = max(max(a, b), c); 
	int mn = min(min(a, b), c);
	if (b != mx && b != mn)
	{
		 n = b;
	}
	else if (c != mx && c != mn)
	{
		 n = c;
	}
	cout << mn << " " << n << " " << mx;
	return 0;
}

int zad5()
{
	int n = 0, e = 0, d = 0, s = 0;
	cin >> n;
	e = n % 10;
	d = n / 10 % 10;
	s = n / 100;
	if (e == d)
	{
		cout << "true";
	}
	else if (e == s)
	{
		cout << "true";
	}
	else if (d == s)
	{
		cout << "true";
	}
	else
		cout << "false";
	return 0;
}

int zad6()
{
	float n=0;
	cin >> n;
	bool isInt = n != (int)n;
	if (isInt == true)
	{
		if (n > 0)
		{
			cout << "Positive rational";
		}
		else cout << "Negative rational";
	}
	else
	{
		if ((int)n % 2 == 0)
		{
			cout << "Even integer";
		}
		else cout << "Odd integer";
	}
	return 0;
}

int zad7()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	if (a + b > c && a + c > b && b + c > a)
	{
		cout << "true";
	}
	else cout << "false";
	return 0;
}

int zad8()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	int ab, ac, ba, ca, bc, cb;
	ab = a * 10 + b;
	ac = a * 10 + c;
	ba = b * 10 + a;
	ca = c * 10 + a;
	bc = b * 10 + c;
	cb = c * 10 + b;
	cout << max(max(max(ab, bc), ac), max(max(ba, cb), ca));
	return 0;
}

int zad9()
{
	int n=0, a=0, b=0;
	cin >> n;
	if (n == 0) 
	{
		cout << "zero";
		return 0;
	}
	if (n == 100)
	{
		cout << "one hundred";
		return 0;
	}
	a = n / 10;
	b = n % 10;
	if (a == 1) 
	{
		switch (b)
		{
		case 0: cout << "ten"; break;
		case 1: cout << "eleven"; break;
		case 2: cout << "twelve"; break;
		case 3: cout << "thirteen"; break;
		case 4: cout << "fourteen"; break;
		case 5: cout << "fifteen"; break;
		case 6: cout << "sixteen"; break;
		case 7: cout << "seventeen"; break;
		case 8: cout << "eighteen"; break;
		case 9: cout << "nineteen"; break;
		}
		return 0;
	}
	switch (a)
	{
	case 2: cout << "twenty"<<" "; break;
	case 3: cout << "thirty" << " "; break;
	case 4: cout << "forty" << " "; break;
	case 5: cout << "fifty" << " "; break;
	case 6: cout << "sixty" << " "; break;
	case 7: cout << "seventy" << " "; break;
	case 8: cout << "eighty" << " "; break;
	case 9: cout << "ninety" << " "; break;
	}
	switch (b)
	{
	case 1: cout << "one"; break;
	case 2: cout << "two"; break;
	case 3: cout << "three"; break;
	case 4: cout << "four"; break;
	case 5: cout << "five"; break;
	case 6: cout << "six"; break;
	case 7: cout << "seven"; break;
	case 8: cout << "eight"; break;
	case 9: cout << "nine"; break;
	}
	return 0;
}

int zad10()
{
	int a = 0, b = 0, aa = 0, bb = 0;
	cin >> a >> b;
	if (a == 11 || a == 12 || a == 13)aa = 10;
	if (b == 11 || b == 12 || b == 13)bb = 10;
	if (a == 1)aa = 11;
	if (b == 1)bb = 11;
	if (aa + bb < 21)cout << "false";
	else cout << "true";
	return 0;
}

int zad11()
{
	int a = 0, b = 0, c = 0, d = 0, x = 0, y = 0, n = 0; //[a,b] [c,d] --> [x,y]
	cin >> a >> b >> c >> d >> n;
	bool b1, b2, b3;
	//Obedinenie
	if (a < c) x = a;
	else x = c;
	if (b < d) y = d;
	else y = b;
	b1 = (n >= x) && (n <= y);
	if (b1==true)
	{
		cout << "true, ";
	}
	else
	{
		cout << "false, ";
	}
	
	//Sechenie
	if (a < c) x = c;
	else x = a;
	if (b < d) y = b;
	else y = d;
	b2 = (n >= x) && (n <= y);
	if (b2==true)
	{
		cout << "true, ";
	}
	else
	{
		cout << "false, ";
	}
	
	//Razlika
	b3 = ((n >= a) && (n <= b)) && ((n < c) || (n > d));
	if (b3==true)
	{
		cout << "true, "; 
	}
	else 
	{ 
		cout << "false, ";
	}
	
	if (b3==true)
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
	return 0;
}

int zad12()
{
	int d=0, m=0, g=0,a=0 ,b=0 ,c=0 ;
	cin >> d >> m >> g;
	a = d + 1;
	b = m;
	if (a == 31 && (m == 4 || m == 6 || m == 9 || m == 11))
	{
		b = m + 1; a = 1;
	}
	if (a == 32 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
	{
		b = m + 1; a = 1;
	}
	if (a == 29 && m == 2) 
	{ 
		b = m + 1; a = 1; 
	}
	if (a == 32 && m == 12 )
	{
		b =	1; a = 1; g++ ;
	}
	cout << a << " " << b << " " << g;
	return 0;
}