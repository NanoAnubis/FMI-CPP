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
	do {
		cin >> N;
	} while (N < 3 || N > 200);
	do {
		cin >> M;
	} while (M < 3 || M > 200);
	do {
		cin >> p;
	} while (p < 0 || p >= N);
	do {
		cin >> q;
	} while (q < 0 || q >= M);
	do {
		cin >> p1;
	} while (p1 < 0 || p1 >= N);
	do {
		cin >> q1;
	} while (q1 < 0 || q1 >= M);
	do {
		cin >> k;
	} while (k > 30 || k < 0);

	if (Reach(p, q, p1, q1, k) == 1) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	return 0;
}
