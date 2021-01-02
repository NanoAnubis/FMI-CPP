#include<iostream>
using namespace std;

bool rec(int p, int q, int p1, int q1, int k, int counter = 0) {
	if (k < counter) {
		counter--;
		return 0;
	}
	if (p == p1 && q == q1) {
		return 1;
	}
	if (rec(p - 2, q + 1, p1, q1, k, counter + 1) == 1) return 1;
	if (rec(p - 1, q + 2, p1, q1, k, counter + 1) == 1) return 1;
	if (rec(p + 1, q + 2, p1, q1, k, counter + 1) == 1) return 1;
	if (rec(p + 2, q + 1, p1, q1, k, counter + 1) == 1) return 1;
	if (rec(p + 2, q - 1, p1, q1, k, counter + 1) == 1) return 1;
	if (rec(p + 1, q - 2, p1, q1, k, counter + 1) == 1) return 1;
	if (rec(p - 1, q - 2, p1, q1, k, counter + 1) == 1) return 1;
	if (rec(p - 2, q - 1, p1, q1, k, counter + 1) == 1) return 1;
	//return 0;
}



int main() {
	int N = 0, M = 0, p = 0, q = 0, p1 = 0, q1 = 0, k = 0;
	cin >> N >> M >> p >> q >> p1 >> q1 >> k;
	if (rec(p, q, p1, q1, k) == 1) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	return 0;
}
