/**
*  
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lubomir Stoykov
* @idnumber 62569
* @task 5
* @compiler VC
*
*/

#include<iostream>
using namespace std;
int main()
{
	int N = 0, number = 0, decimals = 0;
	cin >> N;
	while (N < 2 || N>1000000000) {
		cin.clear();
		cin.ignore(100, '\n');
		cin >> N;
	}
	number = N;
	while (number % 2 == 0) {
		number /= 2;
	}
	while (number % 5 == 0) {
		number /= 5;
	}
	if (number == 1) {
		double rational = 0;
		rational = 1.0 / N;
		int condition = 0;
		while (true) {
			rational*=10;
			decimals++;
			condition = rational * 10;
			if (condition != 0 && condition % 10 == 0)break;
		}
		cout << decimals;
	}
	else {
		cout << "No";
	}
	return 0;
}