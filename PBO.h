#include<iostream>
using namespace std;

int zad1()
{
	int n;
	cout << "enter n" << endl;
	cin >> n;
	bool uneven = n & 1;
	if (uneven == false)
		cout << "n is even" << endl;
	else
		cout << "n is uneven" << endl;
	return 0;
}

int zad2()
{
	int m, n;
	cout << "enter n and m" << endl;
	cin >> n >> m;
	bool isOne = (n >> m - 1) & 1;
	if (isOne == true)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}

int zad3()
{
	int m, n;
	cout << "enter n and m" << endl;
	cin >> n >> m;
	cout << (n << m) << endl;
	return 0;
}

int zad4()
{
	int n;
	cin >> n;
	cout << (~n);
	return 0;
}

int zad5()
{
	int key0, value, crypt;
	const int key = 51223;
	cout << "enter value: ";
	cin >> value;
	crypt = (value ^ key);
	cout << "your crypt is: " << crypt << endl;
	cout << "enter key to decrypt: ";
	cin >> key0;
	cout << "your value was: " << (key0 ^ crypt);
	return 0;
}
