/**
*
* Solution to homework assignment 2
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
#include<vector>
using namespace std;
int main()
{
	bool CheckTriangle(int, int, int, int);
	int SizeV = 0;
	bool isTrue = 1;
	vector<int>seq;

	do {
		cin >> SizeV;
	} while (SizeV < 3 || SizeV>100);

	for (int i = 0; i < SizeV; i++) {
		int number;
		cin >> number;
		seq.push_back(number);
	}
	int N = SizeV;

	for (int i = 0; i <= N; i++, N--) {
		if (SizeV % 2 == 0 && i == N) break;
		else if (SizeV % 2 != 0 && i == N - 1) break;
		int a = seq[i], b = seq[i + 1], c = seq[N - 2], d = seq[N - 1];
		if (CheckTriangle(a, b, c, d) == false) {
			isTrue = 0;
			break;
		}
	}
	cout << isTrue << endl;
	return 0;
}

int SpecAbs(int a = 0, int b = 0) {
	if (a - b >= 0) {
		return a - b;
	}
	else {
		return b - a;
	}
}

bool CheckTriangle(int a, int b, int c, int d) {
	int SpecAbs(int, int);
	int x = SpecAbs(a, b);
	int y = SpecAbs(c, d);
	if (x == y) return true;
	else return false;
}