#include<iostream>
#include<vector>
using namespace std;





int main() {

	long long n;
	cin >> n;
	long counter = 0;

	vector<long long> cubes;
	long long i = 1;

	while ((i * i * i) <= n) {
		cubes.push_back(i * i * i);
		i++;
	}

	i = cubes.size() - 1;

	while (n != 0 || i<0) {
		if (n==cubes[i]) {
			counter++;
			break;
		}
		else if (n>cubes[i]) {
			n -= cubes[i];
			counter++;
		}
		else {
			i--;
		}
	}

	cout << counter;

	return 0;
}