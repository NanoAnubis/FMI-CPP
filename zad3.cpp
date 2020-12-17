
#include<iostream>
#include<vector>
using namespace std;

int main() {
	bool isMagic(vector<vector<double>>&square, const int size);
	int N = 0;
	vector<vector<double>>Msquare;
	do {
		cin >> N;
	} while (N <= 1 || N >= 1000);
	for (int i = 0; i < N; i++) {
		vector<double>row;
		for (int p = 0; p < N; p++) {
			double number = 0;
			do {
				cin >> number;
			} while (number < 0 || number > 100);
			row.push_back(number);
		}
		Msquare.push_back(row);
	}
	if (isMagic(Msquare, N) == 1) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	return 0;
}

bool isMagic(vector<vector<double>>& square, const int size) {
	void TotalReset(vector<double>&, double&);
	vector<double>Totals; //saves totals of rows, columns and diagonals
	double total = 0;
	for (int i = 0; i < size; i++) {
		total += square[i][i];
	}
	TotalReset(Totals, total);
	for (int i = 0, p = size - 1; i < size; i++, p--) {
		total += square[i][p];
	}
	TotalReset(Totals, total);
	for (int i = 0; i < size; i++) {
		for (int p = 0; p < size; p++) {
			total += square[i][p];
		}
		TotalReset(Totals, total);
	}
	for (int p = 0; p < size; p++) {
		for (int i = 0; i < size; i++) {
			total += square[i][p];
		}
		TotalReset(Totals, total);
	}
	total = Totals[0];
	for (int i = 0; i < Totals.size(); i++) {
		if (Totals[i] > total) {
			if (Totals[i] - total > 0.00000000001)return false;//dostatychno malko chislo za proverka na ravenstvo
		}
		else if (Totals[i] < total) {
			if (total - Totals[i] > 0.00000000001)return false;
		}
	}
	return true;
}

void TotalReset(vector<double>& Totals, double& total) {
	Totals.push_back(total);
	total = 0;
	return;
}