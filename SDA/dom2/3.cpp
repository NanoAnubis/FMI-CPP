#include<iostream>
#include<vector>
#include<string>
using namespace std;

int toi(char c) {

	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	if (c >= 'a' && c <= 'z') {
		return c - 'a' + 10;
	}
	if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 36;
	}

	return -1;
}


char tos(int n) {

	if (n >= 0 && n <= 9) {
		return n + '0';
	}
	if (n >= 10 && n <= 35) {
		return n - 10 + 'a';
	}
	if (n >= 36 && n <= 61) {
		return n - 36 + 'A';
	}

	return '!';
}

int main() {

	long long n;
	cin >> n;
	string input;
	cin >> input;
	vector<long long> counts;
	counts.resize(62);

	for (long long i = 0; i < n; i++) {
		counts[toi(input[i])]++;
	}
	
	for (size_t i = 0; i < counts.size(); i++) {
		while (counts[i] != 0) {
			cout << tos(i);
			counts[i]--;
		}
	}

	return 0;
}