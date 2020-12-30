// Lubomir Stoykov 62569
#include<iostream>
#include<vector>
using namespace std;

int Size(int num) {
	int size = 1;
	while (num / 10 != 0) {
		num /= 10;
		size++;
	}
	return size;
}

int main() {
	int number = 0, size = 0;
	vector<int> Cifri;
	cin >> number;
	if (number < 0) {
		number *= -1;
	}
	size = Size(number);
	int delitel = 1;
	for (int i = 1; i <= size; i++){
		delitel *= 10;
	}
	while (number / 10 != 0) {
		Cifri.push_back(number / delitel);
		number %= delitel;
		delitel /= 10;
	}
	Cifri.push_back(number);
	bool check = 0;
	for (int i = 1; i < Cifri.size(); i++) {
		for (int p = i + 1; p < Cifri.size(); p++) {
			if (Cifri[i] == Cifri[p]) {
				check = 1;
				break;
			}
		}
	}
	cout << check << endl;
	return 0;
}
