#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <math.h>
using namespace std;


long answer(const long s, const long p, const vector<long>& arr) {

	long counter = 0;
	long index = 0;
	long sum = 0;

	if (p < arr[0]) {
		return 0;
	}

	if (p > arr[arr.size() - 1]) {
		index = arr.size() - 1;
	}
	else {
		long jump = sqrtl((long)arr.size());

		long i = 0;
		while (i < (long)arr.size()) {
			if (arr[i] == p) {
				while (i + 1 < (long)arr.size() && arr[i + 1] == p) {
					i++;
				}
				index = i;
				break;
			}

			if (arr[i] > p) {
				break;
			}

			i = min(i + jump, (long)arr.size());
		}

		if (index == 0) {
			for (long j = 0; j < jump; j++) {
				if (arr[i - j] == p) {
					index = i - j;
					break;
				}
				else if (arr[i - j] > p) {
					index = i - j - 1;
				}
			}
		}

	}

	while (index >= 0) {
		sum += arr[index];
		if (sum <= s) {
			counter++;
			index--;
		}
		else break;
	}

	return counter;
}


int main() {

	string output;
	long n, q;
	cin >> n >> q;
	vector<long> numbers;

	for (long i = 1; i <= n; i++) {
		long tmp;
		cin >> tmp;
		numbers.push_back(tmp);
	}

	sort(numbers.begin(), numbers.end());

	for (long i = 1; i <= q; i++) {
		long tmp1,tmp2;
		cin >> tmp1 >> tmp2;
		output += to_string(answer(tmp1, tmp2, numbers));
		output += '\n';
	}

	cout << output;

	return 0;
}
