#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int CounterP(vector<int>, int, int, int, int);
	int SizeV = 0, number = 0;
	vector<int>seq;
	do {
		cin >> SizeV;
	} while (SizeV < 3 || SizeV>1000);

	for (int i = 0; i < SizeV; i++) {
		cin >> number;
		seq.push_back(number);
	}
	int i = 0, x = 2, s = 0;
	int count = 0;
	count = CounterP(seq, i, SizeV, s, x);
	if (count == 0) {
		cout << "-1";
	}
	else {
		cout << count;
	}
	return 0;
}

int CounterP(vector<int>seq, int i, int size, int s, int x) {
	for (int k = 1; k < size; k++) {    //proverqva dali vsichki elementi sa ravni
		if (seq[i] != seq[k]) break;
		s = s + (k - 1);
		if (k == size - 1) {
			return s;
		}
	}
	s = 0;
	while (i < size - 2) {
		if (seq[i] == seq[x]) {
			for (int p = 1; p <= ((x - i) / 2); p++) {
				if (seq[i + p] == seq[x - p]) {
					if (i + p == x - p || i + p == (x - p) - 1) {
						s = s + p;
						i = i + p;
						x = i + 1;
						break;
					}
				}
				else break;
			}
		}
		x++;
		if (x >= size) {
			i++;
			x = i + 1;
		}

	}
	return s;
}