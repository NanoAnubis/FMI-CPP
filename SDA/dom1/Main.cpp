#include<iostream>
#include<string>
#include<vector>
using namespace std;


//int main() {
//	string input;
//	cin >> input;
//	char symbol;
//	cin >> symbol;
//	vector<bool> location;
//	vector<int> output;
//	for (size_t i = 0; i < input.size(); i++) {
//		if (input[i] == symbol) {
//			location.push_back(1);
//		}
//		else {
//			location.push_back(0);
//		}
//	}
//	for (size_t i = 0; i < input.size(); i++) {
//		if (location[i] == 1) {
//			output.push_back(0);
//			continue;
//		}
//		int l = 0;
//		int r = 0;
//		size_t p = i;
//		while (location[p] != 1) {
//			if (p == (location.size() - 1)) {
//				r=0;
//				break;
//			}
//			p++;
//			r++;
//		}
//		p = i;
//		while (location[p] != 1) {
//			if (p == 0) {
//				l = 0;
//				break;
//			}
//			p--;
//			l++;
//		}
//		if (l == 0 && r != 0) {
//			output.push_back(r);
//			continue;
//		}
//		if (r == 0 && l != 0) {
//			output.push_back(l);
//			continue;
//		}
//		if (l > r) {
//			output.push_back(r);
//		}
//		else {
//			output.push_back(l);
//		}
//	}
//	for (size_t i = 0; i < output.size(); i++) {
//		cout << output[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

//int main() {
//	unsigned n = 0;
//	cin >> n;
//	if (n == 0)return 0;
//	vector<bool> available;
//	available.resize(n+1);
//	for (size_t i = 0; i < n; i++) {
//		int input;
//		cin >> input;
//		if (input <= 0) {
//			continue;
//		}
//		if (input > n) {
//			available.resize(input+1);
//		}
//		available[input - 1] = 1;
//	}
//	for (size_t i = 0; i <= n; i++) {
//		if (available[i] == 0) {
//			cout << i + 1;
//			break;
//		}
//	}
//
//
//	return 0;
//}

//int main() {
//
//	string input;
//	cin >> input;
//	if (input.size() > 100) return 0;
//	unsigned n;
//	cin >> n;
//	if (n > 1000000000) return 0;
//	char symbol;
//	cin >> symbol;
//	if (symbol < 'A' || (symbol > 'Z' && symbol < 'a') || symbol > 'z') {
//		return 0;
//	}
//	int counter = 0;
//	for (size_t i = 0; i < input.size(); i++) {
//		if (input[i] == symbol) {
//			counter++;
//		}
//	}
//	counter *= n / input.size();
//	for (size_t i = 0; i < (n % input.size()); i++) {
//		if (input[i] == symbol) {
//			counter++;
//		}
//	}
//
//	cout << counter << endl;
//	return 0;
//}

