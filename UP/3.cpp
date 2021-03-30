#include<iostream>
using namespace std;

int size(int n) {
	int s=1;
	while (n / 10 != 0) {
		s++;
		n /= 10;
	}
	return s;
}

int main() {
	int number=0;
	int arr[10] = {};
	//int out[10] = {};
	cin >> number;
    int s = size(number);
	for (int i = 0; i < s; i++) {
		for (int k = 0; k < 10; k++) {
			if (number % 10 == k) {
				number /= 10;
				arr[k]++;
				break;
			}
		}
	}
	int o = 0;
	cout << "[";
	for (int i = 1; i < 10; i++) {
		if (o < arr[i]) {
			o = i;
		}
	}
	for (int i = 1; i < 10; i++) {
		if (o == arr[i]) {
			cout << i <<",";
		}
	}
	cout<< "-1]" << endl;
	return 0;
}