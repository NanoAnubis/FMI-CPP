/**
*  
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lubomir Stoykov
* @idnumber 62569
* @task 1
* @compiler VC
*
*/

#include<iostream>
using namespace std;
int main()
{
	int n = 0, x = 0, m = 0, total = 0;
	cin >> n >> x >> m;
	for (int i=1; i <= n; i++) {
		if (i % 2 != 0) {
			total += m;
		}
		else {
			total = total + ((i/2) * 30) - 5;
		}
	}
	if (total > x) {
		cout << "yes\n" << total - x;
	}
	else {
		cout << "no\n" << x - total;
	}
	return 0;
}