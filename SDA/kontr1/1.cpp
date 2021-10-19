#include<iostream>
#include<vector>
using namespace std;

int main() {

	long n;
	cin >> n;
	vector<bool> counter;
	for (long i = 0; i < n; i++) {
		long tmp;
		cin >> tmp;
		if (tmp >= counter.size()) counter.resize(tmp+1);
		counter[tmp]=true;
	}

	for (long i = 0; i < counter.size(); i++) {
		if (counter[i] == true) {
			cout << i << " ";
		}
	}


	return 0;
}