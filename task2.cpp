/**
*  
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lubomir Stoykov
* @idnumber 62569
* @task 2
* @compiler VC
*
*/

#include <iostream>
using namespace std;
int main() {
	int n = 0, maxc = -1, maxp = -1;//maxc- nastoqsht maximum, maxp- predishen maximum 
	do {
		cin >> n;
		if (maxc < n) {
			maxp = maxc;
			maxc = n;
		}
	} while (n > 0);
	cout << maxp;
	return 0;
}