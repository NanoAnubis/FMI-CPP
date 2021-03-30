/**
*
* Solution to homework assignment 4
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

#include<iostream>
using namespace std;

bool Reach(int p, int q, int p1, int q1, int k, int counter = 0) {
	if (k < counter) {
		counter--;
		return 0;
	}
	if (p == p1 && q == q1) {
		return 1;
	}
	if (Reach(p - 2, q + 1, p1, q1, k, counter + 1) == 1) return 1;
	if (Reach(p - 1, q + 2, p1, q1, k, counter + 1) == 1) return 1;
	if (Reach(p + 1, q + 2, p1, q1, k, counter + 1) == 1) return 1;
	if (Reach(p + 2, q + 1, p1, q1, k, counter + 1) == 1) return 1;
	if (Reach(p + 2, q - 1, p1, q1, k, counter + 1) == 1) return 1;
	if (Reach(p + 1, q - 2, p1, q1, k, counter + 1) == 1) return 1;
	if (Reach(p - 1, q - 2, p1, q1, k, counter + 1) == 1) return 1;
	if (Reach(p - 2, q - 1, p1, q1, k, counter + 1) == 1) return 1;

	return 0;
}



int main() {
	int N = 0, M = 0, p = 0, q = 0, p1 = 0, q1 = 0, k = 0;
	cin >> N >> M >> p >> q >> p1 >> q1 >> k;
	if (N < 3 || N > 200) {
		cout << "-1" << endl;
		return 0;
	}
	if (M < 3 || M > 200) {
		cout << "-1" << endl;
		return 0;
	}
	if (p < 0 || p >= N) {
		cout << "-1" << endl;
		return 0;
	}
	if (q < 0 || q >= M) {
		cout << "-1" << endl;
		return 0;
	}
	if (p1 < 0 || p1 >= N) {
		cout << "-1" << endl;
		return 0;
	}
	if (q1 < 0 || q1 >= M) {
		cout << "-1" << endl;
		return 0;
	}
	if (k < 0 || k > 30) {
		cout << "-1" << endl;
		return 0;
	}
	if (Reach(p, q, p1, q1, k) == 1) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	return 0;
}
