#include<iostream>
#include<vector>
using namespace std;

vector<int> output;

void make_masks(int input) {

	if (input >= (int)output.size()) {
		output.resize(input + 1);
	}

	if (output[input] != 0) {
		return;
	}

	for (int i = 0; i <= input; i++) {
		int tmp = input & i;
		output[tmp] = 1;
	}
}


int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		make_masks(tmp);
	}


	int count = 0;

	for (int i = 0; i < (int)output.size(); i++) {
		if (output[i] == 1) {
			count++;
		}
	}

	cout << count;

	return 0;
}